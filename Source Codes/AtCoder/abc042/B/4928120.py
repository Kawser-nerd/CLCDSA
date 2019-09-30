n, _ = [int(_) for _ in input().split()]
words = []
for _ in range(n):
    words.append(input())
print("".join(sorted(words)))