N = int(input())
if N%9 == 0:print('9'* (N//9))
else:print(str(N%9) * (N//9 + 1))