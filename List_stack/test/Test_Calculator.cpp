#include "gtest.h"
#include "../Stack/Calculator.h"
#include "../Stack/Calculator.cpp"

TEST(Calculator, can_create_a_calculator)
{
    ASSERT_NO_THROW(TCalculator calc);
}
TEST(Calculator, can_pass_a_string_to_the_calculator)
{
    TCalculator calc;
    std::string str = "1+5*2";
    ASSERT_NO_THROW(calc.SetFormula(str));
}
TEST(Calculator, can_pass_the_correct_string_with_parentheses_to_the_calculator)
{
    TCalculator calc;
    std::string str = "(1+5)*2";
    ASSERT_NO_THROW(calc.SetFormula(str));
}

TEST(Calculator, passing_a_formula_with_incorrectly_placed_parentheses_to_the_calculator_will_cause_an_exception)
{
    TCalculator calc;
    std::string str = "(1+5*2";
    ASSERT_ANY_THROW(calc.SetFormula(str));
}
TEST(Calculator, can_calculate_the_result_of_an_arithmetic_expression)
{
    TCalculator calc;
    calc.SetFormula("1+5*2");
    calc.ToPostfix();
    ASSERT_NO_THROW(calc.CalcPostfix());
}
TEST(Calculator, evaluating_an_expression_with_incorrect_operations_will_throw_an_exception)
{
    TCalculator calc;
    calc.SetFormula("1+5*");
    calc.ToPostfix();
    ASSERT_ANY_THROW(calc.CalcPostfix());
}


TEST(Calculator, the_calculator_adds_integers_correctly)
{
    TCalculator calc;
    calc.SetFormula("1+5");
    calc.ToPostfix();
    double a = 1.0 + 5.0;
    EXPECT_EQ(a, calc.CalcPostfix());
}


TEST(Calculator, the_calculator_subtracts_integers_correctly)
{
    TCalculator calc;
    calc.SetFormula("2-3");
    calc.ToPostfix();
    double a = 2.0 - 3.0;
    EXPECT_EQ(a, calc.CalcPostfix());
}


TEST(Calculator, the_calculator_multiplies_integers_correctly)
{
    TCalculator calc;
    calc.SetFormula("3*7");
    calc.ToPostfix();
    double a = 3.0*7.0;
    EXPECT_EQ(a, calc.CalcPostfix());
}


TEST(Calculator, the_calculator_divides_integers_correctly)
{
    TCalculator calc;
    calc.SetFormula("5/2");
    calc.ToPostfix();
    double a = 5.0/2.0;
    EXPECT_EQ(a, calc.CalcPostfix());
}


TEST(Calculator, the_calculator_raise_to_a_degree_integers_correctly)
{
    TCalculator calc;
    calc.SetFormula("3^8");
    calc.ToPostfix();
    double a = pow(3.0, 8.0);
    EXPECT_EQ(a, calc.CalcPostfix());
}

TEST(Calculator, the_calculator_correctly_counts_complex_arithmetic_expressions)
{
    TCalculator calc;
    calc.SetFormula("3*7/(2+5)-(10*4-39)");
    calc.ToPostfix();
    EXPECT_EQ(2, calc.CalcPostfix());
}