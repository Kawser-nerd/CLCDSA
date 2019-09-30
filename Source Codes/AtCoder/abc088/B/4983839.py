n = int(input())

a = []
a = list(map(int, input().split()))

b = sorted(a, reverse=True) # reverse = True???
# print(b)
# print(b[0])

alice = 0
bob = 0
for i in range(n):
    if i % 2 == 0:
        alice += b[i]
    else:
        bob += b[i]
dif = alice - bob
print(dif)