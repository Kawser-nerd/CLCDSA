A, B, C =map(int, input().split())
D = A
count = 0


if B<A:
    A = B
    B = D
  

while True:
    if C >= A:
        C = C-A
        count+=1
    else:
        break

print(count)