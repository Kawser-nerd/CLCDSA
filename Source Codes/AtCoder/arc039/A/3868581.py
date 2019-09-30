A,B = input().split()


ans = [(int(A)-int(B))]

ans.append(int("9" + A[1:]) - int(B))
ans.append(int(A[0] + "9" + A[2]) - int(B))
ans.append(int(A[:2] + "9") - int(B))
ans.append(int(A) - int("1" + B[1:]))
ans.append(int(A) - int(B[0] + "0" +B[2]))
ans.append(int(A) - int(B[:2] + "0"))

print(max(ans))