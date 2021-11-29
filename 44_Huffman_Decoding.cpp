/*
Function Description
Complete the function decode_huff in the editor below. It must return the decoded string.
decode_huff has the following parameters:
root: a reference to the root node of the Huffman tree
s: a Huffman encoded string

Input Format-
There is one line of input containing the plain string, s. Background code creates the Huffman tree then passes the head node and the encoded string to the function.

Output Format-
Output the decoded string on a single line.
*/

/* 
The structure of the node is

typedef struct node {

	int freq;
    char data;
    node * left;
    node * right;
    
} node;

*/


void decode_huff(node * root, string s) {
       string res="";
    node *c=root;
    
    for(int i=0;i<s.size();i++){
        
        if(s[i]=='0') c = c->left;
        else c = c->right;
        if(!c->left and !c->right){ //reached leaf node
            res=res + c->data;
            c=root;
        }
    }
    cout<<res<<endl;
}