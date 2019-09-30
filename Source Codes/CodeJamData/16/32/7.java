package Round1;

import java.io.*;

/**
 * @auther chao
 * @date 16/5/8
 */
public class B {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("/Users/chao/Downloads/B-large.in"));
        //BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        FileWriter out = new FileWriter("/Users/chao/Desktop/B-large.txt");
        //PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
        String s = in.readLine();
        int m = Integer.parseInt(s);
        for (int cases = 1; cases <= m; cases++) {
            String[] ss = in.readLine().split(" ");
            int B = Integer.parseInt(ss[0]);
            long M = Long.parseLong(ss[1]);
            out.write("Case #" + cases + ": ");
            int n = B;
            long max = pow(B-2);
            if (max >= M) {
                out.write("POSSIBLE\n");
                int[][] map = new int[n][n];
                for (int i = 1; i < n; i++) {
                    for (int j = i + 1; j < n; j++) {
                        map[i][j] = 1;
                    }
                }
                for (int k = 1; k < n; k++) {
                    if (k != n-1) max = max/2;
                    if (max <= M) {
                        M-=max;
                        map[0][k] = 1;
                    }
                }
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        out.write(""+map[i][j]);
                    }
                    out.write("\n");
                }
            } else {
                out.write("IMPOSSIBLE\n");
            }
        }
        in.close();
        out.flush();
        out.close();
    }
    private static long pow(int n) {
        long x = 1;
        for (int i = 0; i < n; i++) {
            x*=2;
        }
        return x;
    }

}
