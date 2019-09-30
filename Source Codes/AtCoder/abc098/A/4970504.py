i = list(map(int, input().split()))
A = i[0]
B = i[1]

a = 0
s = 0
m = 0

def add(a, b):
  return a + b

def sub(a, b):
  return a - b

def mul(a, b):
  return a * b

a = add(A, B)
s = sub(A, B)
m = mul(A, B)

print(max(a, s, m))