N, T = map(int, input().split())
start = int(input())
end = start + T
total = T
for i in range(1,N):
    start = int(input())
    if start < end:
        total += T - (end - start)
    else:
        total += T
    end = start + T
print(total)