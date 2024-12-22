資料結構第四次程式作業 （聖誕快樂 OuO）
姓名 : 盧昱安
學號 : 41247001S

作業在 Linux 環境下開發，故附上 makefile

功能：
    完成了作業所有的要求且使用 adjacent list 實作
    且有通過範例測資以及自己想的所有測資

重點 function 介紹：
    所有的 function 幾乎都是寫在 adj_list.h
    main 只作為 IO 的檔案

    add_edge : 將新的邊放到 adjacent list
    print_edge : 作為 debug 使用，輸出所有的 adjacent list
    free_graph : 最後作為釋放記憶體使用
    count_groups : 計算總共有幾組，使用的是 BFS + 紀錄 visited
    count_atLeast : 透過 O(2^N * N) 窮舉所有可能性，計算出最少需要打開幾個扣環
    isAvailible : 作為 count_atLeast 的子 function，判斷是否可以達成目標
                同時也作為第三小題去判斷解開特定扣環能不能達成目標

    main.c 中有清楚記錄整個 IO 和這些 function 的使用
        可以看到程式架構十分清晰且簡單

範例測資全部通過
自訂測資1 : 
12 15
12 1
11 1
1 3
1 2
1 4
2 3
3 4
2 4
3 5
5 6
5 7
6 7
7 8
8 9
9 10
1 3 7
Output : 
1
3
No

Test #2:
13 15
12 1
11 1
1 3
1 2
1 4
2 3
3 4
2 4
3 5
5 6
5 7
6 7
7 8
8 9
9 10
1 3 7 11 12
Output :
2
3
Yes



