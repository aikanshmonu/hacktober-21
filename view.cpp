#include <bits/stdc++.h>
using namespace std;

int N;
struct node{
    int key;
    vector<node *> children;
};

node * newNode(int key){
    node * temp = new node;
    temp->key = key;
    return temp;
}

// Constructs tree from ancestor matrix
// node* ancestorTree(int mat[N][N])
// {
//     // Binary array to determine whether
//     // parent is set for node i or not
//     int parent[N] = {0};
   
//     // Root will store the root of the constructed tree
//     node* root = NULL;
   
//     // Create a multimap, sum is used as key and row
//     // numbers are used as values
//     multimap<int, int> mm;
   
//     for (int i = 0; i < N; i++)
//     {
//         int sum = 0; // Initialize sum of this row
//         for (int j = 0; j < N; j++)
//             sum += mat[i][j];
   
//         // insert(sum, i) pairs into the multimap
//         mm.insert(pair<int, int>(sum, i));
//     }
   
//     // node[i] will store node for i in constructed tree
//     node* node[N];
   
//     // Traverse all entries of multimap.  Note that values
//     // are accessed in increasing order of sum
//     for (auto it = mm.begin(); it != mm.end(); ++it)
//     {
//       // create a new node for every value
//       node[it->second] = newNode(it->second);
   
//       // To store last processed node. This node will be
//       // root after loop terminates
//       root = node[it->second];
   
//       // if non-leaf node
//       if (it->first != 0)
//       {
//         // traverse row 'it->second' in the matrix
//         for (int i = 0; i < N; i++)
//         {
//            // if parent is not set and ancestor exits
//            if (!parent[i] && mat[it->second][i])
//            {
//              // check for unoccupied left/right node
//              // and set parent of node i

//             //  if (!node[it->second]->left)
//             //    node[it->second]->left = node[i];
//             //  else
//             //    node[it->second]->right = node[i];

//                node[it->second]->children.push_back(node[i]);
   
//              parent[i] = 1;
//            }
//         }
//       }
//     }
//     return root;
// }

/* Compute the "height" of a tree -- the number of
    nodes along the longest path from the root node
    down to the farthest leaf node.*/
int height(node* node)
{
    if (node == NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        // int lheight = height(node->left);
        // int rheight = height(node->right);
        int heightArray[node->children.size()];
        
        for(int i = 0; i < node->children.size(); i++){
            heightArray[i] = height(node->children.at(i));
        }
        /* use the larger one */
        // if (lheight > rheight)
        // {
        //     return(lheight + 1);
        // }
        // else {
        //   return(rheight + 1);
        // }
        int* maxElement;
        maxElement = max_element(heightArray, heightArray + node->children.size());
        return *maxElement;   
    }
}

/* Print nodes at a current level */
void printCurrentLevel(node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->key << " ";
    else if (level > 1)
    {
        // printCurrentLevel(root->left, level-1);
        // printCurrentLevel(root->right, level-1);
        for(auto &it:root->children){
            printCurrentLevel(it, level- 1);
        }
    }
}

/* Function to print level
order traversal a tree*/
void printLevelOrder(node* root)
{
    // int h = height(root);
    int h = 3;
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}

int main(){
    int numOfTestCases;
    cin>>numOfTestCases;

    while(numOfTestCases-- != 0){
        int numOfNodes;
        cin>>numOfNodes;

        int mat[numOfNodes][numOfNodes] = {};
        N = numOfNodes;
        for(int i = 0; i < numOfNodes - 1; i++){
            int u,v;
            cin>>u>>v;
            mat[u][v] = 1;
        }

        for(int i = 0; i < numOfNodes; i++){
            for(int k = 0; k < numOfNodes; k++){
                cout<<mat[i][k]<<" ";
            }
            cout<<"\n";
        }

        // Binary array to determine whether
    // parent is set for node i or not
    int parent[N] = {0};
   
    // Root will store the root of the constructed tree
    node* root = NULL;
   
    // Create a multimap, sum is used as key and row
    // numbers are used as values
    multimap<int, int> mm;
   
    for (int i = 0; i < N; i++)
    {
        int sum = 0; // Initialize sum of this row
        for (int j = 0; j < N; j++)
            sum += mat[i][j];
   
        // insert(sum, i) pairs into the multimap
        mm.insert(pair<int, int>(sum, i));
    }
   
    // node[i] will store node for i in constructed tree
    node* node[N];
   
    // Traverse all entries of multimap.  Note that values
    // are accessed in increasing order of sum
    for (auto it = mm.begin(); it != mm.end(); ++it)
    {
      // create a new node for every value
      node[it->second] = newNode(it->second);
   
      // To store last processed node. This node will be
      // root after loop terminates
      root = node[it->second];
   
      // if non-leaf node
      if (it->first != 0)
      {
        // traverse row 'it->second' in the matrix
        for (int i = 0; i < N; i++)
        {
           // if parent is not set and ancestor exits
           if (!parent[i] && mat[it->second][i])
           {
             // check for unoccupied left/right node
             // and set parent of node i

            //  if (!node[it->second]->left)
            //    node[it->second]->left = node[i];
            //  else
            //    node[it->second]->right = node[i];

               node[it->second]->children.push_back(node[i]);
   
             parent[i] = 1;
           }
        }
      }
    }

    printLevelOrder(root);
    }
    system("pause");
    return 0;
}
