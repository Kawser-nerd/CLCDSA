def main():
    h, bmi = map(float, input().split())
    print(h * h * bmi / 10000)


if __name__ == "__main__":
    main()