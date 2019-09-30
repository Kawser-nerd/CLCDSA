import sun.net.ftp.FtpProtocolException;
import sun.reflect.generics.tree.ArrayTypeSignature;

import javax.xml.soap.Node;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C {

    int n, m, k;
    private int[] ne;
    private int[][] e;
    private int[] p;
    private boolean[] z;
    private int[] zz;

    private String solve(Scanner in) {
        n = in.nextInt();
        m = in.nextInt();
        k = n * m;

        e = new int[k][9];
        ne = new int[k];

        for (int i = 0; i < n; i++) {
            String s = in.next();
            for (int j = 0; j < m; j++) {
                char c = s.charAt(j);
                if (c == '|') {
                    addEdge(i, j, i - 1, j);
                    addEdge(i, j, i + 1, j);
                }
                if (c == '-') {
                    addEdge(i, j, i, j - 1);
                    addEdge(i, j, i, j + 1);
                }
                if (c == '/') {
                    addEdge(i, j, i - 1, j + 1);
                    addEdge(i, j, i + 1, j - 1);
                }
                if (c == '\\') {
                    addEdge(i, j, i - 1, j - 1);
                    addEdge(i, j, i + 1, j + 1);
                }
            }
        }

        p = new int[k];
        z = new boolean[k];
        Arrays.fill(p, -1);

        for (int i = 0; i < k; i++) {
            Arrays.fill(z, false);
            if (!dfs(i)) {
                return "0";
            }
        }

        zz = new int[k];
        for (int i = 0; i < k; i++) {
            dfs2(i);
        }

//        System.out.println(count);

        long res = 1;
        for (int i = 0; i < count; i++) {
            res *= 2;
            res %= 1000003;
        }

        return "" + res;
    }

    int count;

    private void dfs2(int i) {
        if (zz[i] == 2) return;
        if (zz[i] == 1) {
            count++;
            return;
        }
        zz[i] = 1;
        for (int j = 0; j < ne[i]; j++) {
            int ii = e[i][j];
            if (p[ii] != i) {
                dfs2(p[ii]);
            }
        }
        zz[i] = 2;
    }

    private boolean dfs(int i) {
        if (z[i]) return false;
        z[i] = true;
        for (int j = 0; j < ne[i]; j++) {
            int ii = e[i][j];
            if (p[ii] == -1) {
                p[ii] = i;
                return true;
            } else {
                if (dfs(p[ii])) {
                    p[ii] = i;
                    return true;
                }
            }
        }
        return false;
    }

    private void addEdge(int i, int j, int i1, int j1) {
        if (i1 < 0) i1 += n;
        if (i1 >= n) i1 -= n;
        if (j1 < 0) j1 += m;
        if (j1 >= m) j1 -= m;
        int a = i * m + j;
        int b = i1 * m + j1;
        e[a][ne[a]++] = b;
    }


    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("input.txt"));
        PrintWriter out = new PrintWriter("output.txt");
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new C().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }

}