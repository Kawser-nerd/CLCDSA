import sys

n, = [int(x) for x in input().strip().split(" ")]
n = int(n)

As = []
for line in sys.stdin:
    a, = line.strip().split(" ")
    As.append(int(a))
#print(As)

if As[0] != 0:
    print(-1)
    sys.exit()

result = 0
for i in range(n):
    k = n-1-i
    As[k]
    if As[k] > k:
        print(-1)
        sys.exit()
    if k == n-1:
        result += As[k]
    else:
        if As[k] > As[k+1]:
            result += As[k]
        if As[k] == As[k+1]:
            result += As[k]
        if As[k] + 1 < As[k+1]:
            print(-1)
            sys.exit()
#    print(result)
print(result)