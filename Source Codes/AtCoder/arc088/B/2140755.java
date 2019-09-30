import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        byte[] s = scan.next().getBytes();
        int m = s.length / 2;
        if (s.length % 2 == 0) {
            for (int i = 0; i < m; i++) {
                if (s[m - 1 - i] != s[m] || s[m + i] != s[m]) {
                    System.out.println(m + i);
                    return;
                }
            }
        }
        else {
            for (int i = 0; i < m + 1; i++) {
                if (s[m  - i] != s[m] || s[m + i] != s[m]) {
                    System.out.println(m + i);
                    return;
                }
            }
        }
        System.out.println(s.length);
    }
}