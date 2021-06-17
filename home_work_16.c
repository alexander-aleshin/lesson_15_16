#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define true 1 == 1
#define false 1 != 1
typedef int boolean;


void Ceasar_Encript(char* in, char* out, int key) {  // кодирование, реализовано только для латинских букв
    int i;
    for (i = 0; in[i] != '\0'; i++) {

        int tmp = (int)in[i];  // числовое значение символа по ASCII
 
        if ((tmp >= 65 && tmp <= 90) || (tmp >= 97 && tmp <= 122)) {  // только заглавные и строчные буквы латинского алфавита
            tmp += key; // сдвигаем буквы

            if (tmp > 90 && tmp <= 90 + key)      // закольцовываем последние заглавные буквы латинского алфавита
                tmp -= 26;

            if (tmp > 122 && tmp <= 122 + key)    // закольцовываем последние строчные буквы латинского алфавита
                tmp -= 26;
        }
            
        out[i] = (char)tmp;
    }
    out[i] = '\0';
}

void Ceasar_Decript(char* in, char* out, int key) {  // раскодирование, реализовано только для латинских букв
    int i;
    for (i = 0; in[i] != '\0'; i++) {

        int tmp = (int)in[i];  // числовое значение символа по ASCII
 
        if ((tmp >= 65 && tmp <= 90) || (tmp >= 97 && tmp <= 122)) {  // только заглавные и строчные буквы латинского алфавита
            tmp -= key; // сдвигаем буквы

            if (tmp < 65 && tmp >= 65 - key)      // закольцовываем первые заглавные буквы латинского алфавита
                tmp += 26;

            if (tmp < 97 && tmp >= 97 - key)    // закольцовываем первые строчные буквы латинского алфавита
                tmp += 26;
        }
            
        out[i] = (char)tmp;
    }
    out[i] = '\0';
}

void shuffle(char* in, char* out, int key) {  // шифрование методом перестановок
    int len = strlen(in);
    int n_char = len / key + 1;  // сколько символов будет в каждом столбце
    char** cols = (char**) malloc(key);   // выделяем память под столбцы с символами
    if (cols) {
        for (int i = 0; i < key; i++) {
            cols[i] = (char*) malloc(n_char);
            if (!cols[i]) {
                printf("Can't allocate memory!");
                return;
            }
        }
    }
    else {
        printf("Can't allocate memory!");
        return;
    }

    for (int i = 0; i < key; i++) {     // обнуляем элементы массивов
        for (int j = 0; j < n_char; j++) {
            cols[i][j] = '\0';
        }
    }
    
    int counter = 0;
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < n_char; j++) {
            cols[i][j] = in[counter++];   // помещаем символы входящей строки в столбцы
        }
    }
        
    counter = 0;
    for (int j = 0; j < n_char; j++) {
        for (int i = 0; i < key; i++) {
            if (cols[i][j] != '\0')     // чтоб терминирующий 0 не помешал последующему выводу на дисплей
                out[counter++] = cols[i][j];   // помещаем символы в выходную строку "поперечно"
        }
    }
    out[counter] = '\0';  
    
    free(cols);
}

void main()
{
    char in[16];
    char out[16];
    strcpy(in, "Hello, world!");
    printf("\nНачальная строка: %s\n", in);

    Ceasar_Encript(in, out, 3);
    printf("\nЗашифрованная методом цезаря строка: %s\n", out);
    Ceasar_Decript(out, in, 3);
    printf("\nРасшифрованная строка: %s\n", in);
    printf("\n");

    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));
    strcpy(in, "Hello, world!");
    printf("\nНачальная строка: %s\n", in);
    shuffle(in, out, 4);
    printf("\nЗашифрованная методом перестановки строка: %s\n", out);
}




