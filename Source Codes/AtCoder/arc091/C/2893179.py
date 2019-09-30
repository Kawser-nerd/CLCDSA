N,A,B = list(map(int,input().split()))
ans = []
if N >= A + B - 1 and N <= A *B:
    for i in range(A):
        ans.append(str(N - A +1 + i))
        for j in range(B-1):
            if i * (B -1 ) + (B -1 -j) > N - A + B:
              break
            elif i * (B-1) + (B -1 - j ) >= N - A + 1:
                continue
            #print(i * (B-1) + (B-1 -j))
            ans.append(str(i * (B-1) + (B-1 - j )))
else:
    ans = ["-1"] 
print(" ".join(ans))