input()
a = set(map(int, input().split()))
b = set(map(int, input().split()))
print(len(a & b) / len(a | b))