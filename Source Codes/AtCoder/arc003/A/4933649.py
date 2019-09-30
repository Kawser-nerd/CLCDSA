SCORE = {
    'A': 4,
    'B': 3,
    'C': 2,
    'D': 1,
    'F': 0
}


def main():
    N = int(input())
    ranks = input().rstrip()
    gpa = float(sum(SCORE[t] for t in ranks)) / float(len(ranks))
    print("{}".format(gpa))


if __name__ == '__main__':
    main()