#include <iostream>
#include <vector>
#include <string>
#include "tree.hpp"

void printTreeInfo(ExpressionTree& tree)
{
    std::cout << "Infix:   " << tree.getexpr_infix() << std::endl;
    std::cout << "Prefix:  " << tree.getexpr_prefix() << std::endl;
    std::cout << "Postfix: " << tree.getexpr_postfix() << std::endl;

    std::cout << "Высота: " << tree.height() << std::endl;
    std::cout << "Счетчик Операторов: " << tree.operators_count() << std::endl;

    int result;

    if (tree.evaluate(result))
    {
        std::cout << "Результат: " << result << std::endl;
    }
    else
    {
        std::cout << "Нельзя Посчитать, Неправленное Выражение" << std::endl;
    }
}

int main()
{
    std::cout << "=== Пример 1: Строим Из Постфикса ===" << std::endl;

    ExpressionTree tree1;

    std::vector<std::string> postfix = {
        "2", "3", "+", "4", "5", "*", "+"
    };

    if (!tree1.build_expression_tree(postfix))
    {
        std::cout << "Не Удалось Построить" << std::endl;
        return 1;
    }

    printTreeInfo(tree1);

    std::cout << std::endl;


    std::cout << "=== Пример 2: Строим Из Инфикса ===" << std::endl;

    ExpressionTree tree2;

    std::vector<std::string> infix = {
        "(", "2", "+", "3", ")", "*", "4"
    };

    if (!tree2.build_from_infix(infix))
    {
        std::cout << "Не Удалось Построить" << std::endl;
        return 1;
    }

    printTreeInfo(tree2);

    std::cout << std::endl;


    std::cout << "=== Пример 3: Переменные  ===" << std::endl;

    ExpressionTree tree3;

    std::vector<std::string> variables = {
        "(", "a", "+", "b", ")", "*", "2"
    };

    if (!tree3.build_from_infix(variables))
    {
        std::cout << "Не Удалось Построит" << std::endl;
        return 1;
    }
    //Задаем Значения Переменных
    tree3.setVariable("a", "3");
    tree3.setVariable("b", "5");

    printTreeInfo(tree3);

    std::cout << std::endl;


    std::cout << "=== Пример 4: Оператор ^===" << std::endl;

    ExpressionTree tree4;

    std::vector<std::string> power = {
        "2", "^", "3"
    };

    if (!tree4.build_from_infix(power))
    {
        std::cout << "Не Удалось Построить" << std::endl;
        return 1;
    }

    printTreeInfo(tree4);

    std::cout << std::endl;


    std::cout << "=== Пример 5:  Упрощение===" << std::endl;

    ExpressionTree tree5;

    std::vector<std::string> expr1 = {
        "(", "2", "+", "3", ")", "*", "x"
    };

    if (!tree5.build_from_infix(expr1))
    {
        std::cout << "Не Удалось Построить" << std::endl;
        return 1;
    }

    std::cout << "Перед Упрощением:" << std::endl;
    std::cout << "Инфикс:   " << tree5.getexpr_infix() << std::endl;
    std::cout << "Постфикс: " << tree5.getexpr_postfix() << std::endl;

    tree5.simplify();

    std::cout << "После Упрощения:" << std::endl;
    std::cout << "Инфикс:   " << tree5.getexpr_infix() << std::endl;
    std::cout << "Постфикс: " << tree5.getexpr_postfix() << std::endl;

    tree5.setVariable("x", "10");

    int simplified;

    if (tree5.evaluate(simplified))
    {
        std::cout << "Result with x = 10: " << simplified << std::endl;
    }
    else
    {
        std::cout << "Не Удалось Посчитать" << std::endl;
    }

    std::cout << std::endl;


    std::cout << "=== Пример 6: Унарный Минус ===" << std::endl;

    ExpressionTree tree6;

    std::vector<std::string> expr2 = {
        "-5", "+", "2"
    };

    if (!tree6.build_from_infix(expr2))
    {
        std::cout << "Не Удалось Построить" << std::endl;
        return 1;
    }

    printTreeInfo(tree6);

    return 0;
}