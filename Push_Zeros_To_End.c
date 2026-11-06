#include <stdio.h>
#include <stdlib.h>

void pushZerosToEnd(int n, int* arr) {
    //===== Write Your Logic Here =====
    int write = 0;

    for(int read = 0; read < n ; read++){
        if(arr[read] != 0){
            int temp = arr[write];
            arr[write] = arr[read];
            arr[read] = temp;
            write++;
        }
    }

}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    pushZerosToEnd(n, arr);

    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", arr[i]);
    }

    free(arr);
    return 0;
}