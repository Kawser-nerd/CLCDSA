n = int(input())
salary = 0
for i in range(1,n+1):
    salary += i*10000*(1/n)
print(int(salary))