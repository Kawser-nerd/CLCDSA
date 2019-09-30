N = int(input())
a_ = list(map(int,input().split()))

a_g = [i for i in a_ if i%2 == 0]

count = 0
for i in a_g:
  while(i%2 == 0):
    count += 1
    i = i/2
print(count)