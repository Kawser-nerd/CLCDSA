import numpy as np

class Calculator:
    def __init__(self, arr):
        self.arr = arr

    def calc(self):
        self.min_num = 9999
        self.max_num = 0
        for i in range(1, 5):
            self.sum = np.sum(self.arr == i)
            self.min_num = min(self.min_num, self.sum)
            self.max_num = max(self.max_num, self.sum)

    def get_max(self):
        return self.max_num

    def get_min(self):
        return self.min_num

def main():
    N, = map(int, input().split())
    c = list(map(int, list(input())))
    arr = np.array(c, dtype=int)

    calc = Calculator(arr)
    calc.calc()
    print(calc.get_max(), calc.get_min())

if __name__ == "__main__":
    main()