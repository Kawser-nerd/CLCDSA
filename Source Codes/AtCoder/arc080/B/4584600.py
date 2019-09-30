def start_process(high, width, number, color_data):
    ans_data = []
    for i in range(number):
        ans_data += [str(i + 1) for j in range(color_data[i])]
    for i in range(high):
        ans_kari = ans_data[i * width : (i + 1) * width]
        if i % 2 == 1:
            ans_kari = ans_kari[::-1]
        print(' '.join(ans_kari))

def main():
    high, width = map(int, input().split())
    number = int(input())
    color_data = list(map(int, input().split()))
    start_process(high, width, number, color_data)

if __name__ == '__main__':
    main()