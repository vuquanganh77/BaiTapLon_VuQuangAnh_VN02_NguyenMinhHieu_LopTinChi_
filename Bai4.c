//Quy uoc
//00 -> A  tep | 01 -> A  bich | 02 -> A  ro | 03 -> A  co
//04 -> 2  tep | 05 -> 2  bich | 06 -> 2  ro | 07 -> 2  co
//08 -> 3  tep | 09 -> 3  bich | 10 -> 3  ro | 11 -> 3  co
//12 -> 4  tep | 13 -> 4  bich | 14 -> 4  ro | 15 -> 4  co
//16 -> 5  tep | 17 -> 5  bich | 18 -> 5  ro | 19 -> 5  co
//20 -> 6  tep | 21 -> 6  bich | 22 -> 6  ro | 23 -> 6  co
//24 -> 7  tep | 25 -> 7  bich | 26 -> 7  ro | 27 -> 7  co
//28 -> 8  tep | 39 -> 8  bich | 30 -> 8  ro | 31 -> 8  co
//32 -> 9  tep | 33 -> 9  bich | 34 -> 9  ro | 35 -> 9  co
//36 -> 10 tep | 37 -> 10 bich | 38 -> 10 ro | 39 -> 10 co
//40 -> J  tep | 41 -> J  bich | 42 -> J  ro | 43 -> J  co
//44 -> Q  tep | 45 -> Q  bich | 46 -> Q  ro | 47 -> Q  co
//48 -> K  tep | 49 -> K  bich | 50 -> K  ro | 51 -> K  co

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_ARR 100
#define MAX_STRING 256

int *player1, *player2, *player3, *player4;
char cards[52][MAX_STRING] = {"A tep", "A bich", "A ro", "A co",
                                "2 tep", "2 bich", "2 ro", "2 co",
                                "3 tep", "3 bich", "3 ro", "3 co",
                                "4 tep", "4 bich", "4 ro", "4 co",
                                "5 tep", "5 bich", "5 ro", "5 co",
                                "6 tep", "6 bich", "6 ro", "6 co",
                                "7 tep", "7 bich", "7 ro", "7 co",
                                "8 tep", "8 bich", "8 ro", "8 co",
                                "9 tep", "9 bich", "9 ro", "9 co",
                                "10 tep", "10 bich", "10 ro", "10 co",
                                "J tep", "J bich", "J ro", "J co",
                                "Q tep", "Q bich", "Q ro", "Q co",
                                "K tep", "K bich", "K ro", "K co"};

int player5[MAX_ARR] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

int cmpfunc (const void * a, const void * b);
void chiaBai(int* player1, int* player2, int* player3, int* player4);
void printBai(int* player);
void printTuQuy(int* player, int index);

void main() {
    printf("Chuong trinh chia bai cho 4 nguoi!\n");
    player1 = (int*)malloc(sizeof(int) * MAX_ARR);
    player2 = (int*)malloc(sizeof(int) * MAX_ARR);
    player3 = (int*)malloc(sizeof(int) * MAX_ARR);
    player4 = (int*)malloc(sizeof(int) * MAX_ARR);

    //Chia bai cho 4 nguoi
    chiaBai(player1, player2, player3, player4);

    //Xep lai bai cho 4 nguoi
    qsort(player1, 13, sizeof(int), cmpfunc);
    qsort(player2, 13, sizeof(int), cmpfunc);
    qsort(player3, 13, sizeof(int), cmpfunc);
    qsort(player4, 13, sizeof(int), cmpfunc);

    //Check tu quy bai nguoi 1
    printf("--------------------------------------------------------------------------------------------------------\n");
    printBai(player1);
    printTuQuy(player1, 1);

    //Check tu quy bai nguoi 2
    printf("--------------------------------------------------------------------------------------------------------\n");
    printBai(player2);
    printTuQuy(player2, 2);

    //Check tu quy bai nguoi 3
    printf("--------------------------------------------------------------------------------------------------------\n");
    printBai(player3);
    printTuQuy(player3, 3);

    //Check tu quy bai nguoi 4
    printf("--------------------------------------------------------------------------------------------------------\n");
    printBai(player4);
    printTuQuy(player4, 4);

    // //Check tu quy bai nguoi 5
    // printf("--------------------------------------------------------------------------------------------------------\n");
    // printBai(player5);
    // printTuQuy(player5, 5);

    free(player1);
    free(player2);
    free(player3);
    free(player4);
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void chiaBai(int* player1, int* player2, int* player3, int* player4) {
    bool checkBai[13][4] = {false};
    int card, dem_chia_bai = 0;

    srand(time(0));
    do {
        //Chia bai cho nguoi 1
        card = rand() % 52;
        while (checkBai[card / 4][card % 4]) {
            card++;
            if (card >= 52) card = 0;
        }
        checkBai[card / 4][card % 4] = true;
        *player1 = card;
        player1++;

        //Chia bai cho nguoi 2
        card = rand() % 52;
        while (checkBai[card / 4][card % 4]) {
            card++;
            if (card >= 52) card = 0;
        }
        checkBai[card / 4][card % 4] = true;
        *player2 = card;
        player2++;

        //Chia bai cho nguoi 3
        card = rand() % 52;
        while (checkBai[card / 4][card % 4]) {
            card++;
            if (card >= 52) card = 0;
        }
        checkBai[card / 4][card % 4] = true;
        *player3 = card;
        player3++;

        //Chia bai cho nguoi 4
        card = rand() % 52;
        while (checkBai[card / 4][card % 4]) {
            card++;
            if (card >= 52) card = 0;
        }
        checkBai[card / 4][card % 4] = true;
        *player4 = card;
        player4++;

        dem_chia_bai++;
    } while (dem_chia_bai < 13);
}

void printBai(int* player){
	int i;
    for (i = 0; i < 13; i++) printf("%s | ", cards[player[i]]);
    printf("\n");
}

void printTuQuy(int* player, int index) {
    bool checkTuQuy, checkBai = false;

    printf("Kiem tra bai nguoi choi %d!\n", index);
    int i;
    for (i = 0; i < 13; i++)
    if (player[i] % 4 == 0) {
        checkTuQuy = true;
        int j = i;

        do {
            if (player[j] + 1 != player[j + 1]) checkTuQuy = false;
            j++;
        } while (checkTuQuy && j - i < 3);

        if (checkTuQuy) {
            checkBai = true;
            int card = player[i] / 4;
            switch (card)
            {
            case 0:
                printf("Tu quy A!\n");
                break;
            case 1:
                printf("Tu quy 2!\n");
                break;
            case 2:
                printf("Tu quy 3!\n");
                break;
            case 3:
                printf("Tu quy 4!\n");
                break;
            case 4:
                printf("Tu quy 5!\n");
                break;
            case 5:
                printf("Tu quy 6!\n");
                break;
            case 6:
                printf("Tu quy 7!\n");
                break;
            case 7:
                printf("Tu quy 8!\n");
                break;
            case 8:
                printf("Tu quy 9!\n");
                break;
            case 9:
                printf("Tu quy 10!\n");
                break;
            case 10:
                printf("Tu quy J!\n");
                break;
            case 11:
                printf("Tu quy Q!\n");
                break;
            default:
                printf("Tu quy K!\n");
                break;
            }
        }
        i = j;
    }
    if (!checkBai) printf("Nguoi choi khong co tu quy nao!\n");
}
