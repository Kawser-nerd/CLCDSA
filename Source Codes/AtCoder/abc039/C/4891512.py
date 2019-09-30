def pianist_takahashi(S: str)->int:
    scales = [
        'Do', 'Do#', 'Re', 'Re#', 'Mi',
        'Fa', 'Fa#', 'So', 'So#', 'La', 'La#', 'Si'
    ]
    keyboard = 'WBWBWWBWBWBW'

    for i, scale in enumerate(scales):
        if (S).startswith(keyboard[i:] + keyboard[:i]):
            return scale
    return 'Unknown'


if __name__ == "__main__":
    S = input()
    ans = pianist_takahashi(S)
    print(ans)