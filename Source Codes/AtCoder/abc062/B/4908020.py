H, W = map(int, input().split())
a = ["" for i in range(H)]
for i in range(H):
	a[i] = input()

print("#"*(W+2))
for i in range(H):
	print("#" + a[i] + "#")
print("#"*(W+2))