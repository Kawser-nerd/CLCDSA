import sys
input = sys.stdin.readline

n = int(input())
max_dist = 0
index = 0
for i in range(1, n+1):
    print('? {0} {1}'.format(1, i))
    sys.stdout.flush()
    dist = int(input())
    if dist > max_dist:
        max_dist = dist
        index = i

ans = 0
for i in range(1, n+1):
    print('? {0} {1}'.format(index, i))
    sys.stdout.flush()
    dist = int(input())
    if dist > ans:
        ans = dist

print('! {0}'.format(ans))