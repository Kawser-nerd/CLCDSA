import java.util.Arrays;
import java.util.Scanner;

public class Main {

    static Scanner in = new Scanner(System.in);
    int n, k;
    String s;

    void solve() {
        n = in.nextInt();
        k = in.nextInt();
        in.nextLine();
        s = in.nextLine();
        char[] c = s.toCharArray();
        Arrays.sort(c);

        String ans = "";
        for(int i = 0 ; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(c[j] == '\0') continue;
                if(count(ans, c, c[j]) <= k) {
                    ans += c[j];
                    c[j] = '\0';
                    break;
                }
            }
        }

        System.out.println(ans);
    }

    int count(String ans, char[] c, char ch) {
        int diff = 0;
        for(int i = 0; i < ans.length(); i++) {
            diff += s.charAt(i) == ans.charAt(i) ? 0 : 1;
        }
        if(ch != s.charAt(ans.length())) {
            diff++;
        }

        int[] a = new int[26];
        for(char b : c) {
            if(b == '\0') continue;
            a[b - 'a']++;
        }
        a[ch - 'a']--;
        for(int i = ans.length() + 1; i < s.length(); i++) {
            int idx = s.charAt(i) - 'a';
            if(a[idx] > 0) {
                a[idx]--;
            }else {
                diff++;
            }
        }
        return diff;
    }

    public static void main(String[] args) {
        new Main().solve();
    }
}