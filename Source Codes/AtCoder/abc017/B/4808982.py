def judge_choku(str):
    isChoku = 1
    while isChoku:
        if (str == ""):
            break
        elif (str[0] == "o" or str[0] == "k" or str[0] == "u"):
            str = str[1:]
            judge_choku(str)
        elif (str[:2] == "ch"):
            str = str[2:]
            judge_choku(str)
        else:
            isChoku = 0
    return isChoku

s=input()
print("YES" if judge_choku(s) == 1 else "NO")