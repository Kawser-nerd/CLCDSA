import bisect
N = int(input())
W = [int(input()) for l in range(N)]
box =[W[0]]
for i in range(1,N):
    if max(box)<W[i]:
        box.append(W[i])
    else:
        box[bisect.bisect_left(box,W[i])] = W[i]
print(len(box))