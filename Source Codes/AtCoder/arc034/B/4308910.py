def main():
    N = int(input().rstrip("\n"))
    answers = []
    for n in range(max(N-153, 1),N):

        s = str(n)
        sum_of_digits = sum([int(x) for x in s])
        if (n + sum_of_digits) == N:
            answers.append(n)
    
    print(len(answers))
    for answer in answers:
        print(answer)
    
if __name__ == '__main__':
    main()