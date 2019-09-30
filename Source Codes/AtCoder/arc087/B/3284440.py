s = input() + "T"
goal_x, goal_y = map(int, input().split())
length = len(s)
dp_x, dp_y = [0]*(length*2+1), [0]*(length*2+1)
start = x_steps = s.index("T")
dp_x[length+start] = dp_y[length] = 1
steps = y_steps = 0
direction = 0

for i, c in enumerate(s[start:], start=start):
    if c == "F":
        steps += 1
    else:
        if steps:
            _dp = [0]*(length*2+1)
            if direction == 0:
                for x, v in enumerate(dp_x[length-x_steps:length+x_steps+1], start=length-x_steps):
                    if v:
                        _dp[x-steps] = _dp[x+steps] = 1
                x_steps += steps
                dp_x = _dp
            else:
                for y, v in enumerate(dp_y[length-y_steps:length+y_steps+1], start=length-y_steps):
                    if v:
                        _dp[y-steps] = _dp[y+steps] = 1
                y_steps += steps
                dp_y = _dp

        steps = 0
        direction ^= 1

print("Yes" if dp_x[length+goal_x] and dp_y[length+goal_y] else "No")