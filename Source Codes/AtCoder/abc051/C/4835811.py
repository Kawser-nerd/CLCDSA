# -*- coding: utf-8 -*-

sx,sy,tx,ty = map(int,input().split())

route = []

y = ty - sy
x = tx - sx

route += ["U"] * y
route += ["R"] * x
route += ["D"] * y
route += ["L"] * x
route += ["L"]
route += ["U"] * (y + 1)
route += ["R"] * (x + 1)
route += ["D","R"]
route += ["D"] * (y + 1)
route += ["L"] * (x + 1)
route += ["U"]

print("".join(route))