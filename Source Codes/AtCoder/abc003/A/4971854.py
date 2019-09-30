N = int(input())
ave = 0

for i in range(N):
    ave = ave + (i+1)*10000/N

print(round(ave))