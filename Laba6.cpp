/*********************************************************
* Автор:   Воронков.А.А                                  *
* Дата:    30.10.2023                                    *
* Название: Работа с файлами, вариант 4                  * 
* https://onlinegdb.com/HM_I5gsgh                        *
**********************************************************/
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
 
struct Cube {  
    double size;
    char color[20];
    int id;
};  
 
int main() {  
    const int MAX_SIZE = 100;
    Cube cubes[MAX_SIZE];
    double total_volume = 0;  
    char UserColor[20];
    
    printf("Please, chose a color - ");
    scanf("%s", UserColor);
 
    FILE* fin = fopen("CubeInfo.txt", "r");
 
    if (!fin) {
        printf("File can't be opened!\n");  
        return -1;  
    }
    
    int CubeNumber = 0;   
  
    while (fscanf(fin, "%lf %s %d", &cubes[CubeNumber].size, cubes[CubeNumber].color, &cubes[CubeNumber].id) != EOF) { 
        if (strcmp(cubes[CubeNumber].color, UserColor) == 0) {
            printf( "%s %lf %d\n", cubes[CubeNumber].color, cubes[CubeNumber].size, cubes[CubeNumber].id);
            total_volume += cubes[CubeNumber].size * cubes[CubeNumber].size * cubes[CubeNumber].size;
        }
        ++CubeNumber;
    }
   
    fclose(fin);   
   
    printf("Total volume of cubes: %.2lf cm^3\n", total_volume);    
   
    return 0;    
}
