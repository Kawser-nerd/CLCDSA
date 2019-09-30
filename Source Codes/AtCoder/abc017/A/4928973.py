A = input().split()
B = input().split()
C = input().split()
s1 = int(A[0])
e1 = int(A[1])
s2 = int(B[0])
e2 = int(B[1])
s3 = int(C[0])
e3 = int(C[1])
if 10 <= s1 and s2 and s3 <= 990:
    if 1 <= e1 and e2 and e3 <=10:
        if s1 % 10 == 0 and s2 % 10 == 0 and s3 % 10 ==0:
            print( int(s1 / 10 * e1 + s2 / 10 * e2 + s3 / 10 * e3) )