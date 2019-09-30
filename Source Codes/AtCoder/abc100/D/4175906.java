import java.util.*;

public class Main {

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        long[] x = new long[n];
        long[] y = new long[n];
        long[] z = new long[n];
        for (int i = 0; i < n; i++) {
            x[i] = sc.nextLong();
            y[i] = sc.nextLong();
            z[i] = sc.nextLong();
        }

        long[][] mm = new long[8][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 8; j++) {
                long kk = 0;
                if ((j & 4) == 0) {
                    kk += x[i];
                } else {
                    kk -= x[i];
                }

                if ((j & 2) == 0) {
                    kk += y[i];
                } else {
                    kk -= y[i];
                }

                if ((j & 1) == 0) {
                    kk += z[i];
                } else {
                    kk -= z[i];
                }
                mm[j][i] = kk;
            }
        }
        long ans = 0;
        for (int i = 0; i < 8; i++) {
            Arrays.sort(mm[i]);
            long tmp = 0;
            for (int j = 0; j < m; j++) {
                tmp += mm[i][n - j - 1];
            }
            ans = Math.max(ans, tmp);
        }

        System.out.println(ans);

    }

}