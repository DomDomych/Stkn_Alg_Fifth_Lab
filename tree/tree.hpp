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
    ExprNode* root;
    void clearStack(std::stack<ExprNode*>& stack);
    ExprNode* simplify(ExprNode* node);
    bool isConstant(ExprNode* node)const;
    void clear(ExprNode* node);
    bool isOperator(const std::string& token)const;
    bool evaluate(ExprNode* node,int& result)const;
    bool isNumber(const std::string& s)const;
    bool stringToInt(const std::string& s,int& v) const;
    bool infix_to_postfix(const std::vector<std::string>& tokens,std::vector<std::string>& postfix)const;
    int height(ExprNode* node)const;
    int operators_count(ExprNode* node)const;
    int priority(const std::string& op)const;
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
    bool build_from_infix(const std::vector<std::string>&tokens);
    int operators_count()const;
    int height()const;
    void simplify();
    void setVariable(const std::string& name,const std::string& value);
};