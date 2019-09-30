import java.io.*;
import java.util.Arrays;
import java.util.Locale;
import java.util.StringTokenizer;

public class B {
    FastScanner in;
    PrintWriter out;
    
    int can(double fs, double cs, double ft, double ct, double wh) {
        if (fs > ct - 50 || wh > ct - 50 || ft > ct - 50) {
            return -1;
        }
        if (ft > cs - 50) {
            return -1;
        }
        if (wh >= fs + 20) {
            return 10;
        }
        return 100;
    }
    
    class Cell implements Comparable<Cell> {
        int r;
        int c;
        
        int time;

        public int compareTo(Cell o) {
            if (time != o.time) {
                return time - o.time;
            }
            return r * 1000 + c - (o.r * 1000 + o.c);
        }
    }

    public void solve(int testNo) throws IOException {
        System.out.println("Solving case " + testNo);

        double wh = in.nextInt();
        int rn = in.nextInt();
        int cn = in.nextInt();
        int[][] c = new int[rn][cn];
        for (int i = 0; i < rn; i++) {
            for (int j = 0; j < cn; j++) {
                c[i][j] = in.nextInt();
            }
        }
        int[][] f = new int[rn][cn];
        for (int i = 0; i < rn; i++) {
            for (int j = 0; j < cn; j++) {
                f[i][j] = in.nextInt();
            }
        }

        int[][] t = new int[rn][cn];
        for (int i = 0; i < rn; i++) {
            for (int j = 0; j < cn; j++) {
                t[i][j] = Integer.MAX_VALUE;
            }
        }
        
        t[0][0] = 0;
        
        int[] dr = new int[]{-1, 0, 1, 0};
        int[] dc = new int[]{0, 1, 0, -1};
        
        boolean changed = true;
        while (changed) {
            changed = false;
            for (int i = 0; i < rn; i++) {
                for (int j = 0; j < cn; j++) {
                    if (t[i][j] == 0) {
                        for (int k = 0; k < 4; k++) {
                            int ni = i + dr[k];
                            int nj = j + dc[k];
                            if (0 <= ni && ni < rn && 0 <= nj && nj < cn && t[ni][nj] == Integer.MAX_VALUE) {
                                if (can(f[i][j], c[i][j], f[ni][nj], c[ni][nj], wh) > 0) {
                                    t[ni][nj] = 0;
                                    changed = true;
                                }
                            }
                        }
                    }
                }
            }
        }
        
        changed = true;
        int time = 0;
        while (changed) {
            changed = false;
            boolean existSlow = false;
            for (int i = 0; i < rn; i++) {
                for (int j = 0; j < cn; j++) {
                    if (t[i][j] <= time) {
                        for (int k = 0; k < 4; k++) {
                            int ni = i + dr[k];
                            int nj = j + dc[k];
                            if (0 <= ni && ni < rn && 0 <= nj && nj < cn) {
                                int d = can(f[i][j], c[i][j], f[ni][nj], c[ni][nj], wh); 
                                if (d > 0 && time + d < t[ni][nj]) {
                                    t[ni][nj] = time + d;
                                    changed = true;
                                }
                            }
                        }
                    } else if (t[i][j] != Integer.MAX_VALUE) {
                        existSlow = true;
                    }
                }
            }
            if (!changed && (wh > 0 || existSlow)) {
                changed = true;
                wh -= 1;
                time++;
            }
        }

//        System.out.println(Arrays.deepToString(t));

        out.println("Case #" + testNo + ": " + 0.1 * t[rn - 1][cn - 1]);
        System.out.println("Case #" + testNo + ": " + 0.1 * t[rn - 1][cn - 1]);
    }

    public void run() {
        try {
            in = new FastScanner(new File("B-large.in"));
            out = new PrintWriter(new File("B-large.out"));

            long time = System.currentTimeMillis();
            int testNo = in.nextInt();
            for (int test = 0; test < testNo; test++) {
                solve(test + 1);
                System.out.println((System.currentTimeMillis() - time) + " passed");
                out.flush();
            }

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] arg) {
        Locale.setDefault(Locale.US);
        new B().run();
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File file) throws IOException {
            br = new BufferedReader(new FileReader(file));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                    return "";
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }
}