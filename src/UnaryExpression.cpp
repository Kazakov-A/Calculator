/**
 * author   k 
 * date     06.08.17.
 */

#include "UnaryExpression.h"

UnaryExpression::UnaryExpression(char operation, Expression* data) : operation(operation), data(data){}

float UnaryExpression::eval()
{
	return -(data->eval());
}

UnaryExpression::~UnaryExpression()
{
	delete data;
}

void UnaryExpression::print(std::ostream& os) const
{
	os << operation << *data;
}
