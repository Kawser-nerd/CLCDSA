n=int(input())
hoge=[]
ans_name="hoge"
ans_coun=0
for i in range(n):
  hoge.append(input())
  
for i in range(n):
  if(hoge.count(hoge[i])>=ans_coun):
    ans_name=hoge[i]
    ans_coun=hoge.count(hoge[i])
    
print(ans_name)