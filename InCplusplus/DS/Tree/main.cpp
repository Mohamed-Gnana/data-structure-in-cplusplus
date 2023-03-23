#include <iostream>

using namespace std;

template<class t>
class binarytree {

private:
    struct Node {
        t item ;
        Node* left ;
        Node* right ;
        Node* parent ;
    };
    Node* root ;

    void inorder (Node* ptr) {
        if (ptr != NULL) {
            inorder(ptr->left);
            cout<<ptr->item;
            inorder(ptr->right);
        }
    }

    void preorder (Node* ptr) {
        if (ptr != NULL) {
            cout<<ptr->item;
            preorder(ptr->left);
            preorder(ptr->right);
        }
    }

    void postorder (Node* ptr) {
        if (ptr != NULL) {
            postorder(ptr->left);
            postorder(ptr->right);
            cout<<ptr->item;
        }
    }

    int maximum(int x, int y) {
        if (x > y)
            return x;
        else
            return y ;
    }

    int height (Node* ptr) {
        if (ptr == NULL)
            return 0 ;
        else
            return 1 + maximum(height(ptr->left),height(ptr->right));
    }

    int Nodes (Node* ptr) {
        if (ptr == NULL)
            return 0 ;
        else
            return 1 + Nodes(ptr->left) + Nodes(ptr->right);
    }

    int leaves (Node* ptr) {
        if (ptr == NULL)
            return 0 ;
        else if ((ptr->left == NULL )&& (ptr->right == NULL))
            return 1;
        else
            return leaves(ptr->left) + leaves(ptr->right);
    }

    bool searchrec (Node* ptr , t item) {
        if (ptr == NULL)
            return false ;
        else if (ptr->item == item)
            return true ;
        else if (ptr->item > item)
            return searchrec(ptr->left,item);
        else
            return searchrec(ptr->right , item);
    }

    void treedelete (Node* &ptr) {
        Node* temp ;
        if ((ptr->left == NULL) && (ptr->right == NULL)){
            delete ptr ;
            ptr = NULL ;
        }
        else if (ptr->left == NULL){
            temp = ptr ;
            ptr = ptr->right ;
            delete temp ;
        }
        else if (ptr->right == NULL){
            temp = ptr ;
            ptr = ptr->left ;
            delete temp ;
        }
        else {
            Node* cur = ptr->left ;
            Node* prv = NULL ;
            while (cur->right != NULL){
                prv = cur ;
                cur = cur->right;
            }
            ptr->item = cur->item;
            if (prv == NULL)
                ptr->left = cur->left ;
            else
                prv->right = cur->left;
            delete cur ;
        }
    }

public:
    binarytree () {
        root = NULL;
    }

    bool isempty () {
        return root == NULL ;
    }

    void inordertraverse () {
        inorder(root);
    }

    void preordertraverse () {
        preorder(root);
    }

    void postordertraverse () {
        postorder(root);
    }

    int treeheight () {
        return height(root);
    }

    int treenodes () {
        return Nodes(root);
    }
    int treeleaves () {
        return leaves(root);
    }

    bool treesearch (t element) {
        Node* cur = root ;
        while (cur != NULL) {
            if (cur->item == element)
                return true ;
            else if (cur->item > element)
                cur = cur->left ;
            else
                cur = cur->right ;
        }
        return false ;
    }

    bool treesearchrec (t element) {
        return searchrec(root , element);
    }

    void treeinsert (t element) {
        Node*newitem = new Node ;
        newitem->item = element ;
        newitem->left = NULL ;
        newitem->right = NULL ;
        newitem->parent = NULL;
        Node* cur ;
        Node* prv;
        if (root == NULL)
            root = newitem ;
        else {
            cur = root ;
            while (cur != NULL){
                prv = cur ;
                if(cur->item == element){
                    cout << "Duplicates are not allowed.";
                    return;
                }
                else if (cur->item > element)
                    cur = cur->left ;
                else
                    cur = cur->right;
            }
            if (prv->item > element)
                prv->left = newitem ;
            else
                prv->right = newitem;
            newitem->parent = prv;
        }
    }

    void treeremove (t element) {
        if (isempty())
            cout << "the tree is empty.";
        else {
            if (root->item == element)
                treedelete(root);
            else {
                Node* prv = root ;
                Node* cur ;
                if(root->item > element)
                    cur = root->left;
                else
                    cur = root->right ;

                while(cur != NULL) {
                    if (cur->item == element)
                        break ;
                    else {
                        prv = cur ;
                        if (cur->item > element)
                            cur = cur->left;
                        else
                            cur = cur->right;
                    }
                }
                if (cur == NULL)
                    cout << "The item is not found.";
                else if (prv->item > element)
                    treedelete(prv->left);
                else
                    treedelete(prv->right);
            }
        }
    }

};

int main()
{
    binarytree<int> b ;
    b.treeinsert(10);
    b.treeinsert(21);
    b.treeinsert(5);
    b.treeinsert(20);
    b.treeinsert(7);
    b.treeinsert(25);
    b.treeinsert(1);
    b.treeremove(30);
    b.treeremove(20);
    b.treeremove(7);
    b.inordertraverse();
    return 0;
}
