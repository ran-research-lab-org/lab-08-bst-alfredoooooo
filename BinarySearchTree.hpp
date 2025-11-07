#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <string>
#include <sstream>
#include <queue>
using namespace std;

template <typename Comparable>
class BinarySearchTree {
private:
    struct TreeNode {
        Comparable element;
        TreeNode *left;
        TreeNode *right;

        TreeNode(const Comparable &e, TreeNode *lt, TreeNode *rt)
            : element{e}, left{lt}, right{rt} {}
    };

    TreeNode *root;

    void insert(const Comparable &x, TreeNode *&t) {
        if (t == nullptr)
            t = new TreeNode{x, nullptr, nullptr};
        else if (x < t->element)
            insert(x, t->left);
        else if (t->element < x)
            insert(x, t->right);
    }

    void remove(const Comparable &x, TreeNode *&t) {
        if (t == nullptr)
            return;
        if (x < t->element)
            remove(x, t->left);
        else if (t->element < x)
            remove(x, t->right);
        else if (t->left != nullptr && t->right != nullptr) {
            t->element = findMin(t->right)->element;
            remove(t->element, t->right);
        } else {
            TreeNode *oldNode = t;
            t = (t->left != nullptr) ? t->left : t->right;
            delete oldNode;
        }
    }

    TreeNode *findMin(TreeNode *t) const {
        if (t == nullptr)
            return nullptr;
        if (t->left == nullptr)
            return t;
        return findMin(t->left);
    }

    bool contains(const Comparable &x, TreeNode *t) const {
        if (t == nullptr)
            return false;
        else if (x < t->element)
            return contains(x, t->left);
        else if (t->element < x)
            return contains(x, t->right);
        else
            return true;
    }

    void toInorderStr(TreeNode *t, ostringstream &out) const {
        if (t != nullptr) {
            toInorderStr(t->left, out);
            if (out.str().length() > 0)
                out << " ";
            out << t->element;
            toInorderStr(t->right, out);
        }
    }

    void makeEmpty(TreeNode *&t) {
        if (t != nullptr) {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        t = nullptr;
    }

public:
    BinarySearchTree() : root{nullptr} {}

    ~BinarySearchTree() {
        makeEmpty();
    }

    bool contains(const Comparable &x) const {
        return contains(x, root);
    }

    void insert(const Comparable &x) {
        insert(x, root);
    }

    void remove(const Comparable &x) {
        remove(x, root);
    }

    void makeEmpty() {
        makeEmpty(root);
    }

    string toInorderStr() const {
        ostringstream out;
        toInorderStr(root, out);
        return out.str();
    }

    string BFT() const {
        if (root == nullptr) return "[]";
        
        ostringstream result;
        result << "[";
        
        queue<TreeNode*> q;
        q.push(root);
        
        bool firstLevel = true;
        
        while (!q.empty()) {
            int levelSize = q.size();
            
            if (!firstLevel) result << ",";
            firstLevel = false;
            
            result << "[";
            
            for (int i = 0; i < levelSize; i++) {
                TreeNode* current = q.front();
                q.pop();
                
                if (i > 0) result << ",";
                result << current->element;
                
                if (current->left != nullptr) q.push(current->left);
                if (current->right != nullptr) q.push(current->right);
            }
            
            result << "]";
        }
        
        result << "]";
        return result.str();
    }
};

#endif