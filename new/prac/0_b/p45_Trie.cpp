#include <bits/stdc++.h>
using namespace std;

#define ALPHABET_SIZE 26

class TrieNode
{
public:
    TrieNode *children[ALPHABET_SIZE];
    bool isEndWord;

    TrieNode();
    void markAsLeaf();
    void unMarkAsLeaf();
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie();
    int getIndex(char t);
    void insertNode(string key);
    bool searchNode(string key);
    bool deleteNode(string key);
};

TrieNode::TrieNode()
{
    this->isEndWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        this->children[i] = NULL;
    }
}

// Function to mark the currentNode as Leaf
void TrieNode::markAsLeaf()
{
    this->isEndWord = true;
}

// Function to unMark the currentNode as Leaf
void TrieNode::unMarkAsLeaf()
{
    this->isEndWord = false;
}

Trie::Trie()
{
    root = new TrieNode();
}

// Function to get the index of a character 't'
int Trie::getIndex(char t)
{
    return t - 'a';
}

// Function to insert a key,value pair in the Trie
void Trie::insertNode(string key)
{
    // Empty string is not allowed
    if (key.empty())
        return;

    // using transform() function and ::tolower in STL to convert 'key' to lowercase
    transform(key.begin(), key.end(), key.begin(), ::tolower);
    TrieNode *currentNode = root;
    int index = 0;

    // Iterate the trie with the given character index,
    // If the index points to NULL
    // simply create a TrieNode and go down a level
    for (int level = 0; level < key.length(); level++)
    {
        index = getIndex(key[level]);

        if (currentNode->children[index] == NULL)
        {
            currentNode->children[index] = new TrieNode();
            cout << key[level] << " inserted" << endl;
        }
        currentNode = currentNode->children[index];
    }

    // Mark the end character as leaf node
    currentNode->markAsLeaf();
    cout << "'" << key << "' inserted" << endl;
}

// Function to search given key in Trie
bool Trie::searchNode(string key)
{
    return false;
}

// Function to delete given key from Trie
bool Trie::deleteNode(string key)
{
    return false;
}

int main()
{
    /*Trie *t = new Trie();
  cout << "Index to insert a = " << t->getIndex('a') << endl;
  cout << "Index to insert t = " << t->getIndex('t') << endl;*/

    string keys[9] = {"the", "a", "there", "answer", "any", "by", "bye", "their", "abc"};

    Trie *t = new Trie();

    cout << "Keys to insert:\n";
    for (int i = 0; i < 9; i++)
    {
        cout << keys[i] << ", ";
    }
    cout << endl;

    // Construct trie
    for (int i = 0; i < 9; i++)
    {
        t->insertNode(keys[i]);
        cout << "\"" << keys[i] << "\"" << "Inserted." << endl;
    }

    return 0;
}