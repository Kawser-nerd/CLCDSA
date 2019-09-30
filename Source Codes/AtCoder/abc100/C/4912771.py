len_list = int(input())
input_list = [int(x) for x in input().split()][:len_list]

n = 0

for x in input_list :
   while (x % 2) == 0 :
      x/=2
      n+=1      
print(n)