#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// Node structure for Huffman Tree
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char ch, int freq) {
        this->ch = ch;
        this->freq = freq;
        left = right = nullptr;
    }
};

// Compare function for priority queue (min-heap)
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq; // Min-heap
    }
};

// Build Huffman Tree
Node* buildHuffmanTree(unordered_map<char, int>& freqMap) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (auto it : freqMap) {
        pq.push(new Node(it.first, it.second));
    }

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* merged = new Node('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        pq.push(merged);
    }

    return pq.top(); // Root of Huffman Tree
}

// Generate Huffman Codes
void generateCodes(Node* root, string code, unordered_map<char, string>& huffmanCode) {
    if (!root)
        return;

    if (root->ch != '\0') {
        huffmanCode[root->ch] = code;
    }

    generateCodes(root->left, code + "0", huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode);
}

// Encode the input string
string encode(string text, unordered_map<char, string>& huffmanCode) {
    string encoded = "";
    for (char ch : text) {
        encoded += huffmanCode[ch];
    }
    return encoded;
}

// Decode the encoded string
string decode(string encodedStr, Node* root) {
    string decoded = "";
    Node* curr = root;
    for (char bit : encodedStr) {
        if (bit == '0')
            curr = curr->left;
        else
            curr = curr->right;

        if (!curr->left && !curr->right) {
            decoded += curr->ch;
            curr = root;
        }
    }
    return decoded;
}

int main() {
    string text = "huffman";

    // Step 1: Count frequency of each character
    unordered_map<char, int> freqMap;
    for (char ch : text) {
        freqMap[ch]++;
    }

    // Step 2: Build Huffman Tree
    Node* root = buildHuffmanTree(freqMap);

    // Step 3: Generate Huffman Codes
    unordered_map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);

    cout << "Huffman Codes:\n";
    for (auto it : huffmanCode) {
        cout << it.first << ": " << it.second << endl;
    }

    // Step 4: Encode
    string encodedStr = encode(text, huffmanCode);
    cout << "\nEncoded String: " << encodedStr << endl;

    // Step 5: Decode
    string decodedStr = decode(encodedStr, root);
    cout << "\nDecoded String: " << decodedStr << endl;

    return 0;
}
