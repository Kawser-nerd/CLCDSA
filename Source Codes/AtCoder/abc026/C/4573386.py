n = int(input())
b = [[0,0]]+[[i,int(input())-1] for i in range(1,n)]
#print(b)
b = b[::-1]
salary =[[] for i in range(n)]
for i in range(n):
  if not salary[i]:
    salary[i].append(1)
  else:
    salary[i].append(min(salary[i])+max(salary[i])+1)
  salary[(n-1)-b[i][1]].append(salary[i][-1])

  
print(salary[n-1][-1])