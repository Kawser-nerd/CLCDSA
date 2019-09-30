C1 = input()
C2 = input()

C1a = C1[2]+C1[1]+C1[0]
C2a = C2[2]+C2[1]+C2[0]

if C1 == C2a and C2 == C1a:
    print("YES")
else:
    print("NO")