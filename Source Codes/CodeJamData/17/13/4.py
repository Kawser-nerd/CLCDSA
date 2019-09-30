#!/usr/bin/env python3

from collections import namedtuple

def read_ints():
    return list(map(int, input().split(' ')))

class State(namedtuple('State', 'my_health my_attack his_health his_attack')):
    def is_win(self):
        return self.his_health <= 0

    def is_loss(self):
        return self.my_health <= 0

    def attack(self):
        return State(self.my_health, self.my_attack, self.his_health - self.my_attack, self.his_attack)

    def buff(self):
        return State(self.my_health, self.my_attack + buff, self.his_health, self.his_attack)

    def cure(self):
        return State(max_health, self.my_attack, self.his_health, self.his_attack)

    def debuff(self):
        return State(self.my_health, self.my_attack, self.his_health, max(0, self.his_attack - debuff))

    def knight(self):
        return State(self.my_health - self.his_attack, self.my_attack, self.his_health, self.his_attack)

    def steps(self):
        for state in self.attack(), self.buff(), self.cure(), self.debuff():
            if not state.is_win():
                state = state.knight()
            if not state.is_loss():
                yield state

def solve(state):
    count = 1
    seen = set([state])
    current = [state]
    while current:
        next = []
        for state in current:
            for step in state.steps():
                if step.is_win():
                    return count
                if step in seen:
                    continue
                seen.add(step)
                next.append(step)
        current = next
        count += 1
    return 'IMPOSSIBLE'

def main():
    global max_health, buff, debuff
    t = int(input())
    for ti in range(t):
        max_health, my_attack, his_health, his_attack, buff, debuff = read_ints()
        print("Case #{}: {}".format(ti+1, solve(State(max_health, my_attack, his_health, his_attack))))

if __name__ == '__main__':
    main()
