n = input()
a = []
for i in range(len(n)-2):
    a.append(abs(int(n[i:i+3])-753))
print(min(a))