n = int(input())
p = [int(input()) for i in range(n)]
sum =0

p.sort(reverse=True, key=int)

p[0] = p[0]//2
#print(p[0])
for i in range(n):
	sum += p[i]

print(sum)