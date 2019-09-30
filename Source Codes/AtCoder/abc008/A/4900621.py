s = input().split()

S = int(s[0])
T = int(s[1])

if 1 <= S <= T <= 1000:
    print(T - S +1)