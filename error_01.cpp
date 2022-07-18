// error_01.cpp 
//

#include <iostream>
#include <string>
#include <Windows.h>




class My_error : public std::exception
{
public:
	My_error(std::string word, int size) : std::exception()
	{
		this -> word = word;
		this -> size = size;
	};
	
	~My_error() = default;

	

	int function(std::string str, int forbidden_length)
	{
		
		size = str.length();
		if (size != forbidden_length) 
		{
			throw My_error(str, forbidden_length);
		}		
		return size;
	}


	void print()
	{
		std::cout << "Длина слова " << "< " << word << " > " << "равна: " << size << std::endl;

	}
	


private:
	int size = 0;
	std::string word;

};






int main()
{
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);

	int length = 0;
	std::string word;
	

	
	while (!0)
	{
		std::cout << "Введите запретную длину: " << std::endl;
		std::cin >> length;
		std::cout << "Введите слово: " << std::endl;
		std::cin >> word;
		My_error my_errror{ word, length };

		try
		{
			my_errror.function(word, length);
		}
		
		catch (...) {
			std::cout << "Вы ввели слово запретной длины!До свидания" << std::endl;
			break;
		}
		
		
		my_errror.print();
		
		my_errror.~My_error();
	}
	
	
	


	return 0;
}
