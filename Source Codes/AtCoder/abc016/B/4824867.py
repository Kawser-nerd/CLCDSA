A, B, C = map(int, input().split())

if A+B==C and A-B==C:
    ans = '?'
elif A+B==C:
    ans = '+'
elif A-B==C:
    ans = '-'
else:
    ans = '!'

print(ans)