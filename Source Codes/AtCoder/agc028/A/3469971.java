import java.util.*;

public class Main {
    public void main(Scanner sc) {
        int n = sc.nextInt();
        int m = sc.nextInt();
        char s[] = sc.next().toCharArray();
        char t[] = sc.next().toCharArray();
        sc.close();

        System.out.println(n < m ? check(n, m, s, t) : check(m, n, t, s));
    }

    private long check(int min, int max, char s[], char t[]) {
        int g = gcm(max, min);
        int minp = min / g;
        int maxp = max / g;
        for (int i = 0; i < g; i++) {
            if (s[i * minp] != t[i * maxp]) {
                return -1;
            }
        }

        return ((long) min) * maxp;
    }

    private int gcm(int a, int b) {
        return b == 0 ? a : gcm(b, a % b);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
    }
}