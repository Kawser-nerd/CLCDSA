x = input()
a = ["ch", 'o', 'k', 'u']
for a_ in a:
    x = "".join(x.split(a_))
if len(x) == 0:
    ans = "YES"
else:
    ans = "NO"
print(ans)