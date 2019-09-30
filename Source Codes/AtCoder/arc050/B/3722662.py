if __name__ == '__main__':
    
    R, B = map(int, input().split())
    x, y = map(int, input().split())
    ans = 0
    ans = max(ans, min(R // x, B))
    ans = max(ans, min(R, B // y));
    if R * y - B >= 0:
        k = (R * y - B) // (x * y - 1);
        l = min(R - k * x, (B - k) // y);
        if l >= 0:
            ans = max(ans, k + l);
        k += 1
        l = min(R - k * x, (B - k) / y);
        if l >= 0:
            ans = max(ans, k + l);
    print(ans)