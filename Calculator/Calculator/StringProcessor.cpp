#include "stdafx.h"
#include "StringProcessor.h"

StringProcessor::StringProcessor(string input)
{
	this->input = input;
}

StringProcessor::~StringProcessor()
{
}

void StringProcessor::ParsingInput()
{
	string s;
	s.assign(this->input);
	string delimiter = " ";

	int pos = 0;
	string token;
	while ((pos = s.find(delimiter)) != string::npos)
	{
		token = s.substr(0, pos);
		this->tokenlist.push_back(token);
		s.erase(0, pos + delimiter.length());
	}
	tokenlist.push_back(s);
}

void StringProcessor::PrintTokenList()
{
	for (int i = 0; i < tokenlist.size(); i++)
	{
		cout << tokenlist.at(i) << " " << endl;
	}
}

void StringProcessor::PrintExpList()
{
	for (int i = 0; i < explist.size(); i++)
	{
		cout << explist.at(i) << " " << endl;
	}
}

void StringProcessor::ConverttoPostfix()
{
	for (int i = 0; i < tokenlist.size(); i++)
	{
		string token = tokenlist.at(i);
		if (isdigit(token.at(0))) {
			explist.push_back(token);
		}
		else {
			char operation = token.at(0);

			if (operatorList.empty() || operation == '(')
				operatorList.push(token);
			else if (operation == ')') {
				while (true)
				{
					string lastElement = operatorList.top();
					operatorList.pop();

					if (lastElement.at(0) == '(')
						break;

					explist.push_back(lastElement);
				}
			}
			else if (GetPriority(operatorList.top().at(0)) < GetPriority(operation)) {
				operatorList.push(token);
			}
			else {
				while (!operatorList.empty() && GetPriority(operation) <= GetPriority(operatorList.top().at(0)))
				{
					explist.push_back(operatorList.top());
					operatorList.pop();
				}
				operatorList.push(token);
			}
		}
	}

	while (!operatorList.empty())
	{
		explist.push_back(operatorList.top());
		operatorList.pop();
	}
}

int StringProcessor::Calculate(int oprd1, int oprd2, char opeator)
{
	if (opeator == '+') {
		return oprd1 + oprd2;
	}
	else if (opeator == '-') {
		return oprd1 - oprd2;
	}
	else if (opeator == '*') {
		return oprd1 * oprd2;
	}
	else {
		return oprd1 / oprd2;
	}
}

int StringProcessor::Eval()
{
	stack<int> oprdStack;

	for (int i = 0; i < explist.size(); i++)
	{
		string member = explist.at(i);

		if (isdigit(member.at(0)))
			oprdStack.push(stoi(member, nullptr));
		else {
			int oprd2 = oprdStack.top();
			oprdStack.pop();
			int oprd1 = oprdStack.top();
			oprdStack.pop();
			oprdStack.push(Calculate(oprd1, oprd2, member.at(0)));
		}
	}


	return oprdStack.top();
}

int StringProcessor::GetPriority(char operation)
{
	if (operation == '*' || operation == '/')
		return 2;
	else if (operation == '+' || operation == '-')
		return 1;
	else if (operation == '(')
		return 0;
	else
		return -1;
}

int StringProcessor::Process()
{
	StringProcessor::ParsingInput();
	//StringProcessor::PrintTokenList();
	StringProcessor::ConverttoPostfix();
	//StringProcessor::PrintExpList();

	return StringProcessor::Eval();
}