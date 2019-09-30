S = input()

index_A = []
index_Z = []
for i in range(len(S)):
    if S[i] == "A" and len(index_A) == 0:
        index_A.append(i+1)
    if S[i] == "Z":
        index_Z.append(i+1)
            
print(max(index_Z) - index_A[0] + 1)