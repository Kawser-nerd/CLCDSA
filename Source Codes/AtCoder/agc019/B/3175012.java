import java.util.*;

public class Main {

    int INF = Integer.MAX_VALUE;

    public static void main(String[] args) {
        new Main().solve();
    }

    void solve() {
        Scanner sc = new Scanner(System.in);
        String A = sc.next();
        char[] a = A.toCharArray();
        Arrays.sort(a);
        long c = 1;
        long ans = 0;
        for (int i = 1; i < (long) A.length(); i++) {
            if (a[i] != a[i - 1]) {
                ans += (c * (c - 1)) / 2;
                c = 1;
            } else {
                c++;
            }
        }
        ans += (c * (c - 1)) / 2;
        System.out.println(((long) A.length() * ((long) A.length() - 1)) / 2 - ans + 1);
    }
}