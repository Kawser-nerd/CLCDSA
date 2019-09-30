N, VA, VB, L = map(int, input().split(" "))

d = L
for _ in range(N):
    d = VB*(d/VA)
print(d)