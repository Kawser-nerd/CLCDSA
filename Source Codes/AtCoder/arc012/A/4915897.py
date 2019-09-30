def main():
    d = input()
    rems = {
        "Sunday": 0,
        "Monday": 5,
        "Tuesday": 4,
        "Wednesday": 3,
        "Thursday": 2,
        "Friday": 1,
        "Saturday": 0,
    }
    print(rems[d])


if __name__ == "__main__":
    main()