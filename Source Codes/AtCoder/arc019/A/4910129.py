def main():
    chars = {"O": "0", "D": "0", "I": "1", "Z": "2", "S": "5", "B": "8"}
    s = input()
    for k, v in chars.items():
        s = s.replace(k, v)
    print(s)


if __name__ == "__main__":
    main()