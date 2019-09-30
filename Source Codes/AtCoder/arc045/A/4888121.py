def main():
    res = {"Left": "<", "Right": ">", "AtCoder": "A"}
    print(" ".join(res[w] for w in input().split()))


if __name__ == "__main__":
    main()