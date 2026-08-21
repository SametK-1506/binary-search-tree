#include <iostream>
using namespace std;

class Node {
public:
    Node* left;
    Node* right;
    int deger;
    
    Node(int val) {
        deger = val;
        left = NULL;  
        right = NULL;
    }
}; 

class binarySearchTree {
public:
    Node* root;
    binarySearchTree(){
        root=NULL;
    }
    ~binarySearchTree(){
        deleteAllNodes();
    }
     void deleteAllNodes(Node* node){
        if(node==NULL) return;
        if(node->left!=NULL){
             deleteAllNodes(node->left);

        }
        if(node->right!=NULL){
             deleteAllNodes(node->right);

        }
        delete node;
     }
    bool insertNode(int deger){
        Node* node=new Node(deger);
        if(root==NULL){
        root=node;
        return true;
    }
        
        Node* tmp=root;
        while (true)
        {
           
            if(tmp->deger==node->deger){
                cout<<"this node is allready exsist\n ";
                delete node; // tepede en başta oluşan node u sildik 
                return false;
            }
            if(node->deger < tmp->deger){
                if(tmp->left==NULL){
                    tmp->left=node;
                    return true;
                }
                tmp=tmp->left;

            }
            else{
                if(tmp->right==NULL){
                    tmp->right=node;
                    return true;
                }
                tmp=tmp->right;
                
            }
        }
        
    }
    void DFSPreOrderSearchPrintAll(Node* node){
        cout<<node->deger<<", ";
        if(node->left!=NULL){
            DFSPreOrderSearchPrintAll(node->left);
        }                                               // buradakiş reculsive çagırma algoritmasıyla öncew sola g
                                                             //           node de boşluk varsa reculsive kapatıp bir üsse geçiyor devam ediyor 
        if(node->right!=NULL){
            DFSPreOrderSearchPrintAll(node-right);
        }

    }
    Node* DFSPreOrderSearchAra(Node* node,int arananDeger){
        if(node==NULL || node->deger== arananDeger){
            return node;
        }
        if(arananDeger<node->deger){
            DFSPreOrderSearchAra(root->left,arananDeger);
        }
        else{
             DFSPreOrderSearchAra(root->right,arananDeger);
        }

    }
  

}; 

int main() {
  binarySearchTree* bst=new binarySearchTree();
  bst->insertNode(52);
  bst->insertNode(27);
  bst->insertNode(15);
  bst->insertNode(30);
  bst->insertNode(78);
  bst->insertNode(65);
  bst->insertNode(53);
  bst->insertNode(76);
  cout<<bst->root->deger<<endl;;

  cout<<"last node is "<<bst->root->right->left->right->deger<<endl;
  delete bst;
    return 0;
};
