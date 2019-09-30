s = input()
k = int(input())

sub_s = []
for i in range(len(s)-k+1):
    sub_s.append(s[i:i+k])

print(len(set(sub_s)))