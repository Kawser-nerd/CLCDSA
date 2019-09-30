_ = int(input())
l = [int(i) for i in input().split()]
count = 0
output = []
for num in l:
    while num%2 == 0:
        num = num/2
    output.append(num)
print(len(set(output)))