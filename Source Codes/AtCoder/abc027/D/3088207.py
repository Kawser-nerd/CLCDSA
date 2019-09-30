A = []
x = 0
for c in input()[::-1]:
    if c == 'M':
        A.append(x)
    else:
        x += (c == '+') - (c == '-')
A.sort()
half = len(A) // 2
print(sum(A[half:]) - sum(A[:half]))