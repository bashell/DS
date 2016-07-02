#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using std::cin; using std::cout; using std::endl;
using std::vector;
using std::stack;
using std::queue;

class TreeNode {
 public:
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  ~TreeNode() {}
 public:
  int val;
  TreeNode *left;
  TreeNode *right;
};

vector<int> preOrderTraversal(TreeNode *root) {
  vector<int> res;
  if(NULL == root) return res;
  stack<TreeNode*> stk;
  stk.push(root);
  while(!stk.empty()) {
    TreeNode *tmp = stk.top();
    stk.pop();
    res.push_back(tmp->val);
    if(tmp->right)
      stk.push(tmp->right);
    if(tmp->left)
      stk.push(tmp->left);
  }
  return res;
}

vector<int> postOrderTraversal(TreeNode *root) {
  vector<int> res;
  if(NULL == root) return res;
  stack<TreeNode*> stk;
  stk.push(root);
  while(!stk.empty()) {
    TreeNode *tmp = stk.top();
    stk.pop();
    res.push_back(tmp->val);
    if(tmp->left)
      stk.push(tmp->left);
    if(tmp->right)
      stk.push(tmp->right);
  }
  return vector<int>(res.crbegin(), res.crend());
}

vector<int> inOrderTraversal(TreeNode *root) {
  vector<int> res;
  if(NULL == root) return res;
  stack<TreeNode*> stk;
  TreeNode *pCur = root;
  while(pCur || !stk.empty()) {
    if(pCur) {
      stk.push(pCur);
      pCur = pCur->left;
    } else {
      TreeNode *tmp = stk.top();
      stk.pop();
      res.push_back(tmp->val);
      pCur = tmp->right;
    }
  }
  return res;
}

vector<int> levelOrderTraversal(TreeNode *root) {
    vector<int> res;
    if(NULL == root) return res;
    queue<TreeNode*> q;
    q.push(root);
    while(q.size() > 0) {
        TreeNode *tmp = q.front();
        q.pop();
        res.push_back(tmp->val);
        if(tmp->left)
            q.push(tmp->left);
        if(tmp->right)
            q.push(tmp->right);
    }
    return res;
}

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);

  vector<int> preOrder = preOrderTraversal(root);
  vector<int> inOrder = inOrderTraversal(root);
  vector<int> postOrder = postOrderTraversal(root);
  vector<int> levelOrder = levelOrderTraversal(root);

  cout << "PreOrder: ";
  for(auto i : preOrder)
      cout << i << " ";
  cout << endl;

  cout << "InOrder: ";
  for(auto i : inOrder)
      cout << i << " ";
  cout << endl;
  
  cout << "PostOrder: ";
  for(auto i : postOrder)
      cout << i << " ";
  cout << endl;

  cout << "LevelOrder: ";
  for(auto i : levelOrder)
      cout << i << " ";
  cout << endl;

  return 0;
}
