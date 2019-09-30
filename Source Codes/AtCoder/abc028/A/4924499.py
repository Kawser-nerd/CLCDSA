def eval_test(N: int) -> int:
    if N < 60:
        return 'Bad'
    if N < 90:
        return 'Good'
    if N < 100:
        return 'Great'
    return 'Perfect'


if __name__ == "__main__":
    N = int(input())
    ans = eval_test(N)
    print(ans)