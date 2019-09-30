N = int(input())

p = []
n = []

for i in range(N):
    a_num, b_num = map(int, input().split())
    if a_num >= b_num:
        p.append([a_num, b_num])
    else:
        n.append([a_num, b_num])


def get_first(data):
    return data[0]


def get_second(data):
    return data[1]


p.sort(key=get_second, reverse=True)
n.sort(key=get_first)


class Temp:
    def __init__(self):
        self.current = 0
        self.top = 0

    def magic(self, data):
        self.current += data[0]
        if self.top < self.current:
            self.top = self.current
        self.current -= data[1]
        return self.top


temp = Temp()

ans = list(map(temp.magic,n + p))

print(ans[len(ans)-1])