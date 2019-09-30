N = int(input())
A = list(map(int, input().split()))

A.sort(reverse=True)

dic = {}
for i in range(N):
    if A[i] in dic:
        dic[A[i]] += 1
    else:
        dic[A[i]] = 1
 
res = 0
for i in range(N):
    if A[i] in dic:
        n = 0
        tmp = A[i]
        while True:
            if tmp == 0:
                break
            tmp //= 2
            n += 1

        if 2 ** n - A[i] in dic:
            if 2 ** n - A[i] == A[i] and dic[A[i]] < 2:
                pass
            else:
                res += 1
                dic[2 ** n - A[i]] -= 1
                if dic[2 ** n - A[i]] == 0:
                    dic.pop(2 ** n - A[i])

        dic[A[i]] -= 1
        if dic[A[i]] == 0:
            dic.pop(A[i])
        
print(res)