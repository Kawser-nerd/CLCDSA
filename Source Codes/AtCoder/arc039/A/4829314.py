A, B = input().split()

if A[0] != '9':
    x = int('9' + A[1:]) - int(B)
elif A[1] != '9':
    x = int(A[0] + '9' + A[2]) - int(B)
elif A[2] != '9':
    x = int(A[:2] + '9') - int(B)
else:
    x = int(A) - int(B)
    
if B[0] != '1':
    y = int(A) - int('1' + B[1:])
elif B[1] != '0':
    y = int(A) - int(B[0] + '0' + B[2])
elif B[2] != '0':
    y = int(A) - int(B[:2] + '0')
else:
    y = int(A) - int(B)

print(max(x, y))