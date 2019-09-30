R, C, D = map(int, input().split(" "))
A = [list(map(int, input().split(" "))) for _ in range(R)]

max_num = 0
for y in range(min(R, D+1)):
    # print(D-y+1, C, y)
    l = A[y][D%2^y%2:min(C, D-y+1):2]
    # print(A[y][y%2:min(C, D-y+1)])
    # print(l)
    if l:
        max_num = max(max_num, max(l))

print(max_num)