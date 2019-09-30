import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        List<Long> a = new ArrayList<>();
        a.add(0L);
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'A') {
                a.add(a.get(i) + 1);
                continue;
            }
            a.add(a.get(i));
        }

        List<Long> c = new ArrayList<>();
        c.add(0L);
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'C') {
                c.add(c.get(i) + 1);
                continue;
            }
            c.add(c.get(i));
        }

        List<Long> hatena = new ArrayList<>();
        hatena.add(0L);
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '?') {
                hatena.add(hatena.get(i) + 1);
                continue;
            }
            hatena.add(hatena.get(i));
        }

        long ans = 0;
        long MOD = 1000000007;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '?' || s.charAt(i) == 'B') {
                long aCnt = a.get(i);
                long cCnt = c.get(s.length()) - c.get(i + 1);
                long hatenaLeft = hatena.get(i);
                long hatenaRight = hatena.get(s.length()) - hatena.get(i + 1);
                ans += aCnt * cCnt % MOD * pow(3, hatenaLeft + hatenaRight, MOD) % MOD;
                ans %= MOD;
                ans += aCnt * hatenaRight % MOD * pow(3, hatenaLeft + hatenaRight - 1, MOD) % MOD;
                ans %= MOD;
                ans += hatenaLeft * cCnt % MOD * pow(3, hatenaLeft + hatenaRight - 1, MOD) % MOD;
                ans += hatenaLeft * hatenaRight % MOD * pow(3, hatenaLeft + hatenaRight - 2, MOD)
                    % MOD;
            }
            ans %= MOD;
        }
        System.out.println(ans);
    }
    public static long pow(long x, long n, long mod) {
        long ans = 1;
        while (n > 0) {
            if ((n & 1) == 1) {
                ans = ans * x % mod;
            }
            x = x * x % mod;
            n >>= 1;
        }
        return ans;
    }
}