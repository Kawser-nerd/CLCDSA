n = int(input())
m = n//10
n -= m*10
print(m*100+min(n*15,100))