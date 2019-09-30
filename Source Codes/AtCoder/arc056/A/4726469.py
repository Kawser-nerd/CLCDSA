A,B,K,L=map(int,input().split())
s1 = K * A
s2 = (K//L) * B + (K%L)*A
s3 = (K//L + 1) * B
print(min(s1,s2,s3))