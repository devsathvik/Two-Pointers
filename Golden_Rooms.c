#include <stdio.h>
#include <stdlib.h>

void findRooms(int n, long long k, long long* coins, int* start, int* end) {
    //===== Write Your Logic Here =====
    *start = -1;
    *end = -1;
    
    int left = 0;
    long long sum = 0;

    for(int right = 0 ; right < n ; right++){

        sum += coins[right];

        while(sum > k && left <= right){
            sum -= coins[left];
            left++;
        }

        if(sum == k){
            *start = left + 1;
            *end = right + 1;
            return;
        }
    }

}

int main() {
    int n;
    long long k;
    if (scanf("%d %lld", &n, &k) != 2) return 0;

    long long* coins = (long long*)malloc(n * sizeof(long long));
    for (int i = 0; i < n; i++) scanf("%lld", &coins[i]);

    int start, end;
    findRooms(n, k, coins, &start, &end);
    printf("%d %d\n", start, end);

    free(coins);
    return 0;
}