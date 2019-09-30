def main():
    n = int(input())
    a = list(map(int,input().split()))
    if (max(a) - min(a)) > 1:
        print("No")
        return 0
    minor = a.count(min(a))
    if n != minor:
        major = n-minor

        mini = minor+1
        maxi = minor + (major//2)
        if mini <= max(a) and max(a) <= maxi:
            print("Yes")
        else:
            print("No")
    else:
        mini = 1
        maxi = minor//2
        if mini <= max(a) and max(a) <= maxi or max(a) == n-1:
            print("Yes")
        else:
            print("No")


main()