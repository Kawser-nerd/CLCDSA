def a_tab(N, L, S):
    num_opened_tabs = 1
    num_crashed_browser = 0
    for c in S:
        if c == '+':
            num_opened_tabs += 1
            if num_opened_tabs == L + 1:
                num_crashed_browser += 1
                num_opened_tabs = 1
        elif c == '-':
            num_opened_tabs -= 1
    return num_crashed_browser

N, L = [int(i) for i in input().split()]
S = input()
print(a_tab(N, L, S))