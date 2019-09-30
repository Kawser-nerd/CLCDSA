n=int(input())
l=list(map(int,input().split()))
l.sort(reverse=True)

print(sum(l[1:2*n:2]))