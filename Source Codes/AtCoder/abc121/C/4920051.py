import itertools

N, M  = tuple([int(x) for x in input().split(' ')])
AB = [tuple([int(x) for x in input().split(' ')]) for i in range(N)]

ans = 0
count = 0
for a, b in sorted(AB, key=lambda x: x[0]):
        if M - count <= b:
                ans +=  (M - count) * a
                break
        else:
                count += b
                ans += a * b

print(ans)