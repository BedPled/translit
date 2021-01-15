#include <iostream>
#include "lib.h"
#include <string>

/*

Реализовать функционал транслитерации предложения содержащего русские символы(char*).
Каждый русскоязычный символ заменяется на созвучную последовательность из букв латинского алфавита.
Пример: "Привет, Ярик!" -> "Privet, Yarik!"
Запрещается использование любых функций для работы со строками (разрешаются только самописные).
Т.е. нельзя strlen и тд, но можно реализовать самому strlen. Кодировка входных данных: utf-8.

Помогалочка: https://apps.timwhitlock.info/unicode/inspect?s=%D0%90
https://utf8-chartable.de/unicode-utf8-table.pl?start=900

*/

using namespace std;


int main() {
    char *inStr = new char[500]; // входная строка
    //char *outStr = new char[1000]; // входная строка

    cin.getline(inStr, 500, '\n');

    cout << translitStr(inStr);

    return 0;
}
