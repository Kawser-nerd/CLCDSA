import java.util.*;

public class Main {

    long INF = Long.MAX_VALUE;

    public static void main(String[] args) {
        new Main().solve();
    }

    void solve() {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        char[] s = S.toCharArray();
        boolean[] c = new boolean[26];
        Arrays.fill(c, false);
        for (int i = 0; i < S.length(); i++) {
            c[s[i] - 'a'] = true;
        }
        if (S.length() < 26) {
            for (int i = 0; i < 26; i++) {
                if (!c[i]) {
                    System.out.print(S);
                    System.out.println((char) ('a' + i));
                    return;
                }
            }
        }
        if("zyxwvutsrqponmlkjihgfedcba".equals(S)){
            System.out.println("-1");
            return;
        }
        char right;
        for (int i = 24; i >= 0; i--) {
            if ((s[i + 1]) > (s[i])) {
                right = s[i + 1];
                for (int j = i + 1; j < 26; j++) {
                    if ((s[i]) < (s[j])) {
                        right = (char) Math.min(right, s[j]);
                    }
                }
                for (int j = 0; j < i; j++) {
                    System.out.print(s[j]);
                }
                System.out.println(right);
                return;
            }
        }
    }
}