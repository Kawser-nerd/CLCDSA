import sys
line1, line2 = [sys.stdin.readline() for i in range(2)]
components = [int(i) for i in line2.strip().split()]
count = 0
while all([i % 2 == 0 for i in components]):
    count += 1
    components = [i//2 for i in components]
else:
    print(count)