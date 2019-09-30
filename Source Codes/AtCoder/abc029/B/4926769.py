def start_process():
    X, Y, Z, K = map(int, input().split())
    A = list(map(int, input().split()))
    return

def main():
    count = 0
    for i in range(12):
        a = list(input())
        if 'r' in a:
            count += 1
    print(count)



if __name__ == '__main__':
    main()