#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

struct Node {
    int freq;
    char ch;
    Node *left, *right;
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator(Node* a, Node* b)
    {
        return a->freq > b->freq;
    }
};

void printCodes(Node* root, string code = "") {
    if(!root)
        return;
    
    if(root->ch != "#")
        cout << root->ch << " : " << code << endl;

    printCodes(root->left, code + '0');
    printCodes(root->right, code + '1');
}

void huffmanEncoding(unordered_map<char, int>& freq)
{
    priority_queue<Node *, vector<Node *>, Compare> pq;
    for(auto pair : freq)
        pq.push(new Node(pair, first, pair.second));

    while(pq.size() > 1) {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();

        Node *parent = new Node('#', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }

    printCodes(pq.top());
}
