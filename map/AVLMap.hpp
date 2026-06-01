#pragma once

#include <string>
#include <vector>

class Node
{
    private:
    std::string key;
    std::string value;
    Node* left;
    Node* right;
    unsigned int h;
    int count;
    Node(const std::string& key,const std::string& value);
    ~Node() = default;
    friend class AVLTree;
};

class AVLTree
{
    private:
    Node* root;
    unsigned int height(Node *p);
    int bfactor(Node *p);
    void fixheight(Node *p);
    bool kmp(const std::string& value,const std::string& word)const;
    Node* RotateRight(Node *p);
    Node* RotateLeft(Node *p);
    Node* balance(Node *p);
    Node* insert(Node *p,const std::string& key,const std::string& value);
    Node* find(Node *p,const std::string& key);
    Node* MostPopular(Node *p,Node *best)const;
    Node* findmin(Node *p);
    Node* removemin(Node* p);
    Node* remove(Node *p,const std::string& key);
    void clear(Node *p);
    void print(Node *p,int& number)const;
    void find_by_word(Node *p,const std::string& word,std::vector<std::pair<std::string,std::string>>& found)const;

    public:
    bool remove(const std::string& key);
    bool get(const std::string& key,std::string& value);
    bool getMostPopular(std::string& key,std::string& value,int& count)const;
    std::string& operator[](const std::string& key);
    std::vector<std::pair<std::string, std::string>> find_by_word(const std::string& word) const;
    void print()const;
    void increment(const std::string& key);
    AVLTree(const AVLTree&) = delete;
    AVLTree& operator=(const AVLTree&) = delete;
    AVLTree();
    ~AVLTree();
};