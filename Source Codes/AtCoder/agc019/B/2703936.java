import java.util.*;

public class Main {
    public void main(Scanner sc) {
        String a = sc.next();
        char c[] = a.toCharArray();
        int len = c.length;

        long cnt[] = new long[26];
        for (int i = 0; i < len; i++) {
            for (int j = 'a'; j <= 'z'; j++) {
                if (c[i] == j) {
                    cnt[j - 'a']++;
                }
            }
        }

        long max = len * (len - 1L) / 2;
        for (int i = 0; i < 26; i++) {
            max -= (cnt[i] * (cnt[i] - 1) / 2);
        }
        System.out.println(max + 1);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}