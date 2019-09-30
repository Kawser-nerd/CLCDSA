S = input()
T = input()
ans = 'You can win'
for a,b in zip(S,T):
    if a!=b and a+b not in ('@a@t@c@o@d@e@r@'):
        ans = 'You will lose'
        break
print(ans)