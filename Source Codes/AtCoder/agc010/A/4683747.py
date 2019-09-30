N = int(input())
A_list = list(map(int, input().split()))
a = sum(A_list)
if a%2 == 0:
	print("YES")
else:
	print("NO")