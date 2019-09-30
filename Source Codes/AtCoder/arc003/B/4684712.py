N = int(input())
s = [input() for _ in range(N)]

s.sort(key=lambda x:x[::-1])

for w in s:
    print(w)