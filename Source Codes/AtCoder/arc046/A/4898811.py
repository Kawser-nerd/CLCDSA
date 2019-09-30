n = int(input())

count = 0
num = 0

while count < n:
    num += 1
    for i in range(len(str(num))-1):
       if str(num)[i] != str(num)[i+1]:
            break
    else:
      count += 1

print(num)