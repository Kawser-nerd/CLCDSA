import math
N = int(input())

MovingCardNum = math.floor(N / 5) % 6 + 1
List = list(range(MovingCardNum + 1, 7)) + list(range(1, MovingCardNum + 1))

idx = N % 5
List[(idx + 1) : 6] = List[idx : 5]
List[idx] = MovingCardNum

print(''.join([str(x) for x in List]))