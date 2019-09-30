n = list(map(int, input().split()))
a = list(range(n[0], n[1]+1))
b = list(range(n[2], n[3]+1))
print(max(0, len(set(a) & set(b))-1))