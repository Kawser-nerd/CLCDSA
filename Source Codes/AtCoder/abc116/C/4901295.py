N = int(input())
h = [int(i) for i in input().split()]
h.append(0)

cnt = 0
for H in range(max(h)):
    #print(h)
    for i in range(N):
        if h[i] >0:
            h[i] -= 1
            if h[i+1] == 0:
                cnt +=1

print(cnt)