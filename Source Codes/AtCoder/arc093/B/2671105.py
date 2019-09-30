A,B=map(int,input().split())
a_line=(A-1)//50+1
b_line=(B-1)//50+1

print(2*a_line+2*b_line,99)
for i in range(a_line):
 if i == a_line-1:
  print(('.#'*((A-1)%50)+'#'*(99-2*((A-1)%50))))
 else:
  print(('.#'*49)+'.')
 print('#'*99)

for i in range(b_line):
 print('.'*99)
 if i == b_line-1:
  print(('#.'*((B-1)%50)+'.'*(99-2*((B-1)%50))))
 else:
  print(('#.'*49)+'#')