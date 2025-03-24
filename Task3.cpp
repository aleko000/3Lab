#include <string>
#include <iostream>
#include <algorithm>
class TEXT
{
    public:
        void CIN()
        {
            std::cout << "Eneter your sentence" << std::endl;
            std::cin >> doc1;
            std::cout << std::endl;
        }
        void Rewrite()
        { //переписываем в doc2 из doc1 заглавные буквы
            for (int i = 0; i < doc1.size(); i++) 
            {   //заглавные буквы имееют код в таблице ASCII в диапазоне 65:90
                if (doc1[i] >= 65 && doc1[i] <= 90) doc2.push_back(doc1[i]);
            }
        
        }
        void SORT()
        { // bubble sort
            for(int j = 1; j < doc2.size(); j++)
            {
                for (int i = 0; i < doc2.size() - 1; i++)
                {
                    if (doc2[i] > doc2[i + 1])
                    {
                        double x = doc2[i];
                        doc2[i] = doc2[i + 1];
                        doc2[i + 1] = x;
                    }
                }
            }
        }
        void COUT()
        {
            std::cout << doc2 << std::endl;
        }
    private:
        std::string doc1;
        std::string doc2;
        
        int lengthsize = doc2.size(); // переменная для сортировки
};
int main()
{
    TEXT* text = new TEXT;
    text->CIN();
    text->Rewrite();
    text->SORT();
    text->COUT();
    return 0;
}

