n = int(input())
n = int(n*(n+1)/2)
if n == 1:
    print("BOWWOW")
    exit()
for i in range(2,n):
    if n % i == 0:
        print("BOWWOW")
        exit()
print("WANWAN")