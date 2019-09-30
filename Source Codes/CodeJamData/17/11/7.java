package gcj.gcj2017.round1;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int t = in.nextInt();
        for (int cs = 1 ; cs <= t ; cs++) {
            int n = in.nextInt();
            int m = in.nextInt();
            char[][] cake = new char[n][];
            for (int i = 0; i < n ; i++) {
                cake[i] = in.next().toCharArray();
            }
            char[][] answerCake = solve(cake);
            out.println(String.format("Case #%d:", cs));
            for (int i = 0; i < n ; i++) {
                out.println(String.valueOf(answerCake[i]));
            }
        }
        out.flush();
    }

    private static char[][] solve(char[][] cake) {
        int n = cake.length;
        int m = cake[0].length;

        char[] chs = new char[m+10];
        int[] pos = new int[m+10];

        int lastI = -1;
        for (int i = 0 ; i < n ; i++) {
            int pn = 0;
            for (int j = 0; j < m ; j++) {
                if (cake[i][j] != '?') {
                    chs[pn] = cake[i][j];
                    pos[pn] = j;
                    pn++;
                }
            }

            if (pn >= 1) {
                pos[pn++] = m;
                for (int pi = 0 ; pi < pn-1 ; pi++) {
                    int from = pi == 0 ? 0 : pos[pi];
                    int to = pos[pi+1];
                    for (int wi = from ; wi < to ; wi++) {
                        for (int hi = lastI + 1; hi <= i; hi++) {
                            cake[hi][wi] = chs[pi];
                        }
                    }
                }
                lastI = i;
            }
        }
        for (int i = lastI+1 ; i < n ; i++) {
            for (int j = 0; j < m; j++) {
                cake[i][j] = cake[i-1][j];
            }
        }
        return cake;
    }

    static void debug(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }
}



