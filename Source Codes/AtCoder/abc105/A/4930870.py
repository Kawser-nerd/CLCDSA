import numpy as np

class Calculator:
    def __init__(self, N, K):
        self.arr = np.array([N,K])
        self.max_num = int((self.arr[0] + self.arr[1] - 1) / self.arr[1])
        self.min_num = int(self.arr[0] / self.arr[1])

    def get_answer(self):
        return self.max_num - self.min_num

def main():
    N, K, = map(int, input().split())
    c = Calculator(N, K)
    ans = c.get_answer()
    print(ans)

if __name__ == '__main__':
    main()