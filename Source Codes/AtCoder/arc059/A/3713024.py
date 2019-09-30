a = int(input())
ar = list(map(int,input().split(" ")))
br = []
for i in range(min(ar),max(ar)+1):
    count = 0
    for r in ar:
        count += (i - r) ** 2
    br.append(count)
print(min(br))