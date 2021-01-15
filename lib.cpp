#include <iostream>
#include "lib.h"

 char translitTable[][4] = {
        {'A', ' ', ' ', ' '},      // А
        {'B', ' ', ' ', ' '},      // Б
        {'V', ' ', ' ', ' '},      // В
        {'G', ' ', ' ', ' '},      // Г
        {'D', ' ', ' ', ' '},      // Д
        {'E', ' ', ' ', ' '},      // е
        {'Z', 'h', ' ', ' '},  // Ж
        {'Z', ' ', ' ', ' '},      // З
        {'I', ' ', ' ', ' '},      // И
        {'Y', ' ', ' ', ' '},      // Й
        {'K', ' ', ' ', ' '},      // K
        {'L', ' ', ' ', ' '},      // Л
        {'M', ' ', ' ', ' '},      // М
        {'N', ' ', ' ', ' '},      // Н
        {'O', ' ', ' ', ' '},      // О
        {'P', ' ', ' ', ' '},      // П
        {'R', ' ', ' ', ' '},      // Р
        {'S', ' ', ' ', ' '},      // С
        {'T', ' ', ' ', ' '},      // Т
        {'U', ' ', ' ', ' '},      // У
        {'F', ' ', ' ', ' '},      // Ф
        {'K', 'h', ' ', ' '},     // X
        {'T', 's', ' ', ' '},     // Ц
        {'C', 'h', ' ', ' '},     // Ч
        {'S', 'h', ' ', ' '},     // Ш
        {'S', 'c', 'h', ' '},    // Щ
        {' ', ' ', ' ', ' '},       // Ъ
        {'Y', ' ', ' ', ' '},      // Ы
        {' ', ' ', ' ', ' '},       // Ь
        {'E', ' ', ' ', ' '},      // Э
        {'Y', 'u', ' ', ' '},     // Ю
        {'Y', 'a', ' ', ' '},     // Я
        {'a', ' ', ' ', ' '},      // а
        {'b', ' ', ' ', ' '},      // б
        {'v', ' ', ' ', ' '},      // в
        {'g', ' ', ' ', ' '},      // г
        {'d', ' ', ' ', ' '},      // д
        {'e', ' ', ' ', ' '},      // е
        {'z', 'h', ' ', ' '},     // ж
        {'z', ' ', ' ', ' '},      // з
        {'i', ' ', ' ', ' '},      // и
        {'y', ' ', ' ', ' '},      // й
        {'k', ' ', ' ', ' '},      // л
        {'l', ' ', ' ', ' '},      // Л
        {'m', ' ', ' ', ' '},      // М
        {'n', ' ', ' ', ' '},      // Н
        {'o', ' ', ' ', ' '},      // О
        {'p', ' ', ' ', ' '},      // П
        {'r', ' ', ' ', ' '},      // Р
        {'s', ' ', ' ', ' '},      // С
        {'t', ' ', ' ', ' '},      // Т
        {'u', ' ', ' ', ' '},      // У
        {'f', ' ', ' ', ' '},      // Ф
        {'k', 'h', ' ', ' '},     // X
        {'t', 's', ' ', ' '},     // Ц
        {'c', 'h', ' ', ' '},     // Ч
        {'s', 'h', ' ', ' '},     // Ш
        {'s', 'c', 'h', ' '},    // Щ
        {' ', ' ', ' ', ' '},       // Ъ
        {'y', ' ', ' ', ' '},      // Ы
        {' ', ' ', ' ', ' '},       // Ь
        {'e', ' ', ' ', ' '},      // Э
        {'y', 'u', ' ', ' '},     // Ю
        {'y', 'a', ' ', ' '}      // Я
};



char *translitStr(char *inStr) {
    int count = 0;
    char *outStr = new char[1000]; // входная строка

    int i = 0;
    while (inStr[i] != '\0' && i < 500) {


        if (inStr[i] == (char)208 && inStr[i + 1] == (char)129) {
            outStr[count] = 'Y';
            count++;

            outStr[count] = 'o';
            count++;

            i+=2;
        } else if (inStr[i] == (char)209 && inStr[i + 1] == (char)145) {
            outStr[count] = 'y';
            count++;

            outStr[count] = 'o';
            count++;

            i+=2;
        } else if (inStr[i] == (char)208) { // русские буквы
            // hardcode ё и Ё
            if ((char)translitTable[inStr[i+1] - (char)144][0] != ' ') {
                outStr[count] = (char) translitTable[inStr[i + 1] - (char) 144][0];
                count++;
            }

            if ((char)translitTable[inStr[i+1] - (char)144][1] != ' ') {
                outStr[count] = (char) translitTable[inStr[i + 1] - (char) 144][1];
                count++;
            }

            if ((char)translitTable[inStr[i+1] - (char)144][2] != ' ') {
                outStr[count] = (char) translitTable[inStr[i + 1] - (char) 144][2];
                count++;
            }

            if ((char)translitTable[inStr[i+1] - (char)144][3] != ' ') {
                outStr[count] = (char) translitTable[inStr[i + 1] - (char) 144][3];
                count++;
            }

            i+=2;
        } else if (inStr[i] == (char)209) {
            if ((char)translitTable[(unsigned char)inStr[i+1] - (unsigned char)80][0] != ' ') {
                outStr[count] = (char) translitTable[(unsigned char) inStr[i + 1] - (unsigned char) 80][0];
                count++;
            }

            if ((char)translitTable[(unsigned char)inStr[i+1] - (unsigned char)80][1] != ' ') {
                outStr[count] = (char) translitTable[(unsigned char) inStr[i + 1] - (unsigned char) 80][1];
                count++;
            }

            if ((char)translitTable[(unsigned char)inStr[i+1] - (unsigned char)80][2] != ' ') {
                outStr[count] = (char) translitTable[(unsigned char) inStr[i + 1] - (unsigned char) 80][2];
                count++;
            }

            if ((char)translitTable[(unsigned char)inStr[i+1] - (unsigned char)80][3] != ' ') {
                outStr[count] = (char) translitTable[(unsigned char) inStr[i + 1] - (unsigned char) 80][3];
                count++;
            }

            i+=2;
        } else { // всё остальное
            outStr[count] = inStr[i];
            i++;
            count++;
        }
    }

    return outStr;
}