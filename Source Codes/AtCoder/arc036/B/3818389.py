N = int(input())
H = [int(input()) for _ in range(N)]

# H = [10**10] + H + [10**10]
# print(H)
H = [H[i+1]-H[i] for i in range(N-1)]
# print(H)
H = [H[i]<0 and 0<H[i+1] for i in range(N-2)]
# print(H)
H = [True] + H + [True]
# print(H)

# if H.count(True) < 2:
#     print(0)
#     exit()
before = None
max_size = 1
for i in range(N):
    if H[i] == False:
        continue
    if before != None:
        max_size = max(max_size, i-before+1)
    before = i

print(max_size)