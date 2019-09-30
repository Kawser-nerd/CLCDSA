A, B = map(int, input().rstrip().split())
counter = 0
for i in range(A,B+1):
    now = i
    number = 0
    for j in range(5):
        tmp = now % 10
        number += tmp * 10**(4-j)
        now //= 10
    if number == i:
        counter += 1
print(counter)