s = str(input())
t = [0 for i in range(len(s)-2)]
for i in range(len(s)-2):
    t[i] = int(s[i:i+3])
u = [0 for i in range(len(t))]
for i in range(len(t)):
    u[i] = abs(t[i]-753)
print(min(u))