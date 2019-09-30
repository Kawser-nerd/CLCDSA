n = input()
a = list(map(int, input().split()))
alice = 0
bob = 0

for i, num in enumerate(sorted(a)[::-1]):
    if i%2 == 0:
        alice += num
    else:
        bob += num

print(alice - bob)