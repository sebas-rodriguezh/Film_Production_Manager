#pragma once
#include <string>
#include <iostream>
using namespace std; 
class ExcepcionStudio
{
public: 
	ExcepcionStudio(); 
	~ExcepcionStudio(); 
	virtual string mensaje() const = 0;  
};

