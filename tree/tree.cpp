#include "tree.hpp"
#include <string>
#include <iostream>
#include <algorithm>

Node::Node(const std::string& v):value(v),
                                 left(nullptr),
                                 right(nullptr){};
         
ExpressionTree::ExpressionTree():root(nullptr){};

ExpressionTree::~ExpressionTree()
{
    clear(root);
}

void ExpressionTree::clear(Node* node)
{
    if(!node)return;


    clear(node->left);
    clear(node->right);
    delete node;
}

bool ExpressionTree::isOperator(const std::string& token)const
{
    return token == "+" ||
           token == "-" ||
           token == "*" ||
           token == "/" ;
}
bool ExpressionTree::isNumber(const std::string& token)const
{
    if(token.empty())return false;

    int start=0;
    
    if(token[0] == '-')
    {
        if(token.size()==1)return false;

        start = 1;
    }

    for(int i=start;i<token.size();i++)
    {
        if(token[i]<'0' || token[i]>'9')return false;
    }

    return true;
}

bool ExpressionTree::stringToInt(const std::string& token,int& v)const
{
    if(!isNumber(token)) return false;
    
    v = 0;
    int sign = 1;
    int start = 0;

    if(token[0]=='-')
    {
        sign = -1;
        start = 1;
    }
    
    for(int i=start;i<token.size();i++)
    {
        v = v*10 + (token[i]-'0');
    }

    v *=sign;
    return true;
}

bool ExpressionTree::evaluate(Node* node,int& result)const
{
    if(node==nullptr)
    {
        return false;
    }

    if(!isOperator(node->value))
    {
        return stringToInt(node->value,result);
    }

    int leftvalue;
    int rightvalue;

    if(!evaluate(node->left,leftvalue))
    {
        return false;
    }

    if(!evaluate(node->right,rightvalue))
    {
        return false;
    }

    if (node->value == "+") {
        result = leftvalue + rightvalue;
        return true;
    }

    if (node->value == "-") {
        result = leftvalue - rightvalue;
        return true;
    }

    if (node->value == "*") {
        result = leftvalue * rightvalue;
        return true;
    }

    if (node->value == "/") {
        if (rightvalue == 0) {
            return false;
        }

        result = leftvalue / rightvalue;
        return true;
    }

    return false;
}

bool ExpressionTree::evaluate(int &result)const
{
    if(root == nullptr)return false;

    return evaluate(root,result);
}

void ExpressionTree::clearStack(std::stack<Node*>& stack)
{
    while(!stack.empty())
    {
        clear(stack.top());
        stack.pop();
    }
}
bool ExpressionTree::build_expression_tree(const std::vector<std::string>& tokens)
{
    clear(root);
    root = nullptr;

    std::stack<Node*> stack;
    for(int i=0;i<tokens.size();i++)
    {
        if(isOperator(tokens[i]))
        {
            if(stack.size()<2)
            {
                clearStack(stack);
                return false;
            }

            Node* right = stack.top();
            stack.pop();

            Node* left = stack.top();
            stack.pop();

            Node* operationNode = new Node(tokens[i]);
            operationNode->left = left;
            operationNode->right = right;


            stack.push(operationNode);
        }
        else{
            if (!isNumber(tokens[i]))
            {
                clearStack(stack);
                return false;
            }

            Node* numberNode = new Node(tokens[i]);
            stack.push(numberNode);
        }
    }
    if(stack.size()!=1)
    {
        clearStack(stack);
        return false;
    }

    root = stack.top();
    return true;
}

int ExpressionTree::height(Node* node)const
{
    if(node == nullptr)
    {
        return 0;
    }

    return std::max(height(node->left),height(node->right))+1;
}

int ExpressionTree::height()const
{
    return height(root);
}