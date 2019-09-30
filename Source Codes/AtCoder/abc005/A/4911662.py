import sys

class Calculator:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def get_num(self):
        return int(self.y / self.x)

if __name__ == '__main__':
    x, y, = map(int, input().split())
    c = Calculator(x, y)
    print(c.get_num())