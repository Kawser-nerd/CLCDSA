N = int(input())
N = 2025 - N
for i in range(1,10):
    if N%i == 0 and N/i < 10:
        print('{0} x {1}'.format(i,int(N/i)))