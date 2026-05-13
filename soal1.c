/**
 * EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 * Modul             : 5
 * Hari dan Tanggal  : Rabu, 13 Mei 2026
 * Nama (NIM)        : Hezkiel Tarutung Harianja (13224010)
 * Nama File         : soal1_modul5.c
 * Deskripsi         : Program Kunci Gerbang Minecraft
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rec_kurung(int n, int jumlah_bukakurung, int jumlah_tutupkurung, char* current_str, int index, int* total) {
    if (index == 2*n) {
        current_str[index] = '\0'; 
        printf("%s\n", current_str);  
        (*total)++;
        return;
    }
    if (jumlah_bukakurung < n) {
        current_str[index] = '(';
        rec_kurung(n, jumlah_bukakurung+1, jumlah_tutupkurung, current_str, index+1, total);
    }
    if (jumlah_tutupkurung < jumlah_bukakurung) {
        current_str[index] = ')';
        rec_kurung(n, jumlah_bukakurung, jumlah_tutupkurung+1, current_str, index+1, total);
    }
}

int main() {
    int n;
    int total = 0;
    scanf("%d", &n);
    char* current_str = (char*)malloc((2*n + 1) * sizeof(char));
    rec_kurung(n, 0, 0, current_str, 0, &total);
    printf("TOTAL %d\n", total); 
    free(current_str);
    return 0;
}

//Reference : 
//1. https://www.geeksforgeeks.org/c/c-recursion/
//2. https://www.geeksforgeeks.org/c/function-pointer-in-c/
//3. https://www.geeksforgeeks.org/c/c-program-for-binary-search-tree/
//4. https://www.geeksforgeeks.org/c/types-of-recursion-in-c/
//5. https://stackoverflow.com/questions/40348133/recursive-tree-function
