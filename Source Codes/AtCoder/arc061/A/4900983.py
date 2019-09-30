S = [int(x) for x in list(input())]
ans = 0

for i in range(2**(len(S)-1)):
    dig = 0
    for j in range(len(S)-1):
        if int(i/(2**j)) % 2 == 0:
            dig += 1
        else:
            dig = 0
        ans += S[-j-2] * (10**dig)

ans += S[-1]*(2**(len(S)-1))
print(ans)