typedef struct _adj_list {
    int v1 , v2;
    struct _adj_list *next;
} adj_list;

void add_edge(adj_list ** graph ,int v1 ,int v2);
void print_edge(adj_list ** graph , int n);
void free_graph(adj_list ** graph , int n);
int count_groups(adj_list ** graph , int n);
int count_atLeast(adj_list ** graph , int n);
int isAvailible(adj_list ** graph , int n , int free[]);

void add_edge(adj_list ** graph ,int v1 ,int v2){

    adj_list *new_edge = (adj_list*)malloc(sizeof(adj_list));
    new_edge->v1 = v1;
    new_edge->v2 = v2;
    new_edge->next = NULL;

    if(!graph[v1]) graph[v1] = new_edge;
    else{

        adj_list *temp = graph[v1];

        while(temp->next) temp = temp->next;
        temp->next = new_edge;

    }

    new_edge = (adj_list*)malloc(sizeof(adj_list));
    new_edge->v1 = v1;
    new_edge->v2 = v2;
    new_edge->next = NULL;

    if(!graph[v2]) graph[v2] = new_edge;
    else{

        adj_list *temp = graph[v1];

        while(temp->next) temp = temp->next;
        temp->next = new_edge;

    }

}

void print_edge(adj_list ** graph , int n){

    for(int i = 1 ; i < n + 1 ; i++){
        adj_list *temp = graph[i];
        printf("%d -> ",i);
        while(temp){
            printf("%d %d ",temp->v1 , temp->v2);
            temp = temp->next;
        }
        printf("\n");
    }

}

void free_graph(adj_list ** graph , int n){

    for(int i = 1 ; i < n + 1 ; i++){
        adj_list *temp = graph[i];
        while(temp){
            adj_list *temp2 = temp;
            temp = temp->next;
            free(temp2);
        }
    }
}

int count_groups(adj_list ** graph , int n){

    int cnt = 0;
    int appear[n+1];

    for(int i = 1 ; i < n + 1 ; i++) appear[i] = 0;

    for(int i = 1 ; i < n + 1 ; i++){

        adj_list *temp = graph[i];
        int does_appear = 0;
        int this_round_appear[26] = {0};
        while(temp){
            if(!this_round_appear[temp->v1]) does_appear += appear[temp->v1];
            if(!this_round_appear[temp->v2]) does_appear += appear[temp->v2];
            appear[temp->v1] = 1;
            appear[temp->v2] = 1;
            this_round_appear[temp->v1] = 1;
            this_round_appear[temp->v2] = 1;
            temp = temp->next;
        }

        if(!does_appear) cnt++;

    }

    return cnt;

}



int count_atLeast(adj_list ** graph , int n){

    int possible = n;

    for(int i = 0 ; i < ((int)pow(2 , n)); i++){

        int free[n+1] , from[n+1];
        int free_cnt = 0;
        for(int j = 1 ; j < n + 1 ; j++){
            from[j] = -1;
            if((i & (1 << (j-1)))){
                free[j] = 1;
                free_cnt += 1;
            }
            else free[j] = 0;
        }
        if(isAvailible(graph , n , free) == 0)
        possible = possible > free_cnt ? free_cnt : possible;
        //for(int j=1;j<=n;j++) printf("%d ",free[j]);
        //printf("\n");
    }

    return possible;


}

int isAvailible(adj_list ** graph , int n , int free[]){

    int cnt = 0;
    int cycle = 0;
    int leftandright = 0;
    int from[n+1];
    for(int j=1;j<=n;j++) from[j] = -1;

    for(int j = 1 ; j < n + 1 && !cycle ; j++){
        if(free[j]) continue;
        if(from[j] == -1) cnt += 1;
        adj_list *temp = graph[j];
        int pointer_length = 0;
        while(temp){
            
            if(free[temp->v1] || free[temp->v2]){
                temp = temp->next;
            }
            else{
                pointer_length += 1;
                
                if(from[temp->v2] == from[temp->v1] && from[temp->v1] != -1){
                    cycle = 1;
                    break;
                }
                if(from[j] != -1){
                    if(temp->v1 == j){
                        from[temp->v2] = from[j];
                    }
                    else{
                        from[temp->v1] = from[j];
                    }
                }
                else{
                    if(temp->v1 == j){
                        from[temp->v2] = j;
                    }
                    else{
                        from[temp->v1] = j;
                    }
                }
                temp = temp->next;
            }
        }
        if(pointer_length > 2) cycle = 1;
        if(pointer_length == 2) leftandright += 1;
        if(leftandright > 1) cycle = 1;
        
    }

    return cycle;
}