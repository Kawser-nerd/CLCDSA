n = int(input())
list_s1 = list(str(input()))
ans = 1
list_s1.append("!")
for i in range(n):
    if i == 0:
        ans *= 3
    elif i == 1:
        ans *= 2
    else:
        if list_s1[i] == list_s1[i-1]:
            ans *= 1
        else:
            if list_s1[i-1] == list_s1[i-2]:
                if list_s1[i] != list_s1[i+1]:
                    ans *= 1
                else:
                    ans *= 3
            else:
                ans *= 2
print(ans%(10**9+7))