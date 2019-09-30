d = {x:list(input()) for x in "abc"}

s="a"

while d[s]:
    s=d[s].pop(0)


print(s.upper())