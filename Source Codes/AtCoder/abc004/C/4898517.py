n = int(input())
N = n % 30
I = N // 5
i = N % 5 
    
number= [[1,2,3,4,5,6], [2,3,4,5,6,1],[3,4,5,6,1,2],[4,5,6,1,2,3],
         [5,6,1,2,3,4],[6,1,2,3,4,5]]

for s in range(0,i):
    number[I][s], number[I][s+1] = number[I][s+1], number[I][s]

number_str = ""
for t in number[I]:
    number_str += str(t)
print(number_str)