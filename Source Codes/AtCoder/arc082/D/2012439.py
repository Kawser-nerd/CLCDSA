X = int(input())
K = int(input())
r_lst = [int(_) for _ in input().split()]
Q = int(input())
t_lst, a_lst = [], []
for i in range(Q):
    buf = input().split()
    t_lst.append(int(buf[0]))
    a_lst.append(int(buf[1]))
    
pos_lst = []
for i, r in enumerate(r_lst):
    direc = "+" if i%2==0 else "-"
    pos_lst.append((r, direc))
for i, t in enumerate(t_lst):
    pos_lst.append((t, i))
pos_lst = sorted(pos_lst, key=lambda tup: tup[0])


left, right  = 0, X
val = [0, 0, X] 

direc = "-"
prv = 0
for pos in pos_lst:
#    print(left, right)
#    print(val)
#    print(pos)
#    print()
    
    elapsed = pos[0] - prv
    prv = pos[0]
    
    if direc == "+":
        val[0] = min(X, val[0] + elapsed)
        val[1] += elapsed
        val[2] = min(X, val[2] + elapsed)
        right = min(right, X - val[1])
    else:
        val[0] = max(0, val[0] - elapsed)
        val[1] -= elapsed
        val[2] = max(0, val[2] - elapsed)     
        left = max(left, -(val[1]))
        
    if pos[1] == "+" or pos[1] == "-":
        direc = pos[1]
    else: #is query
        a = a_lst[pos[1]]
        
        if a <= left:
            print(val[0])
        elif a >= right:
            print(val[2])
        else:
            print( a + val[1])