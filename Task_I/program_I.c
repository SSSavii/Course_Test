#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int x;
    int y;
} Castle;

typedef struct {
    char type; 
    int value; 
} Line;

int main() {
    int n;
    scanf("%d", &n); 

    Castle* castles = malloc((n) * sizeof(Castle));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &castles[i].x, &castles[i].y); 
    }

   
    Line* lines = malloc((n - 1) * sizeof(Line));
    int index = 0;

    
    if (castles[0].y != castles[1].y) {
        lines[index].type = 'x';
        lines[index].value = castles[0].x;
        index++;
    }
    
    else if (castles[0].x != castles[1].x) {
        lines[index].type = 'y';
        lines[index].value = castles[0].y;
        index++;
    }

    
    for (int i = 2; i < n; i++) {
       
        if (castles[0].y == castles[i].y) {
            lines[index].type = 'x';
            lines[index].value = castles[i].x;
            index++;
        }
       
        else if (castles[0].x == castles[i].x) {
            lines[index].type = 'y';
            lines[index].value = castles[i].y;
            index++;
        }
    }

    
    printf("%d\n", index);
    for (int i = 0; i < index; i++) {
        printf("%c %d\n", lines[i].type, lines[i].value);
    }

    free(lines); 

    return 0;
}