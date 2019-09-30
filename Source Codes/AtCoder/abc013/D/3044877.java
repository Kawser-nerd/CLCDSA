import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.stream.IntStream;
import java.util.List;
import java.util.Arrays;
import java.util.Scanner;
import java.util.ArrayList;

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
        D solver = new D();
        solver.solve(1, in, out);
        out.close();
    }

    static class D {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            /* ??????? */
            int n = in.nextInt(), m = in.nextInt(), d = in.nextInt();
            int[] uni = IntStream.range(0, n).toArray();
            for (int i = 0; i < m; i++) {
                int a = in.nextInt();
                uni[a - 1] ^= uni[a];
                uni[a] ^= uni[a - 1];
                uni[a - 1] ^= uni[a];
            }

            /* ?????????????????? */
            List<List<Integer>> cys = new ArrayList<>();
            int[] cyd = new int[n];
            int[] sub = new int[n];
            Arrays.fill(cyd, -1);
            for (int i = 0; i < n; i++) {
                if (cyd[i] >= 0) {
                    continue;
                }
                List<Integer> cy = new ArrayList<>();
                cyd[i] = cys.size();
                sub[i] = 0;
                cy.add(i);

                int c = i;
                while ((c = uni[c]) != i) {
                    cyd[c] = cys.size();
                    sub[c] = cy.size();
                    cy.add(c);
                }
                cys.add(cy);
            }

            /* ????????? */
            int[] ans = new int[n];
            for (int i = 0; i < n; i++) {
                List<Integer> cy = cys.get(cyd[i]);
                ans[cy.get((sub[i] + d) % cy.size())] = i + 1;
            }
            for (int i = 0; i < n; i++) {
                out.println(ans[i]);
            }
        }

    }
}