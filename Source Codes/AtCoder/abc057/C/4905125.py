N = int(input())
minimum = 10**9
num = []
for i in range(1, int(N**0.5)+1):
    if N%i == 0:
        num.append(i)
for i in num:
    A = i
    B = N//i
    minimum = len(str(max(A,B))) if minimum > len(str(max(A,B))) else minimum
print(minimum)