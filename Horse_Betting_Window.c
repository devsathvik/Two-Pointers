#include <stdio.h>
#include <stdlib.h>

int longestAffordableRun(int n, long long k, long long* cost) {
    //===== Write Your Logic Here =====
    int left = 0 ; int best = 0;
    long long sum = 0;

    for(int right = 0 ; right < n ; right++){
        sum += cost[right];
    

    while(sum >= k && left <= right){
        sum -= cost[left];
        left++;
    }

    int len = right - left + 1;
    if(len > best){
        best = len;
    }
    }
    return best;

}

int main() {
    int n;
    long long k;
    if (scanf("%d %lld", &n, &k) != 2) return 0;

    long long* cost = (long long*)malloc(n * sizeof(long long));
    for (int i = 0; i < n; i++) scanf("%lld", &cost[i]);

    printf("%d\n", longestAffordableRun(n, k, cost));

    free(cost);
    return 0;
}