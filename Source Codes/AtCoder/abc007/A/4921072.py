import numpy as np

class Calculator:
    def __init__(self):
        pass

    def set_num(self, N):
        self.num = 0
        self.N = N

    def calc(self):
        self.num = self.N - 1;

    def get_num(self):
        return self.num

def main():
    N, = map(int, input().split())
    c = Calculator()
    c.set_num(N)
    c.calc()
    ans = c.get_num()
    print(ans)

if __name__ == "__main__":
    main()