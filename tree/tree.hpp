#include "AVLMap.hpp"
#include <string>
#include <vector>
#include <stack>

class ExprNode
{
    public:

    std::string value;
    ExprNode* left;
    ExprNode* right;

    ExprNode(const std::string& v);
};

class ExpressionTree
{
    private:
    void clearStack(std::stack<ExprNode*>& stack);
    ExprNode* root;
    void clear(ExprNode* node);
    bool isOperator(const std::string& token)const;
    bool evaluate(ExprNode* node,int& result)const;
    bool isNumber(const std::string& s)const;
    bool stringToInt(const std::string& s,int& v) const;
    int height(ExprNode* node)const;
    int operators_count(ExprNode* node)const;
    std::string getexpr_postfix(ExprNode* node)const;
    std::string getexpr_prefix(ExprNode* node)const;
    std::string getexpr_infix(ExprNode* node)const;
    AVLTree variables;
    public:
    ExpressionTree();
    ~ExpressionTree();
    ExpressionTree(const ExpressionTree&) = delete;
    ExpressionTree& operator=(const ExpressionTree&)=delete;
    std::string getexpr_postfix()const;
    std::string getexpr_prefix()const;
    std::string getexpr_infix()const;
    bool build_expression_tree(const std::vector<std::string>& v);
    bool evaluate(int& result) const;
    int operators_count()const;
    int height()const;

    void setVariable(const std::string& name,const std::string& value);
};