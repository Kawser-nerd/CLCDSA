n=int(input())
l=list(map(int, input().split()))
print("Yes" if max(l) < sum(l)-max(l) else "No")