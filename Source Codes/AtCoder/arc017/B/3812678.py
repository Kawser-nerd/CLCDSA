N, K = map(int, input().split(" "))
A = [int(input()) for _ in range(N)]

count = 0
up_count = 1
before = A[0]
for a in A[1:]+[0]:
    # print(a)
    if before < a:
        up_count += 1
    else:
        if up_count >= K:
            # print("up_count:", up_count)
            count += up_count - K + 1
        up_count = 1
    before = a

print(count)