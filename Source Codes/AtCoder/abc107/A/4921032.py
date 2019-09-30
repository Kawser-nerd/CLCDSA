import numpy as np

class Calculator:
    def __init__(self):
        self.num = 0

    def set_num(self, N, i):
        self.N = N
        self.i = i

    def calc(self):
        self.num = self.N - self.i + 1;

    def get_num(self):
        return self.num

def main():
    N, i, = map(int, input().split())
    c = Calculator()
    c.set_num(N, i)
    c.calc()
    ans = c.get_num()
    print(ans)

if __name__ == "__main__":
    main()