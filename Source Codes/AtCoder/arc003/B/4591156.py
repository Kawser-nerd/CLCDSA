n = int(input())
rec = []
for i in range(n):
    rec.append(input()[::-1])

rec = sorted(rec)
for i in range(n):
    print(rec[i][::-1])