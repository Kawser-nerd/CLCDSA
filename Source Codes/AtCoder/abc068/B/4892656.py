a = int(input())
max_count = 0
max_number = 1

for i in range(1,a+1):
    count = 0
    hold = i
    while i%2 == 0:
        count += 1
        i //= 2
    if count > max_count:
        max_count = count
        max_number = hold
        
print(max_number)