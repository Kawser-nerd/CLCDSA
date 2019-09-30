n = int(input())
s = list(input())
box = []
alfa = [chr(ord('a') + i) for i in range(26)]
ans = 1

for hoge in alfa:
    if hoge in s:
        box.append([hoge, s.count(hoge)])

for hoge in range(len(box)):
    ans *= box[hoge][1] + 1

print((ans - 1) % (10 ** 9 + 7))