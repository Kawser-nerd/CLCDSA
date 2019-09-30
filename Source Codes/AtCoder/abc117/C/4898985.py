n,m = [int(i) for i in input().split()]
x = [int(i) for i in input().split()]

x.sort()

distance = [x[i+1]-x[i] for i in range(len(x)-1)]
distance.sort(reverse=True)

ans = sum(distance[n-1:])
print(ans)