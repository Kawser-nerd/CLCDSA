def testcase():
    my_health, my_attack, his_health, his_attack, buff, debuff = [int(x) for x in input().split(" ")]

    # figure out how many attack steps we need

    best_attack_rounds = 100
    for d in range(101):
        # spend first d round to buff
        tmp_attack = my_attack + buff * d
        rounds_to_kill = his_health // tmp_attack
        if tmp_attack * rounds_to_kill < his_health:
            rounds_to_kill += 1
        best_attack_rounds = min(best_attack_rounds, rounds_to_kill + d)

    # if he cannot kill me first

    if his_attack * (best_attack_rounds - 1) < my_health:
        return int(best_attack_rounds)

    best_time = 1000000
    for how_many_debuffs in range(101):
        my_h = my_health
        his_a = his_attack

        # simulate!
        used_debuffs = 0
        empty_moves = 0

        for step in range(2000):
            # if can do debuff, do debuff
            if his_a - debuff < my_h and used_debuffs < how_many_debuffs:
                his_a = max(0, his_a - debuff)
                used_debuffs += 1
            elif my_h > his_a or empty_moves == best_attack_rounds - 1:
                empty_moves += 1
            else:
                my_h = my_health

            if empty_moves == best_attack_rounds:
                best_time = min(best_time, step+1)
                break

            my_h -= his_a

            if my_h <= 0:
                break

    return int(best_time) if best_time < 1000000 else "IMPOSSIBLE"


t = int(input())

for num in range(t):
    print("Case #{num}: {result}".format(num=num + 1, result=testcase()))