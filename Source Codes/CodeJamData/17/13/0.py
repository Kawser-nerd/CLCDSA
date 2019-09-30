from __future__ import division, print_function
input = raw_input

tc = int(input())

R = 100

for t in range(1, tc+1):
    print("Case #%d: "%t, end = "")
    Hd, Ad, Hk, Ak, B, D = map(int, input().split())
    if B == 0:
        b = 0
    else:
        z = ((B * Hk) ** 0.5 - Ad) // B
        if z < 0:
            b = 0
        else:
            b1 = int(z)
            b2 = b1 + 1
            if (Hk + b1 * B + Ad - 1) // (b1 * B + Ad) + b1 <= (Hk + b2 * B + Ad - 1) // (b2 * B + Ad) + b2:
                b = b1
            else:
                b = b2
    a = (Hk + b * B + Ad - 1) // (b * B + Ad)
    ab = a + b
    Hi = Hd
    minturn = 10 ** 15
    if ab <= (Hd - 1) // Ak + 1:
        minturn = ab
    elif D == 0:
        u = (Hd - Ak - 1) // Ak
        if u <= 0 and Hk > Ad:
            minturn = 10 ** 15
        else:
            w = ab - (Hd - 1) // Ak
            minturn = (Hd - 1) // Ak + w + (w + u - 2) // u
    elif Hk > Ad and Ak - D >= Hd:
        minturn = 10 ** 15
    else:
        z = 0
        last_was_heal = False
        Hi = Hd
        lastu = -1
        while Ak > 0:
            u = (Hd - Ak - 1) // Ak
            if ab <= (Hi - 1) // Ak + 1:
                minturn = min(minturn, z + ab)
            elif u > 0 and not last_was_heal and u != lastu:
                w = ab - (Hi - 1) // Ak
                minturn = min(minturn, z + (Hi - 1) // Ak + w + (w + u - 2) // u)
            if Hi <= Ak - D:
                if last_was_heal:
                    break
                z += 1
                last_was_heal = True
                Hi = Hd - Ak
                if Ak >= R * D and u == (Hd - (Ak - R * D) - 1) // (Ak - R * D):
                    tt = R // u
                    z += tt * (u + 1)
                    Ak -= tt * u * D
                    Hi = Hd - Ak
            else:
                last_was_heal = False
                z += 1
                Ak -= D
                Hi -= Ak
            lastu = u
        if Ak <= 0:
            minturn = min(minturn, z + ab)
    if minturn == 10 ** 15:
        print("IMPOSSIBLE")
    else:
        print(minturn)
                
        
