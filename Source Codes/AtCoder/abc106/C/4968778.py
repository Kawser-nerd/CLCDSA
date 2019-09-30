s = input()
k = int(input())
iti = True
for i in range(k):
    if s[i] != '1':
        print(s[i])
        iti = False
        break
if iti:
    print(1)