n = int(input())
a = list(map(int, input().split()))
if([1 for i in range(n) if a[i] % 2 == 1].count(1) % 2 == 0) : print("YES")
else : print("NO")