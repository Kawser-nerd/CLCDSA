N =int(input())
AB=[[str(j) for j in input().split()] for i in range(N)]
M=int(input())
CD=[[str(j) for j in input().split()] for i in range(M)]
ans = 0
for i in AB:
    if ans < AB.count(i) -CD.count(i) :
        ans = AB.count(i) -CD.count(i)
print(ans)