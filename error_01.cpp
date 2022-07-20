// error_01.cpp 
//

#include <iostream>
#include <string>
#include <Windows.h>  //для SetConsoleCP(1251);
#include <exception>


class My_error :public std::exception
{
public:
	My_error(){}

	const char* what() const override
	{
		return "Вы ввели слово запретной длины! До свидания ";
	}
};







class My_length : public My_error 
{
public:
	My_length(std::string word, int size)
	{
		this -> word = word;
		this -> size = size;
	};
	
	~My_length() = default;

	

	void function(std::string str, int forbidden_length)
	{
		
		size = str.length();
		if (size != forbidden_length) 
		{
			throw My_error ();
		}		
		//return size;
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
		My_length my_length{ word, length };
		
		try
		{
			my_length.function(word, length);
		}
		

		catch (const My_error &A)
		{
			std::cout << A.what();
		}

		
		my_length.print();
		
		my_length.~My_length();
	}
	
	
	


	return 0;
}
