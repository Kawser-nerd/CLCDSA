n = input()
result = 0

if int(n)%10 == 0:
    result = 10
else:
    result = sum(int(i) for i in n)

print(result)