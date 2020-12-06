#include<bits/stdc++.h>

 
using namespace std;
const ll l = 1e9+7;


struct Node {
    int val;
    Node *left, *right;
};
 

unordered_map<Node*, Node*> um;
 

void storeParent(Node* root)
{
 
    
    queue<Node*> q;
    q.push(root);
     
   
    while (!q.empty()) {
        Node* p = q.front();
        q.pop();
         
        
        if (p == root) {
            um[p] = NULL;
        }
         
        
        if (p->left) {
            um[p->left] = p;
            q.push(p->left);
        }
        if (p->right) {
            um[p->right] = p;
            q.push(p->right);
        }
    }
}
 

void nodeAtDistK(Node* root, 
           Node* target, int k)
{
    
    unordered_set<Node*> s;
    int dist = 0;
    queue<Node*> q;
    q.push(target);
    s.insert(target);
     
    
    while (!q.empty()) {
 
        
        if (dist == k) {
            while (!q.empty()) {
                cout << q.front()->val << " ";
                q.pop();
            }
        }
 
         
        int size = q.size();
        for (int i = 0; i < size; i++) {
            Node* p = q.front();
            q.pop();
 
             
            if (p->left && 
                s.find(p->left) == s.end()) {
                q.push(p->left);
                s.insert(p->left);
            }
 
             
            if (p->right && 
                s.find(p->right) == s.end()) {
                q.push(p->right);
                s.insert(p->right);
            }
 
            
            if (um[p] && s.find(um[p]) == s.end()) {
                q.push(um[p]);
                s.insert(um[p]);
            }
        }
        dist++;
    }
}
int main()
{
     

    
      Node* root = newnode(20);
      root->left = newnode(8);
      root->right = newnode(22);
      root->right->left = newnode(5);
      root->right->right = newnode(8);
      root->left->left = newnode(4);
      root->left->left->left = newnode(25);
      root->left->right = newnode(12);
      root->left->right->left = 
                     newnode(10);
      root->left->right->left->left = 
                     newnode(15);
      root->left->right->left->right = 
                     newnode(18);
      root->left->right->left->right->right = 
                     newnode(23);
      root->left->right->right = 
                     newnode(14);
      Node* target = root->left->right;
      storeParent(root);
      nodeAtDistK(root, target, 3);
    return 0;
    
 

} 