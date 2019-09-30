def watch(n: int, m: int) -> float:
    long_angle = (n % 12) * (360 // 12) + m * (360 // 12) / 60
    shor_angle = m * 360 // 60

    angle_diff = abs(long_angle - shor_angle)
    return min(angle_diff, 360 - angle_diff)


if __name__ == "__main__":
    n, m = map(int, input().split())
    ans = watch(n, m)
    print(ans)