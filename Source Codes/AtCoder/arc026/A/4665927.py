N,A,B = map(int,input().split())
t = 0
if N >= 5:t = (N-5) * A + 5 * B
else:t = N * B
print(t)