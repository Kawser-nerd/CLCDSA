input()
C = input()
p = [c1 + c2 for c1 in 'ABXY' for c2 in 'ABXY']
print(min(len(C.replace(p1, 'L').replace(p2, 'R')) for p1 in p for p2 in p))