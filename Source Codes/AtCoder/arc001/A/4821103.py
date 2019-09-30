N = int(input())
c = input()

c1 = c.count('1')
c2 = c.count('2')
c3 = c.count('3')
c4 = c.count('4')

ans = [c.count('1'), c.count('2'), c.count('3'), c.count('4')]

ans.sort()

print(ans[3], ans[0])