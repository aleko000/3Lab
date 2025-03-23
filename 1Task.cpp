#include <iostream>
#include <string>
#include <algorithm>

class STRING
{
public:
	void CIN() //считывание
	{
		std::cout << "Enter your sentence:" << std::endl;
		getline(std::cin, str1);
	}
	void REPLACE() // замена всех four на good и скобок на пробелы
	{		
		// replace four
			word_pos = str1.find("four");
			while (word_pos != std::string::npos) 
			{
				str1.replace(word_pos, 4, "good");
				word_pos = str1.find("four");	
			}
			// replace скобок
			std::replace(str1.begin(), str1.end(), '(', ' ');
			std::replace(str1.begin(), str1.end(), ')', ' ');
			//не допускает образование подобных конструкций наподобии "let's fun ."
			for (int i = 0; i < str1.size(); i++)
			{
				if (str1[i] == ' ' && str1[i + 1] == '.') str1.replace(i, 1, "");
			}

	}
	void Word_and_sentence() // метод считающий количество слов по пробелам, а предложений по точкам
	{
		//count words
		//if str empty, то word_counter = 0 по умолчанию
		//if there a place in the start
		for (int i = 0; i < str1.size(); i++)
		{
			if (str1[0] == ' ') continue;
			else if (str1[i] == ' ' && str1[i - 1] != ' ') word_counter++;
		}
		word_counter += 1; // т.к в конце нет точки
		//count sentence
		for (int i = 0; i < str1.size(); i++)
		{
			if (str1[0] == '.') continue;
			else if (str1[i] == '.') sentence_counter++;
		}

	}
	void console()
	{
		std::cout << std::endl;
		std::cout << str1 << std::endl;
		std::cout << "Number of words: " << word_counter << ". Number of sentence: " << sentence_counter << std::endl;
	}

private:
	std::string str1;
	const std::string str2 = "good"; // заменяющее слово
	int word_counter = 0;
	int sentence_counter = 0;
	int word_pos = 0;
};

int main()
{
	STRING* str = new STRING;

	str->CIN();
	str->REPLACE();
	str->Word_and_sentence();
	str->console();
	
	


	return 0;
}

