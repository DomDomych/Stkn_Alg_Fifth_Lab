#pragma once

#include "AVLMap.hpp"
#include <string>
#include <vector>
#include <stack>

using VariableStorage = AVLTree;

class ExprNode
{
public:
    virtual ~ExprNode() = default;

    virtual int evaluate(const VariableStorage&) const = 0;

    virtual std::string toInfix() const = 0;
    virtual std::string toPrefix() const = 0;
    virtual std::string toPostfix() const = 0;

    virtual int height() const = 0;
    virtual int operatorsCount() const = 0;
};

class NumberNode : public ExprNode
{
private:
    int value;

public:
    explicit NumberNode(int value);
    int evaluate(const VariableStorage&) const override;

    std::string toInfix() const override;
    std::string toPrefix() const override;
    std::string toPostfix() const override;

    int height() const override;
    int operatorsCount() const override;
};

class BinaryOperatorNode : public ExprNode
{
private:
    std::string op;

    ExprNode *left;
    ExprNode *right;

    int priority() const;
public:
    BinaryOperatorNode(const std::string& op,
                                ExprNode *left,
                                ExprNode *right);
    ~BinaryOperatorNode() override;

    int evaluate(const VariableStorage&) const override;

    std::string toInfix() const override;
    std::string toPrefix() const override;
    std::string toPostfix() const override;

    int height() const override;
    int operatorsCount() const override;
};

class VariableNode : public ExprNode
{
private:
    std::string name;
public:
    explicit VariableNode(const std::string& name);

    int evaluate(const VariableStorage&) const override;

    std::string toInfix() const override;
    std::string toPrefix() const override;
    std::string toPostfix() const override;

    int height() const override;
    int operatorsCount() const override;
};  

class ExpressionTree
{
private:
    ExprNode *root;
    void clearStack(std::stack<ExprNode *> &stack);
    ExprNode *simplify(ExprNode *node);
    bool isConstant(ExprNode *node) const;
    void clear(ExprNode *node);
    bool isOperator(const std::string &token) const;
    bool isNumber(const std::string &s) const;  
    bool stringToInt(const std::string &s, int &v) const;
    bool infix_to_postfix(const std::vector<std::string> &tokens, std::vector<std::string> &postfix) const;
    VariableStorage variables;

public:
    ExpressionTree();
    ~ExpressionTree();
    ExpressionTree(const ExpressionTree &) = delete;
    ExpressionTree &operator=(const ExpressionTree &) = delete;
    std::string getexpr_postfix() const;
    std::string getexpr_prefix() const;
    std::string getexpr_infix() const;
    bool build_expression_tree(const std::vector<std::string> &v);
    bool evaluate(int &result) const;
    bool build_from_infix(const std::vector<std::string> &tokens);
    int operators_count() const;
    int height() const;
    void simplify();
    void setVariable(const std::string &name, const std::string &value);
};