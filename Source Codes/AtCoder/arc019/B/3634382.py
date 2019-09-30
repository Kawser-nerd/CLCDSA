A = input()
ans = 0
for i in range(len(A)//2):
    if A[i] != A[-i-1]:
        ans += 1
if ans == 0:
    print(25*2*(len(A)//2))
elif ans == 1:
    print(24*2+25*(len(A)-2))
else:
    print(25*len(A))