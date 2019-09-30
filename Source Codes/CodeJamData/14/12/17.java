
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File(B.class.getSimpleName() + ".in"));
        PrintWriter out = new PrintWriter(new File(B.class.getSimpleName() + ".out"));
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new B().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }

    private String solve(Scanner in) {
        int n = in.nextInt();
        init(n, 2 * n);
        for (int i = 0; i < n - 1; i++) {
            int x = in.nextInt() - 1;
            int y = in.nextInt() - 1;
            addEdge(x, y);
            addEdge(y, x);
        }
        int res = n;
        for (int i = 0; i < n; i++) {
            for (int[] ints : maxChild) {
                Arrays.fill(ints, -1);
            }
            dfs(i, -1);
            res = Math.min(res, n - maxW[i]);
        }
        return "" + res;
    }

    private int[] edgeTo;
    private int edgeNum = 0;
    private int[] edgeNext;
    private int[] edgeFirst;
    int[] maxW;
    int[][] maxChild;

    private void dfs(int i, int p) {
        int j = edgeFirst[i];
        maxW[i] = 1;
        while (j >= 0) {
            int v = edgeTo[j];
            if (v != p) {
                dfs(v, i);
                for (int d = 0; d < maxChild.length; d++) {
                    if (maxChild[d][i] == -1 || maxW[maxChild[d][i]] < maxW[v]) {
                        for (int dd = maxChild.length - 1; dd > d; dd--) {
                            maxChild[dd][i] = maxChild[dd - 1][i];
                        }
                        maxChild[d][i] = v;
                        break;
                    }
                }
            }
            j = edgeNext[j];
        }
        if (maxChild[1][i] >= 0) {
            maxW[i] = maxW[maxChild[0][i]] + maxW[maxChild[1][i]] + 1;
        }
    }

    private void init(int n, int m) {
        edgeNum = 0;
        edgeTo = new int[m];
        edgeNext = new int[m];
        edgeFirst = new int[n];
        Arrays.fill(edgeFirst, -1);
        maxChild = new int[3][n];
        maxW = new int[n];
    }

    private void addEdge(int x, int y) {
        edgeTo[edgeNum] = y;
        edgeNext[edgeNum] = edgeFirst[x];
        edgeFirst[x] = edgeNum;
        edgeNum++;
    }
}