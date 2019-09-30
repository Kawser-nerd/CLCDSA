N = int(input())
di = set()
w = [input() for _ in range(N)]
new_w_set = set()
new_w_set.add(w[0])
lastc = w[0][-1]
for i in range(1,N):
    if (not w[i] in new_w_set) and (w[i][0] == lastc):
        lastc = w[i][-1]
        new_w_set.add(w[i])
        #print(w[i])
        #print(new_w_set)
    else:
        print('WIN' if i%2!=0 else 'LOSE')
        break
else:print('DRAW')