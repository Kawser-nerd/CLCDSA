def input():
    with open('b.in') as file:
        tests_count = int(file.readline().strip())
        for i in xrange(tests_count):
            levels_count = int(file.readline().strip())
            levels_requirements = []
            for j in xrange(levels_count):
                levels_requirements.append(tuple(int(n) for n in file.readline().strip().split()))

            yield levels_requirements

def output(answers):
    with open('b.out', 'w') as file:
        for i, answer in enumerate(answers):
            file.write('Case #%s: %s\n' % (i + 1, answer))

def choose_level(levels_requirements, levels_solved, stars_earned):
    for i in xrange(len(levels_requirements)):
        result = levels_solved[i]
        if result < 2:
            if levels_requirements[i][1] <= stars_earned:
                levels_solved[i] = 2
                return 2 - result

    candidate_i= -1
    maximum_2_stars = -1
    for i in xrange(len(levels_requirements)):
        result = levels_solved[i]
        if result == 0:
            if levels_requirements[i][0] <= stars_earned:
                if levels_requirements[i][1] > maximum_2_stars:
                    maximum_2_stars = levels_requirements[i][1]
                    candidate_i = i

    if candidate_i == -1:
        return 0
    levels_solved[candidate_i] = 1
    return 1

def solve(levels_requirements):
    levels_solved = [0] * len(levels_requirements)

    stars_earned = 0
    games_played = 0
    while True:
        if all(l == 2 for l in levels_solved):
            return games_played
        new_stars = choose_level(levels_requirements, levels_solved, stars_earned)
        if not new_stars:
            return 'Too Bad'
        else:
            stars_earned += new_stars
            games_played += 1

def main():
    answers = (solve(levels_requirements) for levels_requirements in input())
    output(answers)

if __name__ == '__main__':
    main()