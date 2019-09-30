N = int(input())
ans = 0
memo = [0 for i in range(9)]
for i in range(N) :
    l = input()
    for j in range(9) :
        if (l[j] != "o") or (i == (N-1)) :
            ans += memo[j]
            memo[j] = 0
        else :
            memo[j] = 1
    ans += l.count("x")
print(ans)