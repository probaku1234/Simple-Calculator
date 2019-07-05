#pragma once
#include "stdafx.h"
#include <vector>
#include <stack>

class StringProcessor
{
public:
	StringProcessor(string input);
	~StringProcessor();

	int Process();

private:
	string input;
	vector<string> tokenlist;
	vector<string> explist;
	stack<string> operatorList;

	void ParsingInput();
	void PrintTokenList();
	void PrintExpList();
	void ConverttoPostfix();
	int Calculate(int oprd1, int oprd2, char opeator);
	int Eval();
	int GetPriority(char operation);
};