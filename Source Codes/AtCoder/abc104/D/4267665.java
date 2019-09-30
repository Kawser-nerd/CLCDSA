import java.util.*;

public class Main {
    private static final char ABC[] = "ABC".toCharArray();
    private static final long MOD = 1_000_000_007L;

    public void main(Scanner sc) throws Exception {
        char s[] = sc.next().toCharArray();
        sc.close();

        int len = s.length;
        long data[][] = new long[len + 1][4];

        data[len][3] = 1;
        for (int i = len - 1; i >= 0; i--) {
            data[i][3] = (s[i] == '?' ? 3 : 1) * data[i + 1][3];
            data[i][3] %= MOD;
        }

        for (int i = len - 1; i >= 0; i--) {
            for (int j = 2; j >= 0; j--) {
                data[i][j] =
                    (s[i] == '?' ? 3 : 1) * data[i + 1][j]
                        + (s[i] == ABC[j] || s[i] == '?' ? 1 : 0) * data[i + 1][j + 1];
                data[i][j] %= MOD;
            }
        }

        System.out.println(data[0][0] % MOD);
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
    }
}