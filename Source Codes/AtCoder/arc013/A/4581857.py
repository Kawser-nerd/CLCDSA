b = list(map(int, input().split()))
p, q, r = map(int, input().split())
net = [0 for _ in range(6)]
w = [p, p, q, q, r, r]
d = [q, r, p, r, p, q]
h = [r, q, r, p, q, p]
for i in range(6):
  net[i] = (b[0]//w[i])*(b[1]//d[i])*(b[2]//h[i])
print(max(net))