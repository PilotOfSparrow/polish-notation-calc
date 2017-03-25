#include <iostream>
#include <string>
#include <sstream>
#include <stack>

int main()
{
	std::string imp_str;
	std::stack<int> symb_stack;

	getline(std::cin, imp_str);

	std::stringstream ss;

	ss << imp_str;

	std::string symbol;
	while (ss >> symbol)
	{
		if (symbol != "+" && symbol != "-" && symbol != "*" && symbol != "/")	symb_stack.push(stoi(symbol));
		else
			{
				int tmp_result = 0;

				int tmp_second_value = symb_stack.top();
				symb_stack.pop();

				int tmp_first_value = symb_stack.top();
				symb_stack.pop();

				switch(symbol[0])
				{
					case '+': tmp_result = tmp_first_value + tmp_second_value; 
						break;
					case '-': tmp_result = tmp_first_value - tmp_second_value; 
						break;
					case '*': tmp_result = tmp_first_value * tmp_second_value;
						break;
					case '/': tmp_result = tmp_first_value / tmp_second_value;
						break;
				}

				symb_stack.push(tmp_result);
			}
	}

	std::cout << symb_stack.top() << std::endl;
}