l = list(map(int, input().split()))
i = sum([i * 2 for i in list(set(l))])
print(int(i - sum(l)) if len(list(set(l))) == 2 else int(l[0]))