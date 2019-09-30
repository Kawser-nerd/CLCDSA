T = int(input())
for t in range(1, T+1):
    s1, s2 = set(), set()
    a = int(input())
    for i in range(4):
        u = input();
        if i == a-1:
            s1 |= set(map(int, u.split()))
    a = int(input())
    for i in range(4):
        u = input();
        if i == a-1:
            s2 |= set(map(int, u.split()))
    r = s1 & s2
    z = ''
    if len(r) == 0:
        z = 'Volunteer cheated!'
    elif len(r) == 1:
        z = list(r)[0]
    else:
        z = 'Bad magician!'
    print('Case #'+str(t)+': '+str(z))