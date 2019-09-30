A, B = input().split()
a = max(eval('9' + A[1:]), eval(A[0] + '9' + A[2]), eval(A[:2] + '9'))
b = min(eval('1' + B[1:]), eval(B[0] + '0' + B[2]), eval(B[:2] + '0'))
print(max(a-eval(B), eval(A)-b))