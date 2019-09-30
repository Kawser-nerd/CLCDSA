import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class D {
    FastScanner in;
    PrintWriter out;

    public void solve() throws IOException {
        int testNo = in.nextInt();
        for (int test = 1; test <= testNo; test++) {
            System.out.println("Test " + test);

            int[] map = new int[128];
            map['o'] = '0';
            map['i'] = '1';
            map['e'] = '3';
            map['a'] = '4';
            map['s'] = '5';
            map['t'] = '7';
            map['b'] = '8';
            map['g'] = '9';

            int k = in.nextInt();
            String s = in.next();
            int[] di = new int[128]; 
            int[] dx = new int[128];
            int[][] a = new int[128][128]; 
            int e = 0;
            for (int i = 0; i < s.length() - 1; i++) {
                char c1 = s.charAt(i);
                char c2 = s.charAt(i + 1);
                a[c1][c2] = 1;
                if (map[c1] != 0) {
                    a[map[c1]][c2] = 1;
                }
                if (map[c2] != 0) {
                    a[c1][map[c2]] = 1;
                }
                if (map[c1] != 0 && map[c2] != 0) {
                    a[map[c1]][map[c2]] = 1;
                }
            }
            for (int i = 0; i < 128; i++) {
                for (int j = 0; j < 128; j++) {
                    e += a[i][j];
                    dx[i] += a[i][j];
                    di[j] += a[i][j];
                }
            }
            boolean add = false;
            for (int i = 0; i < 128; i++) {
                if (dx[i] > di[i]) {
                    e += dx[i] - di[i];
                    add = true;
                }
            }
            if (!add) {
                e++;
            }

            out("Case #%d: %d\n", test, e);
        }
    }
    
    void out(String format, Object... s) {
        System.out.printf(format, s);
        out.printf(format, s);
        out.flush();
    }

    public void run() {
        try {
            in = new FastScanner(new File("D-small-attempt1.in"));
            out = new PrintWriter(new File("D-small-attempt1.out"));

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] arg) {
        new D().run();
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