
arr = [
   [0 , 6 , 99999 , 7 , 99999],
   [99999 , 0 , 5 , -8 , -4],
   [99999 , -2 , 0 , 99999 , 99999],
   [99999 , 99999 , -3 , 0 , 9],
   [2 , 99999 , 7 , 99999 , 0],
]

dp = [
    [
        [
            99999 for k in range(5)
        ] for j in range(5)
    ] for i in range(5)
]

dp.append(arr)

for k in range(5):
    for i in range(5):
        for j in range(5):
            dp[k][i][j] = min(dp[k-1][i][j] , dp[k-1][i][k] + dp[k-1][k][j])


for i in range(5):
    for j in range(5):
        print(dp[i][j])
    print()