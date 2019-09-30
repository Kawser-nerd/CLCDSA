def swap(a,b,arr):
    tmp = arr[a]
    arr[a] = arr[b]
    arr[b] = tmp

N = int(input())
P = [0] + list(map(int,input().split()))
cnt = 0
for i in range(1,N+1):
    if P[i] == i:
        swap(i,i+1,P) if i<N else 0
        cnt += 1 
print(cnt)