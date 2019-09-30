l=[int(input()) for _ in range(3)]
s=sorted(l)[::-1]
for i in l:
    print(s.index(i)+1)