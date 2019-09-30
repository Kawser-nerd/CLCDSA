N = int(input())
s1 = input()
s2 = input()

ans = 1

for i in range(N) :
    if i == 0 :
        if s1[i] == s2[i] :
            ans *= 3
            state = 0
        else :
            ans *= 6
            state = 1
    else :
        if (s1[i] == s1[i-1]) and (s2[i] == s2[i-1]) :
            continue
        if s1[i] == s2[i] :
            if state == 0 :
                ans *= 2
            else :
                ans *= 1
            state = 0
        else :
            if state == 0 :
                ans *= 2
            else :
                ans *= 3
            state = 1
    ans %= 10**9+7

print(ans)