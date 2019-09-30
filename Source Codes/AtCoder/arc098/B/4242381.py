def main():
    n = int(input().rstrip("\b"))
    numbers = [int(x) for x in input().rstrip("\b").split(" ")]
    start_number = numbers.pop(0)
    targets = {start_number:1}
    total = 0
    from collections import defaultdict
    for number in numbers:
        next_targets = defaultdict(int)
        for (target, count) in targets.items():
            total += count
            if (number | target) >= (target + number):
                next_targets[target + number] += count
        next_targets[number] += 1
        targets = next_targets
        #print(total)
    for (target, count) in targets.items():
        total += count

    print(total)

if __name__ == '__main__':
    main()