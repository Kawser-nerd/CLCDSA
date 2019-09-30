if __name__ == '__main__':
    box_count = int(input())
    boxes = []
    box_towers = []

    for i in range(box_count):
        boxes.append(int(input()))

    for box in boxes:
        is_stacked = False
        for tower in box_towers:
            if tower[-1] >= box:
                tower.append(box)
                is_stacked = True
                break
        if not is_stacked:
            box_towers.append([box])

    print(len(box_towers))