s=input()
t=input()

s=sorted(s)
t=sorted(t)[::-1]

print('Yes' if s<t else 'No')