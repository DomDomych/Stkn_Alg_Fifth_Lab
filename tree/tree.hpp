    #pragma once

#include "AVLMap.hpp"
#include <string>
#include <vector>
#include <stack>
#include <memory>


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

    virtual bool isConstant() const = 0;

    virtual std::unique_ptr <ExprNode> simplify(const VariableStorage&) = 0;
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
    bool isConstant()const override;

    std::unique_ptr <ExprNode> simplify(const VariableStorage&) override;
};

class BinaryOperatorNode : public ExprNode
{
private:
    std::string op;
    std::unique_ptr <ExprNode> left;
    std::unique_ptr <ExprNode> right;

    int priority() const;
public:
    BinaryOperatorNode(const std::string&,
                       std::unique_ptr <ExprNode>,
                       std::unique_ptr <ExprNode>);
    //~BinaryOperatorNode() override;

    int evaluate(const VariableStorage&) const override;

    std::string toInfix() const override;
    std::string toPrefix() const override;
    std::string toPostfix() const override;

    int height() const override;
    int operatorsCount() const override;
    bool isConstant() const override;

    std::unique_ptr <ExprNode> simplify(const VariableStorage&) override;
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
    bool isConstant() const override;

    std::unique_ptr <ExprNode> simplify(const VariableStorage&) override;
};  

class ExpressionTree
{
private:
    std::unique_ptr <ExprNode> root;

    bool isConstant(ExprNode *node) const;
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
    bool evaluate(int &result,const VariableStorage& Storage) const;
    bool build_from_infix(const std::vector<std::string> &tokens);
    int operators_count() const;
    int height() const;
    void simplify();
    void setVariable(const std::string &name, const std::string &value);
};