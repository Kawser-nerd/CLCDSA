class Vector(object):
    def __init__(self, pos1, pos2):
        self.point1 = pos1
        self.point2 = pos2
        self.size_x = pos2[0] - pos1[0]
        self.size_y = pos2[1] - pos1[1]

    def get_cross(self, other: "Vector"):
        return self.size_x * other.size_y - self.size_y * other.size_x

    def check_crossing(self, other: "Vector"):
        vec1, vec2 = Vector(self.point1, other.point1), Vector(self.point1, other.point2)
        vec3, vec4 = Vector(other.point1, self.point1), Vector(other.point1, self.point2)
        return self.get_cross(vec1) * self.get_cross(vec2) < 0 and \
            other.get_cross(vec3) * other.get_cross(vec4) < 0


if __name__ == "__main__":
    pos = list(map(int, input().split()))
    line = Vector(pos[0:2], pos[2:])
    N = int(input())
    a = [list(map(int, input().split())) for _ in [0]*N]
    a += [a[0]]
    count = 0

    for p1, p2 in zip(a, a[1:]):
        if Vector(p1, p2).check_crossing(line):
            count += 1

    print(count//2 + 1)