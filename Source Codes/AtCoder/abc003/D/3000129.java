import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author mikit
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        DAtCoder solver = new DAtCoder();
        solver.solve(1, in, out);
        out.close();
    }

    static class DAtCoder {
        private static final int MOD = (int) 1e9 + 7;

        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int r = in.nextInt(), c = in.nextInt();
            int x = in.nextInt(), y = in.nextInt();
            int d = in.nextInt(), l = in.nextInt();
            int f = d + l;
            int s = x * y;

            long[][] nck = new long[s + 1][s + 1];
            nck[0][0] = 1;
            for (int n = 1; n <= s; n++) {
                nck[n][0] = 1;
                for (int k = 1; k <= n; k++) {
                    nck[n][k] = (nck[n - 1][k - 1] + nck[n - 1][k]) % MOD;
                }
            }

            // ???x,y?????????????????
            long ans = (r - x + 1) * (c - y + 1) * nck[f][d] % MOD;

            // ?????????????????
            if (f == s) {
                out.println(ans);
                return;
            }

            // ????????: ?????????????????
            // ???????????=> A
            // ???????????=> B
            // ???????????=> C
            // ???????????=> D
            // ???????? A&B&C&D ??????
            // A&B&C&D = U - !A|!B|!C|!D
            //         = U - (!A + !B + !C + !D)
            //             + (!A&!B + !A&!C + !A&!D + !B&!C + !B&!D + !C&!D)
            //             - (!A&!B&!C + !B&!C&!D + !C&!D&!A + !D&!A&!B)
            //             + (!A&!B&!C&!D)
            long u = nck[s][f];
            long nA = nck[(x - 1) * y][f], nB = nck[x * (y - 1)][f];
            long nAB = nck[(x - 1) * (y - 1)][f], nAC = nck[Math.max(x * (y - 2), 0)][f], nBD = nck[Math.max((x - 2) * y, 0)][f];
            long nABC = nck[Math.max((x - 2) * (y - 1), 0)][f], nBCD = nck[Math.max((x - 1) * (y - 2), 0)][f];
            long nABCD = nck[Math.max((x - 2) * (y - 2), 0)][f];
            long theABCD = u - (nA + nB + nA + nB)
                    + (nAB + nAC + nAB + nAB + nBD + nAB)
                    - (nABC + nBCD + nABC + nBCD)
                    + nABCD;
            while (theABCD < 0) {
                theABCD += MOD;
            }
            out.println(ans * theABCD % MOD);
        }

    }
}