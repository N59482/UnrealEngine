#include <iostream>
#include <string>

using namespace std;

string make_bracket(string str)
	{
	   	// Переводим строку в нижний регистр
	    for(int i = 0; i < str.length(); i++)
	        str[i] = tolower(str[i]);
	    // Инициализируем массив-маркер уникальных символов строки (все значения по умолчанию уникальны)
	    bool uniqe[str.length()];
	    fill_n(uniqe,str.length(), 1);

	    // Находим повторяющиеся символы строки и отмечаем их в массиве значением 0
	    for(int i = 0; i < (str.length()-1); i++)
	    	for(int j = i+1; j<str.length();j++)
	    		if(str[i] == str[j])
	    			uniqe[i] = uniqe[j] = 0;

	    // Заменяем символы строки на символы '(' и ')'
	    for(int i = 0; i < str.length(); i++)
	    	if(uniqe[i])
	    		str[i] = '(';
	    	else
	    		str[i] = ')';
	    return str;
	};

int main()
	{
		string add = "";
		getline(cin, add);
		string result = make_bracket(add);
		for(char i : result)
		    cout<<i;
		cout<<endl;
	};