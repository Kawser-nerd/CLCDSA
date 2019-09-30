N = int(input())
c = (N//10)*100 + (N%10)*15
c2 = (N//10+1)*100
print(min(c,c2))