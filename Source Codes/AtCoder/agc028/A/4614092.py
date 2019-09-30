import fractions
 
N, M = list(map(int, input().split()))
S = input()
T = input()
 
def lcm(a, b):
	return a * b // fractions.gcd (a, b)
 
ans = lcm(N, M)
 
width = fractions.gcd(N, M)
 
for i in range(width):
    if S[int(N/width) * i] != T[int(M/width) * i]:
        ans = -1
        break
 
print(ans)