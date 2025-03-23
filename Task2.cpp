#include <iostream>
#include <string>
#include <algorithm>

class TEXT
{
public:
	void CIN() //считывание
	{
		std::cout << "Enter your text:" << std::endl;
		getline(std::cin, doc);
	}
	void DELETE_CHAR() // deleting char
	{
		for (int i = 0; i < doc.size(); i++)
		{
			if (doc[i] == symbol) doc.erase(i, 1);
		}
	}
	void probels()  //deleting probels
	{
		for (int i = 0; i < doc.size(); i++)
			if (doc[i] == ' ' && doc[i + 1] == ',') doc.erase(i, 1);
	}
		void COUT() // couting
	{
		std::cout << std::endl;
		std::cout << doc << std::endl;
	}

private:
	std::string doc;
	const char symbol = '$'; // удаляемый символ
};

int main()
{
	TEXT* text = new TEXT;

	text->CIN();
	text->DELETE_CHAR();
	text->probels();
	text->COUT();




	return 0;
}
