N = int(input())

def cal(n):
    return sum(map(int, list(str(n))))

ans = []
for i in range(max(1, N - 9 * 17), N):
    if i + cal(i) == N:
        ans.append(i)

counts = len(ans)
print(counts)
if counts != 0:
    print(*ans, sep='\n')