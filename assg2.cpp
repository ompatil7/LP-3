#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// Comparator for priority queue
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Print Huffman codes
void printCodes(Node* root, string code = "") {
    if (!root) return;
    if (root->ch != '#') cout << root->ch << ": " << code << endl;
    printCodes(root->left, code + "0"); 
    printCodes(root->right, code + "1");
}

// Huffman Encoding function
void huffmanEncoding(const unordered_map<char, int>& freq) {
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto pair : freq) pq.push(new Node(pair.first, pair.second));

    while (pq.size() > 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();
        Node *parent = new Node('#', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }
    
    printCodes(pq.top());
}

int main() {
    unordered_map<char, int> freq = {{'a', 5}, {'b', 9}, {'c', 12}, {'d', 13}, {'e', 16}, {'f', 45}};
    huffmanEncoding(freq);
    return 0;

/*
    unordered_map<char, int> freq; // Map to store character frequencies
    int n;

    cout << "Enter the number of characters: ";
    cin >> n;

    cout << "Enter each character followed by its frequency:\n";
    for (int i = 0; i < n; i++) {
        char ch;
        int frequency;
        
        cout << "Character " << i + 1 << ": ";
        cin >> ch;
        cout << "Frequency of " << ch << ": ";
        cin >> frequency;
        
        freq[ch] = frequency; // Store character and its frequency
    }*/
}