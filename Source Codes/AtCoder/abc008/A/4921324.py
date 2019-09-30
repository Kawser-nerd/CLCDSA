import numpy as np

class Calculator:
    def __init__(self, arr):
        self.arr = arr
        self.calc()

    def calc(self):
        self.num = np.sum(self.arr > 0)

    def get_num(self):
        return self.num

def main():
    S, T, = map(int, input().split())
    arr = np.arange(S, T+1)
    calc = Calculator(arr)
    print(calc.get_num())

if __name__ == '__main__':
    main()