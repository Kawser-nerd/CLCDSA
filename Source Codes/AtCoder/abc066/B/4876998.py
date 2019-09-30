A = input()

for i in range(len(A)):
    A = A[:-1]

    if len(A)%2==1:
        continue

    half_len = int(len(A)/2)
    if A[:half_len] == A[half_len:]:
        break

print(len(A))