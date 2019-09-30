import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String x = sc.next();
        long cnt = 0;
        long s = 0;
        int n = x.length();
        for (int i = 0; i < n; i++) {
            if (x.charAt(i) == 'S') {
                s++;
            }
            if (x.charAt(i) == 'T') {
                s--;
                if (s < 0) {
                    s = 0;
                    continue;
                }
                cnt++;
            }
        }
        long ans = n - 2 * cnt;
        System.out.println(ans);
    }
}