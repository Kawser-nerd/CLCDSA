from sys import stdin
x, y = [int(_) for _ in stdin.readline().rstrip().split()]
count=1
while True:
    x=x*2
    if x <= y:
        count+=1
    else:
        break
print(count)