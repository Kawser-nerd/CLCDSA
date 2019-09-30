N, P = list(map(int, input().split()))
A = list(map(int, input().split()))

ev = 0
ad = 0
for i in A:
  if i % 2 == 0:
    ev += 1
  else:
    ad += 1

if P == 1:
  if ad == 0:
    print("0")
    exit()
  

f = [1, 1]
for i in range(2, ad + 1):
  f.append(f[-1] * i)
num = 0
for i in range(P, ad + 1, 2):
  num += f[ad] // (f[i] * f[ad - i])

print(pow(2, ev) * num)