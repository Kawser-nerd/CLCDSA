H, W = map(int, input().split())
a = [[0] * W for _ in range(H)]

for h in range(H):
    a[h] = [inp for inp in input()]
#print(a)
check = [[0] * W for _ in range(H)]

for h in range(H):
    for w in range(W):
        if a[h][w] == '#':
	        check[h][w] = 1
#print(a)
#print(check)
final_w = [0] * W
for h in range(H):
    final_w = [final_w[w] + check[h][w] for w in range(W)]
    
final_h = [0] * H
for w in range(W):
    final_h = [final_h[h] + check[h][w] for h in range(H)]
  
#print(final)
for h in range(H):
    res = ''
    for w in range(W):
        if final_w[w] >= 1 and final_h[h] >= 1:
            res += a[h][w]
    print(res + '\n')