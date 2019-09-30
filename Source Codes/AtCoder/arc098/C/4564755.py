N, K, Q = map(int, input().split())
A = [int(a) for a in input().split()]

minSub = 10**10
for a in A:
    start = False
    end = 0
    subarray, newarray = [], []
    for i in range(N):
        if A[i] >= a:
            newarray.append(A[i])
            start = True
        else:
            if start:
                start = False
                if len(newarray) >= K:
                    newarray.sort()
                    for j in range(len(newarray) - K + 1):
                        subarray.append(newarray[j])
                newarray = []
    if len(newarray) >= K:
        newarray.sort()
        for j in range(len(newarray) - K + 1):
            subarray.append(newarray[j])
    if len(subarray) >= Q: 
        subarray.sort()
        minSub = min(minSub, subarray[Q-1] - a)
print(minSub)