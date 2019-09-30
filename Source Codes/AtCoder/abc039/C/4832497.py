s=input()
s=s[:12]
DO='WBWBWWBWBWBW'
ans=["Do","Si","La","So","Fa","Mi","Re"]
for i in range(8):
  if s==DO:
    print(ans[i])
    exit()
  DO=list(DO)
  DO.insert(0,DO.pop())
  if DO[0]!='W':
    DO.insert(0,DO.pop())
  DO="".join(DO)