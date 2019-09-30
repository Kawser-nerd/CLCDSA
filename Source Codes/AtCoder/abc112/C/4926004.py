# -*- coding: utf-8 -*-

class Info():
    def __init__(self, x, y, h):
        self.X = x
        self.Y = y
        self.H = h

def main():
    N = int(input())
    infos = []
    for i in range(N):
        x, y, h = list(map(int, input().split(" ")))
        infos.append(Info(x, y, h))
    
    # [0, 100]????????MAX?????
    MAX = 100
    for posY in range(0, MAX+1):
        for posX in range(0, MAX+1):
            # ????????????????????
            # -1?????????????0??????????
            # -2???????????
            ans_h = -1

            for i in range(N):
                # ??????????
                if infos[i].H > 0:
                    H = infos[i].H + abs(posY - infos[i].Y) + abs(posX - infos[i].X)
                    if ans_h == -1:
                        ans_h = H
                    else:
                        if ans_h != H:
                            ans_h = -2
                            break
            
            # ?????????????
            if ans_h == -2:
                continue
            
            is_ok = True
            for i in range(N):
                # ???????????0???????????????
                if infos[i].H == 0:
                    if ans_h - abs(posY - infos[i].Y) - abs(posX - infos[i].X) <= 0:
                        continue
                    else:
                        is_ok = False
                        break
            
            if is_ok:
                print(posX, posY, ans_h)
                return
            """
                if infos[i].H == 0:
                    dist = abs(posY - infos[i].Y) + abs(posX - infos[i].X)
                    if ans_h > dist:
                        ans_h = -2
                        break
            
            if ans_h == -2:
                continue

            print(posX, posY, ans_h)
            return

            """
            

if __name__ == '__main__':
    main()