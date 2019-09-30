def solution(num, list):
    flag = "default"
    count = 1
    for i in range(num - 1):
        diff = l[i+1] - l[i]
        if flag == "plus":
            if diff < 0:
                flag = "default"
                count += 1
        elif flag == "minus":
            if diff > 0:
                flag = "default"
                count += 1
        else:
            if diff > 0:
                flag = "plus"
            elif diff < 0:
                flag = "minus"
    return count

if __name__ == "__main__":
    n = int(input())
    l = list(map(int, input().split()))
    print(solution(n, l))