import sys

def rins():
    return raw_input().strip()

def read_testcase():
    values = rins().split()[1:]
    testcase = []
    for i in xrange(0,len(values),2):
        testcase.append((values[i], int(values[i+1])))
    return testcase

class Robot(object):
    def __init__(self):
        self.pos = 1
        self.time = 0

def other_color(color):
    return {'O':'B', 'B':'O'}[color]

def solve_next():
    testcase = read_testcase()
    robots = {'O':Robot(), 'B':Robot()}
    for color, button in testcase:
        robot = robots[color]
        distance = abs(button - robot.pos)
        newtime = max(robot.time + distance + 1, robots[other_color(color)].time + 1)
        robot.time = newtime
        robot.pos = button
    return max(r.time for r in robots.values())

def run():
    n = int(rins())
    for i in xrange(n):
        print "Case #{0}: {1}".format(i+1, solve_next())

run()
