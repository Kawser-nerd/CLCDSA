n = list(map(int, input().split()))
if n[2] != n[0] != n[1]: print(n[0])
if n[0] != n[1] != n[2]: print(n[1])
if n[1] != n[2] != n[0]: print(n[2])