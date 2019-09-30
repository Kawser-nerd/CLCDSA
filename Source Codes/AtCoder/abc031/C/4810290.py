n = int(input())
a = list(map(int, input().split()))

odd = [0] * (n+1)
even = [0] * (n+1)

for i in range(n):
    if i % 2 == 0:
        odd[i+1] = odd[i] + a[i]
        even[i+1] = even[i]
    else:
        odd[i+1] = odd[i]
        even[i+1] = even[i] + a[i]

#print(odd)
#print(even)

B = -100000
ans = B

for i in range(n):
    p = B
    c = -1
    for j in range(i):
        if j % 2 == 0:
            temp = even[i+1] - even[j]
            if temp > p:
                p = temp
                c = j
        else:
            temp = odd[i+1] - odd[j]
            if temp > p:
                p = temp
                c = j
        #print(i, j, temp)
    for j in range(i+1, n):
        if i % 2 == 0:
            temp = even[j+1] - even[i]
            if temp > p:
                p = temp
                c = j
        else:
            temp = odd[j+1] - odd[i]
            if temp > p:
                p = temp
                c = j
        #print(i, j, temp)
    if c < i:
        if c % 2 == 1:
            temp = even[i+1] - even[c]
        else:
            temp = odd[i+1] - odd[c]
    else:
        if i % 2 == 1:
            temp = even[c+1] - even[i]
        else:
            temp = odd[c+1] - odd[i]
    #print('a ', temp, i, c)
    if temp > ans:
        ans = temp

print(ans)