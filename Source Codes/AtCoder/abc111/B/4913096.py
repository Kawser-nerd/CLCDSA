N = input()
n = [int(i) for i in N]
N = int(N)
a = n[0]
b = len(n)
c = 0

for i in range(b):
    c += a*10**i

if N <= c:
    print(c)
else:
    c = [str(int(i)+1) for i in str(c)]
    print(''.join(c))