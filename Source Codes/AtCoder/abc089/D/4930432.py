h,w,d = map(int,input().split())
a = [list(map(int,input().split())) for _ in range(h)]
q = int(input())
l = [list(map(int,input().split())) for _ in range(q)]
dic = {}
for i in range(len(a)):
    for j in range(len(a[i])):
        dic[a[i][j]] = (i,j)
sum = [0]*(h*w+1)
for i in range(d+1,h*w+1):
    sum[i] = sum[i-d]+abs(dic[i][0]-dic[i-d][0])+abs(dic[i][1]-dic[i-d][1])
for l_ in l:
    print(sum[l_[1]]-sum[l_[0]])