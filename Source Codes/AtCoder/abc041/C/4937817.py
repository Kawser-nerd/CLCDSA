n=int(input())
val=list(map(int, input().split()))
key=[str(i) for i in range(1,n+1)]
d=dict(zip(key, val))
d_sorted = sorted(d.items(), key=lambda x:x[1], reverse=True)
for num, t in d_sorted:
    print(num)