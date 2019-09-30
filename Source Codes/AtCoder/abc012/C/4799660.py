a=2025-int(input())
for i in range(1,10):
  if a%i==0 and a//i<10:
    print(i,"x",a//i)