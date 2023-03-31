#https://lightoj.com/contest/esu-final-pacise/arena/problem/3806
one = input()
two = input()
dp = [[0 for j in range(len(two)+1)] for i in range(len(one)+1)]
for i in range(len(one)-1,-1,-1):
    for j in range(len(two)-1,-1,-1):
        if one[i] == two[j]:
            dp[i][j] = 1 + dp[i + 1][j+1]
        else:
            dp[i][j] = max(dp[i][j+1], dp[i+1][j])

print(dp)
print(dp[0][0])


#if this doesnt work its because i refined it from this correct code:

# one = input()
# two = input()
# dp = [[0 for j in range(len(two))] for i in range(len(one)+1)]
# for i in range(len(one)-1,-1,-1):
#     for j in range(len(two)-1,-1,-1):
#         if one[i] == two[j]:
#             # print("x")
#             # print(i)
#             # print(j)
#             if j!=len(two)-1:
#                 dp[i][j] = 1 + dp[i + 1][j+1]
#             else:
#                 dp[i][j] = 1+dp[i+1][j]
#         else:
#             if j!=len(two)-1:
#                 dp[i][j] = max(dp[i][j+1], dp[i+1][j])
#             else:
#                 dp[i][j] = max(dp[i][j], dp[i+1][j])

#             # print("x")
#             # print(i)
#             # print(j)
# else:
#     print(dp[0][0])