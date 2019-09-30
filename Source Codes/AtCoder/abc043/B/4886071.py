def unhappy_hacking(s: str) -> str:
    display = ''

    for key in s:
        if key == '0':
            display += '0'
        elif key == '1':
            display += '1'
        else:  # Backspace
            display = display[:-1]

    return display


if __name__ == "__main__":
    s = input()
    ans = unhappy_hacking(s)
    print(ans)