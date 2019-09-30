Num = [int(n) for n in input().rstrip().split()]

Str = [input().rstrip() for _ in range(Num[0])]

print("".join(sorted(Str)))