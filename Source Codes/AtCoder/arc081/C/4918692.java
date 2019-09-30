import java.util.*;

public class Main {
    private static final int INF = 1000000000;

    public static void main(String[] args) {
        // read inputs
        Scanner in = new Scanner(System.in);
        String cs = in.next();
        final int N = cs.length();
        // System.out.printf("cs = %s\n", cs);

        // solve dp
        int[][] dpss = new int[N + 1][];
        for (int i = 0; i <= N; i++) {
            dpss[i] = new int[26];
        }
        // initialize
        for (int j = 0; j < 26; j++) {
            dpss[N][j] = 0;
        }
        // solve
        for (int i = N - 1; i >= 0; i--) {
            final char ci = cs.charAt(i);
            int jmin = 0;
            for (int j = 0; j < 26; j++) {
                if (dpss[i + 1][j] < dpss[i + 1][jmin]) {
                    jmin = j;
                }
            }
            for (int j = 0; j < 26; j++) {
                final char cj = (char) ((int) 'a' + j);
                if (ci == cj) {
                    dpss[i][j] = dpss[i + 1][jmin] + 1;
                } else {
                    dpss[i][j] = dpss[i + 1][j];
                }
            }
        }
        StringBuilder builder = new StringBuilder();
        int K = INF;
        char c = 'a';
        for (int j = 0; j < 26; j++) {
            if (dpss[0][j] < K) {
                K = dpss[0][j];
                c = (char) ((int) 'a' + j);
            }
        }
        int i = 0;
        for (int k = 0; k < K; k++) {
            final int j0 = (int) c - 'a';
            while (i < N && cs.charAt(i) != c) {
                i++;
            }
            if (i >= N) {
                break;
            }
            for (int j = 0; j < 26; j++) {
                final char cj = (char) ((int) 'a' + j);
                if (dpss[i][j0] == dpss[i + 1][j] + 1) {
                    builder.append(c);
                    c = cj;
                    break;
                }
            }
            i++;
        }
        builder.append(c);
        System.out.printf("%s\n", builder);
    }
}