#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define true 1 == 1
#define false 1 != 1
typedef int boolean;


int coins[2][5] = {
       {50, 10, 5, 2, 1},  // номиналы используемых монет в порядке убывания (отсортировать, если нет)
       {0, 0, 0, 0, 0}     // количество использованных монет данного номинала (нули на начало расчёта)
};

int cur_kopeks = 98;  // начальное количество копеек


void Greedy_Kopeks(int i) {
    if (cur_kopeks <= 0)     // если нет больше значения для заполнения - выходим
        return;

    coins[1][i] = cur_kopeks / coins[0][i];   // количество монет (начиная с большего номинала) для заполнения текущего значения
    cur_kopeks -= coins[0][i] * coins[1][i];  // уменьшаем текущее значение

    Greedy_Kopeks(i + 1);  // рекурсивно заполняем монетами меньшего номинала
}

void main()
{
    printf("\nНачальная строка:\n");
    char input[] = "Мой дядя самых честных правил";
    printf("%s\n", input);

    int m = 0;
    for (int i = 0; i < strlen(input); i++) {
        m += (int)input[i];
    }

    printf("\nСумма кодов символов:\n");
    printf("%x\n", m);
    

    Greedy_Kopeks(0);
    
    printf("\nПотребуется монет:\n");
    for (int i = 0; i < 5; i++) {
        printf(" %d коп. - ", coins[0][i]);
        printf("%d \n", coins[1][i]);
    }

}




