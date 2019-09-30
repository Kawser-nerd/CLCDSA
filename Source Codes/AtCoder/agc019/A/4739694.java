import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long q = sc.nextLong();
        long h = sc.nextLong();
        long s = sc.nextLong();
        long d = sc.nextLong();
        long n = sc.nextLong();
        q *= 4;
        h *= 2;
        long ans = 0;
        if(n >= 2) {
            ans += Math.min(q * 2, (Math.min(h * 2, (Math.min(s * 2, d))))) * (n / 2);
            n = n - (n / 2) * 2;
        }
        ans += Math.min(q, (Math.min(h, s))) * n;
        System.out.println(ans);
    }
}