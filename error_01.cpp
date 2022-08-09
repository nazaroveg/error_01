// error_01.cpp 
//

#include <iostream>
#include <string>
#include <Windows.h>  //для SetConsoleCP(1251);
#include <exception>












	

	int function(std::string str, int forbidden_length)
	{
		int size;
		 size = str.length();
		if (size != forbidden_length) 
		{
			throw std::exception ("Вы ввели слово запретной длины! До свидания");
		}		
		return size;
	}









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

		try
		{
			 function(word, length);
			
		}
		catch (const std::exception &ex )
		{
			std::cout << ex.what();
			break;
		}
		std::cout << "Длина слова " << word << " равна " << length << std::endl;
		
	}
	
	
	


	return 0;
}
