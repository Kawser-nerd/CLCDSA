def inpl():
    return list(map(int, input().split()))


S = input()

print(len(S) // 2 - S.count('p'))