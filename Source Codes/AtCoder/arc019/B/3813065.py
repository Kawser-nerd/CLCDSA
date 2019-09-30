A = input()

dif_count = 0
for a, b in zip(A[:len(A)//2], A[(len(A)+1)//2:][::-1]):
    if a != b:
        dif_count += 1

if dif_count == 0:
    print(25*(len(A)//2*2))
elif dif_count == 1:
    print(25*len(A)-2)
else:
    print(25*len(A))