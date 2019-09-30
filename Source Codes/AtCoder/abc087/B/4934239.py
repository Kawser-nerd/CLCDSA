A = int(input())
B = int(input())
C = int(input())
X = int(input())
counter = 0
for a in range(A+1):
    for b in range(B+1):
        for c in range(C+1):
            if 500 * a + 100 * b + 50 * c == X:
                counter += 1
print(counter)