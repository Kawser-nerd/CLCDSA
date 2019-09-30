class Calculator:
    def __init__(self):
        pass

    def set_num(self, x):
        self.x = x

    def get_judgement(self):
        self.judge = False
        if "3" in str(self.x) or self.x % 3 == 0:
            self.judge = True
        return self.judge

if __name__ == "__main__":
    n, = map(int, input().split())
    c = Calculator()
    c.set_num(n)
    if c.get_judgement():
        print("YES")
    else:
        print("NO")