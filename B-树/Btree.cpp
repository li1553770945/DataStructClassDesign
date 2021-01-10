

#include <iostream>
#include "Btree.h"
using namespace std;
BTree::BTree(int _t)
{
    root = NULL;
    t = _t;
}


// 初始化
BTreeNode::BTreeNode(int t1, bool leaf1) {
    t = t1;
    leaf = leaf1;

    keys = new int[2 * t - 1];
    C = new BTreeNode * [2 * t];

    n = 0;
    x = 0;
    y = 0;
    occupy_width = 0;

    setStyleSheet("border:2px solid red;");
}

// 查找在当前节点中的index
int BTreeNode::find_key(int k) {
    int index = 0;
    while (index < n && keys[index] < k)
        ++index;
    return index;
}

// Deletion operation
void BTreeNode::deletion(int k) {
    int index = find_key(k);

    if (index < n && keys[index] == k) {
        if (leaf)
            remove_from_leaf(index);
        else
            remove_from_non_leaf(index);
    }
    else {
        if (leaf) {
            cout << "The key " << k << " is does not exist in the tree\n";
            return;
        }

        bool flag = ((index == n) ? true : false);

        if (C[index]->n < t)
            fill(index);

        if (flag && index > n)
            C[index - 1]->deletion(k);
        else
            C[index]->deletion(k);
    }
    return;
}
BTreeNode* BTreeNode::search(int k) {
    setStyleSheet("border:2px solid red;");
    int i = 0;
    while (i < n && k > keys[i])
        i++;

    if (keys[i] == k)
        return this;

    if (leaf == true)
        return NULL;

    return C[i]->search(k);
}
// Remove from the leaf
void BTreeNode::remove_from_leaf(int index) {
    for (int i = index + 1; i < n; ++i)
        keys[i - 1] = keys[i];

    n--;

    return;
}

// Delete from non leaf BTree
void BTreeNode::remove_from_non_leaf(int index) {
    int k = keys[index];

    if (C[index]->n >= t) {
        int pred = getPredecessor(index);
        keys[index] = pred;
        C[index]->deletion(pred);
    }

    else if (C[index + 1]->n >= t) {
        int succ = getSuccessor(index);
        keys[index] = succ;
        C[index + 1]->deletion(succ);
    }

    else {
        merge(index);
        C[index]->deletion(k);
    }
    return;
}

int BTreeNode::getPredecessor(int index) {
    BTreeNode* cur = C[index];
    while (!cur->leaf)
        cur = cur->C[cur->n];

    return cur->keys[cur->n - 1];
}

int BTreeNode::getSuccessor(int index) {
    BTreeNode* cur = C[index + 1];
    while (!cur->leaf)
        cur = cur->C[0];

    return cur->keys[0];
}

void BTreeNode::fill(int index) {
    if (index != 0 && C[index - 1]->n >= t)
        borrowFromPrev(index);

    else if (index != n && C[index + 1]->n >= t)
        borrowFromNext(index);

    else {
        if (index != n)
            merge(index);
        else
            merge(index - 1);
    }
    return;
}

// Borrow from previous
void BTreeNode::borrowFromPrev(int index) {
    BTreeNode* child = C[index];
    BTreeNode* sibling = C[index - 1];

    for (int i = child->n - 1; i >= 0; --i)
        child->keys[i + 1] = child->keys[i];

    if (!child->leaf) {
        for (int i = child->n; i >= 0; --i)
            child->C[i + 1] = child->C[i];
    }

    child->keys[0] = keys[index - 1];

    if (!child->leaf)
        child->C[0] = sibling->C[sibling->n];

    keys[index - 1] = sibling->keys[sibling->n - 1];

    child->n += 1;
    sibling->n -= 1;

    return;
}

// Borrow from the next
void BTreeNode::borrowFromNext(int index) {
    BTreeNode* child = C[index];
    BTreeNode* sibling = C[index + 1];

    child->keys[(child->n)] = keys[index];

    if (!(child->leaf))
        child->C[(child->n) + 1] = sibling->C[0];

    keys[index] = sibling->keys[0];

    for (int i = 1; i < sibling->n; ++i)
        sibling->keys[i - 1] = sibling->keys[i];

    if (!sibling->leaf) {
        for (int i = 1; i <= sibling->n; ++i)
            sibling->C[i - 1] = sibling->C[i];
    }

    child->n += 1;
    sibling->n -= 1;

    return;
}

// Merge
void BTreeNode::merge(int index) {
    BTreeNode* child = C[index];
    BTreeNode* sibling = C[index + 1];

    child->keys[t - 1] = keys[index];

    for (int i = 0; i < sibling->n; ++i)
        child->keys[i + t] = sibling->keys[i];

    if (!child->leaf) {
        for (int i = 0; i <= sibling->n; ++i)
            child->C[i + t] = sibling->C[i];
    }

    for (int i = index + 1; i < n; ++i)
        keys[i - 1] = keys[i];

    for (int i = index + 2; i <= n; ++i)
        C[i - 1] = C[i];

    child->n += sibling->n + 1;
    n--;

    delete (sibling);
    return;
}

// Insertion operation
void BTree::insertion(int k) {
    if (root == NULL) {
        root = new BTreeNode(t, true);
        root->keys[0] = k;
        root->n = 1;
    }
    else {
        if (root->n == 2 * t - 1) {
            BTreeNode* s = new BTreeNode(t, false);

            s->C[0] = root;

            s->split_child(0, root);

            int i = 0;
            if (s->keys[0] < k)
                i++;
            s->C[i]->insert(k);

            root = s;
        }
        else
            root->insert(k);
    }
}

// Insertion non full
void BTreeNode::insert(int k) {
    int i = n - 1;

    if (leaf == true) {
        while (i >= 0 && keys[i] > k) {
            keys[i + 1] = keys[i];
            i--;
        }

        keys[i + 1] = k;
        n = n + 1;
    }
    else {
        while (i >= 0 && keys[i] > k)
            i--;

        if (C[i + 1]->n == 2 * t - 1) {
            split_child(i + 1, C[i + 1]);

            if (keys[i + 1] < k)
                i++;
        }
        C[i + 1]->insert(k);
    }
}

// 把它的儿子分裂
void BTreeNode::split_child(int i, BTreeNode* y) {
    BTreeNode* z = new BTreeNode(y->t, y->leaf);
    z->n = t - 1;

    for (int j = 0; j < t - 1; j++)
        z->keys[j] = y->keys[j + t];

    if (y->leaf == false) {
        for (int j = 0; j < t; j++)
            z->C[j] = y->C[j + t];
    }

    y->n = t - 1;

    for (int j = n; j >= i + 1; j--)
        C[j + 1] = C[j];

    C[i + 1] = z;

    for (int j = n - 1; j >= i; j--)
        keys[j + 1] = keys[j];

    keys[i] = y->keys[t - 1];

    n = n + 1;
}


void BTree::deletion(int k) {//从树种删除节点
    if (!root) {
        cout << "树为空\n";
        return;
    }

    root->deletion(k);

    if (root->n == 0) {
        BTreeNode* tmp = root;
        if (root->leaf)
            root = NULL;
        else
            root = root->C[0];

        delete tmp;
    }
    return;
}
BTreeNode* BTree::search(int k)
{
    if (root == NULL)
        return NULL;
    else
        return  root->search(k);
}