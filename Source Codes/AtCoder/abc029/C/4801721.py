n = int(input())

l = []
def f(s):
    global l
    if len(s) == n:
        l.append(s)
        return 0
    
    f(s+"a")
    f(s+"b")
    f(s+"c")

f("")

for x in l:
    print(x)