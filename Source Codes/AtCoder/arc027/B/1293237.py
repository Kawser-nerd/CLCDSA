import string
beet = string.digits + string.ascii_uppercase

n = int(input())
s = input()
t = input()

data = [-1] * 36

def find(x):
    global data
    if data[x] < 0:
        return x
    data[x] = find(data[x])
    return data[x]

def unite(x, y):
    global data
    x = find(x)
    y = find(y)
    if x == y:
        return
    data[x] += data[y]
    data[y] = x
    
for i in range(n):
    a = beet.find(s[i])
    b = beet.find(t[i])
    unite(a, b)

solid = [0] * 36
solid[find(beet.find(s[0]))] = 2
solid[find(beet.find(t[0]))] = 2
for i in range(10):
    solid[find(i)] = 1
ret = 1
for i in range(10, 36):
    if s.find(beet[i]) == -1 and t.find(beet[i]) == -1:
        continue
    if solid[find(i)] == 1:
        continue
    if solid[find(i)] == 2:
       ret *= 9
    else:
       ret *= 10
    solid[find(i)] = 1
       
print(ret)