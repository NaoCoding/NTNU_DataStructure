#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "adj_list.h"

int main(){

    int n , m ;
    scanf("%d %d" , &n , &m);
    adj_list ** graph = (adj_list **)(calloc(n + 1 , sizeof(adj_list *)));
    for(int i = 0 ; i < n + 1 ; i++) graph[i] = NULL;

    for(int i = 0 ; i < m ; i++){
        int v1 , v2;
        scanf("%d %d" , &v1 , &v2);
        add_edge(graph , v1 , v2);
    }

    //print_edge(graph , n);

    printf("%d\n" , count_groups(graph , n));
    printf("%d\n" , count_atLeast(graph , n));


    char line[10001] = {0};

    int tofree[n+1];
    for(int j=1;j<=n;j++) tofree[j]=0;

    while(fgets(line, sizeof(line), stdin) == NULL || line[0] <= '0'){}

    char *token = strtok(line, " ");
        while (token != NULL) {
            tofree[atoi(token)] = 1;
            token = strtok(NULL, " ");
        }

    printf("%s\n" , (!isAvailible(graph , n , tofree) ? "Yes" : "No"));

    /*
    for(int j=1;j<=n;j++){
        printf("%d ",tofree[j]);
    }
    printf("\n");
    */

    free_graph(graph , n);  

}