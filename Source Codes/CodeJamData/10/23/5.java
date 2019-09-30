import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(new File("Main.in"));
        PrintWriter out = new PrintWriter(new File("Main.out"));
        int tests = in.nextInt();
        
        final int MOD = 100003;
        int[][] f = new int[512][512];
        for (int m = 0; m < 512; m++) f[0][m] = 1;
        for (int n = 1; n < 512; n++) {
            for (int m = 1; m <= n; m++) {
                f[n][m] = 0;
                for (int k = 1; k <= m; k++) {
                    f[n][m] = (f[n][m] + f[n-k][m]) % MOD;
                }
            }
        }
        
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) System.out.print(f[i][j] + " ");
            System.out.println();
        }
        
        for (int test = 1; test <= tests; test++) {
            out.print("Case #" + test + ": ");
            int n = in.nextInt();
            /*
            int nn = (1 << (n - 2));
            int[] ord = new int[n+1];
            int ans = 0;
            for (int m = 0; m < nn; m++) {
                int p = 1;
                for (int i = 0; i <= n - 3; i++) if ((m & (1 << i)) != 0) {
                    ord[i+2] = p++;
                } else ord[i+2] = -1;
                ord[n] = p++;
                int x = n;
                while (x != 1 && x != -1) x = ord[x];
                if (x == 1) ans++;
            }
            out.println(ans);
            */
            int ans = 0;
            for (int h = 2; h <= n; h++) ans = (ans + f[n-1][h-1]) % MOD;
            out.println(ans);
        }
        out.close();
    }
}
