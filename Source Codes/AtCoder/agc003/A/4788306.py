s = input()

N = 'N' in s
S = 'S' in s
E = 'E' in s
W = 'W' in s

if N ^ S or E ^ W:
    print("No")
else:
    print("Yes")