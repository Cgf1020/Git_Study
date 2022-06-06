#pragma once
class __declspec(dllexport)TestClass
{
public:
	TestClass(int a, int b);

	int add(int a, int b);

private:
	int a;
	int b;

};

