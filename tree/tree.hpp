#include <string>
#include <vector>
#include <stack>

class Node
{
    public:

    std::string value;
    Node* left;
    Node* right;

    Node(const std::string& v);
};

class ExpressionTree
{
    private:
    void clearStack(std::stack<Node*>& stack);
    Node* root;
    void clear(Node* node);
    bool isOperator(const std::string& token)const;
    bool evaluate(Node* node,int& result)const;
    bool isNumber(const std::string& s)const;
    bool stringToInt(const std::string& s,int& v) const;
    public:
    ExpressionTree();
    ~ExpressionTree();

    bool build_expression_tree(const std::vector<std::string>& v);
    bool evaluate(int& result) const;



};