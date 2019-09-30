import bisect


def present(N: int, boxes: list)->int:
    sorted_boxes = sorted(
        sorted(boxes, key=lambda x: -x[1]),
        key=lambda x: x[0])

    _, w = sorted_boxes[0]
    wrapping = [w]
    # print(sorted_boxes)

    for _, w in sorted_boxes:
        if wrapping[-1] < w:
            wrapping.append(w)
        else:
            wrapping[bisect.bisect_left(wrapping, w)] = w

    return len(wrapping)


if __name__ == "__main__":
    N = int(input())
    boxes = [tuple(int(s) for s in input().split()) for _ in range(N)]
    ans = present(N, boxes)
    print(ans)