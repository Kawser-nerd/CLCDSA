c = [list(map(str,input().split())) for _ in range(4)]

c[3].reverse()
c[2].reverse()
c[1].reverse()
c[0].reverse()

print(" ".join(c[3]))
print(" ".join(c[2]))
print(" ".join(c[1]))
print(" ".join(c[0]))