H, W = map(int, input().split())
N = int(input())
A = list(map(int, input().split()))
res = [[-1 for _ in range(W)] for _ in range(H)]
tmp = []
for i in range(N):
    for j in range(A[i]):
        tmp.append(i + 1)
        
for i in range(H):
    result = ''
    for j in range(W):
        if i%2 == 0:
            result = result + str(tmp[W * i + j])
            if j != W - 1:
                result = result + ' '
        else:
            result =  str(tmp[W * i + j]) + result
            if j != W - 1:
                result = ' ' + result 
            
    print(result)