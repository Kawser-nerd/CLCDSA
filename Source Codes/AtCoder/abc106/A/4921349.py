import numpy as np

class Calculator:
    def __init__(self, arr):
        self.arr = arr

    def get_result(self):
        return (self.arr[0] - 1) * (self.arr[1] - 1)

def main():
    A, B, = map(int, input().split())
    arr = np.array([A, B], dtype=int)
    calc = Calculator(arr)
    print(calc.get_result())

if __name__ == "__main__":
    main()