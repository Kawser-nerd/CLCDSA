import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        char[] c = s.toCharArray();
        if (c.length < 26) {
            int[] a = new int[26];
            for (int i = 0 ; i < c.length ; i++) {
                a[c[i] - 'a']++;
            }
            for (int i = 0 ; i < 26 ; i++) {
                if (a[i] == 0) {
                    char p = (char) ('a' + i);
                    System.out.println(s + p);
                    return;
                }
            }
        } else {
            int p = 0;
            for (int i = 25; i >= 1 ; i--) {
                if (c[i] - c[i - 1] > 0) {
                    p = i;
                    break;
                }
            }
            if (p == 0) {
                System.out.println(-1);
                return;
            }
            char ch = c[p - 1];
            char t = 'a';
            for (int i = 25 ; i >= p ; i--) {
                if (c[i] > ch) {
                    t = c[i];
                    break;
                }
            }

            System.out.println(s.substring(0, p - 1) + t);
        }

    }

}