inputs = input().split()
n, a, b = list(map(int, inputs))
count=0
for num in range(n+1):
    num_str = str(num)
    all = 0
    for i in range(len(num_str)):
       all += int(num_str[i])
    if a <= all <= b:
      count+=num
print(count)