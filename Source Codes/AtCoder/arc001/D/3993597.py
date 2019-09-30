import sys

class QueenSet:
    def __init__(self, flds):
        self.org_flds = flds[:]

    def set_least_Queen(self):
        self.flds = self.org_flds[:]
        if self.isStartEnable() == False:
            return False
        return self.set_next(0, 0)

    def set_next(self, x, set_count):
        if x < 8:
            for y in range(0, 8):
                if 'Q' in self.flds[x]:
                    if self.isSetEnable(x, y):
                        if self.set_next(x + 1, set_count + 1):
                            return True
                        continue
                if self.isSetEnable(x, y):
                    org_x = self.flds[x]
                    if y == 0:
                        self.flds[x] = 'Q' + self.flds[x][1:8]
                    elif y == 7:
                        self.flds[x] = self.flds[x][0:7] + 'Q'
                    else:
                        self.flds[x] = self.flds[x][0:y] + 'Q' + self.flds[x][y + 1:8]
                    if self.set_next(x + 1, set_count + 1):
                        return True
                    self.flds[x] = org_x

        if set_count == 8:
            return True
        else:
            return False

    def isStartEnable(self):
        for x in range(0, 8):
            if 'Q' in self.flds[x]:
                for y in range(0, 8):
                    if self.flds[x][y] == 'Q':
                        if self.isSetEnable(x, y) == False:
                            return False
        return True

    def isSetEnable(self, x, y):
        for i in range(0, 8):
            if i == x:
                continue
            if self.flds[i][y] == 'Q':
                return False

        for j in range(1, 8):
            if x - j >= 0 and y - j >= 0:
                if self.flds[x - j][y - j] == 'Q':
                    return False
            if x + j < 8 and y - j >= 0:
                if self.flds[x + j][y - j] == 'Q':
                    return False
            if x - j >= 0 and y + j < 8:
                if self.flds[x - j][y + j] == 'Q':
                    return False
            if x + j < 8 and y + j < 8:
                if self.flds[x + j][y + j] == 'Q':
                    return False

        return True

def main():
    flds = [""]*8

    for i in range(len(flds)):
        flds[i] = input()

    '''
    for temp in flds:
        print(temp)
    '''

    qs = QueenSet(flds)

    if qs.set_least_Queen():
        for temp in qs.flds:
            print(temp)
    else:
        print("No Answer")

if __name__ == "__main__":
    main()