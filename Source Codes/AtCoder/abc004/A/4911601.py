class Calculator:
    def __init__(self, n):
        self.num = n

    def get_ans(self):
        return self.num * 2

if __name__ == "__main__":
    n, = map(int, input().split())
    c = Calculator(n)
    print(c.get_ans())