#ifndef CALCULATOR_BINARY_EXPRESSION_HPP
#define CALCULATOR_BINARY_EXPRESSION_HPP

#include "expression.hpp"

namespace calc::expression
{
	struct binary : interface
	{
		binary(char operation, std::unique_ptr<interface>&& expr1, std::unique_ptr<interface>&& expr2) :
			m_expr1(std::move(expr1)), m_expr2(std::move(expr2)), m_operation(operation) {}

		double eval() const override
		{
		   switch (m_operation)
		   {
			  case '+':
				 return m_expr1->eval() + m_expr2->eval();

			  case '-':
				 return m_expr1->eval() - m_expr2->eval();

			  case '*':
				 return m_expr1->eval() * m_expr2->eval();

			  case '/':
				 return m_expr1->eval() / m_expr2->eval();

			  default:
				 throw std::runtime_error("Unknown binary operator");
		   }
		}

		void print(std::ostream& os) const override
		{
		   os << '(' << *m_expr1 << " " << m_operation << " " << *m_expr2 << ')';
		}

	  private:
		std::unique_ptr<interface> m_expr1, m_expr2;
		char m_operation;
	};
} // namespace calc::expression

#endif //CALCULATOR_BINARY_EXPRESSION_HPP
