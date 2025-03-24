#include <iostream>
#include <algorithm>
#include <string>
class TEXT
{
	public:
		void CIN()
		{
			std::cout << "Enter your first str" << std::endl;
			getline(std::cin, str1_primary);
			std::cout << std::endl;
			std::cout << "Enter your second str" << std::endl;
			getline(std::cin, str2);
		}
		void FIX_STRING() //метод, что уберет всё повторяющиеся символы из строки
		{
			for (int i = 0; i < str1_primary.size(); i++) // добавляет символы в fix версию строки, в том случае 
			{											// если не находит такого же в fix версии
				char temp = str1_primary[i];
				if (str1_fixChar.find(temp) == std::string::npos) str1_fixChar.push_back(temp);
			}
		}
		void COUT_NUMBERofMeetings()
		{
			for (int i = 0; i < str1_fixChar.size(); i++)
			{
				std::cout << "The charaster \'" << str1_fixChar[i] << "\' occurs " << NumberOfMeetings(str1_fixChar[i]) <<" times" << std::endl;
			}
		}
		void COUT_STRfix()
		{
			std::cout << "\n";
			std::cout << "The string without specific word:" << std::endl;
			std::cout << Annihilation(str1_primary) << std::endl; 
		}
	private:
		std::string str1_primary;//строка, в которую ведется первоночальнй ввод и из которой удаляются слова
		std::string str2;
		std::string str1_fixChar;  // строка, состоящая из неповторяющихся символов строки str1
		std::string str1_fixString; // строка без слова разрушение
		const std::string str_del = "destruction";

		int NumberOfMeetings(char& temp) 
		{// метод, что считает количество встреч определенного символа в строке
			int number = 0;
			for (int i = 0; i < str2.size(); i++) 
			{
				if (str2[i] == temp) number++;
			}
				return number;
		}
		std::string Annihilation(std::string& temp) // удаление подстроки в строке
		{
			int word_pos = temp.find(str_del);
			while (word_pos != std::string::npos)
			{
				temp.erase(word_pos, str_del.size());
				word_pos = temp.find(str_del);
			}
			return temp;
		}
};

int main()
{
	TEXT* text = new TEXT;
	text->CIN();
	text->FIX_STRING();
	text->COUT_NUMBERofMeetings();
	text->COUT_STRfix();

}

