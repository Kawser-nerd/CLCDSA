import sys
mod = 10**9 +7
N = int(input())
S1 = input()
S2 = input()

H = ''
for i in range(N):
    if S1[i] == S2[i]:
        H += 't'
    else:
        H += 'Y'
H = H.replace('YY','y')
K = len(H)
if K == 1 :
    print(3*N)
    sys.exit()
if H[0] == 'y':
    ans = 6
    prev = 'y'
else:
    ans = 3
    prev = 't'
for i in H[1:]:
    if prev == 'y':
        if i == 'y':
            ans = ans*3 %mod
    else:
        ans = ans*2 %mod
    prev = i
print(ans%mod)