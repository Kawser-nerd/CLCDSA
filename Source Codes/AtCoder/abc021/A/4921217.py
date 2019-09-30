n=int(input());
a=n//8;b=(n-a)//4;c=(n-a-b)//2;d=(n-a-b)%2;
print(a+b+c+d)
if a>0:
  for _ in range(a):
    print(8)
if b>0:
  for _ in range(b):
    print(4)
if c>0:
  for _ in range(c):
    print(2)
if d>0:print(1)