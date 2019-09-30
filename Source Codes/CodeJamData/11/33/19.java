package gcj.round1._11;

import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 *
 * @author epizend
 */
public class C {

    public static void main(String[] args) throws IOException {
        Kattio io = new Kattio(System.in, new FileOutputStream("a.out"));
        int T = io.getInt();
        int at = 0;
        CASE:
        while (at++ < T) {
            int N = io.getInt(), L = io.getInt(), H = io.getInt();
            int[] tones = new int[N];
            for (int i = 0; i < N; i++) {
                tones[i] = io.getInt();
            }
            NUM: for (int j = L; j <= H; j++) {
                for (int k = 0; k < N; k++) {
                    if (!(j % tones[k] == 0 || tones[k] % j == 0)) {
                        continue NUM;
                    }
                }
                System.out.println("Case #" + at + ": " + j);
                continue CASE;
            }
            System.out.println("Case #" + at + ": NO");
        }
    }

    static class Kattio extends PrintWriter {

        public Kattio(InputStream i) {
            super(new BufferedOutputStream(System.out));
            r = new BufferedReader(new InputStreamReader(i));
        }

        public Kattio(InputStream i, OutputStream o) {
            super(new BufferedOutputStream(o));
            r = new BufferedReader(new InputStreamReader(i));
        }

        public boolean hasMoreTokens() {
            return peekToken() != null;
        }

        public int getInt() {
            return Integer.parseInt(nextToken());
        }

        public double getDouble() {
            return Double.parseDouble(nextToken());
        }

        public long getLong() {
            return Long.parseLong(nextToken());
        }

        public String getWord() {
            return nextToken();
        }
        private BufferedReader r;
        private String line;
        private StringTokenizer st;
        private String token;

        private String peekToken() {
            if (token == null) {
                try {
                    while (st == null || !st.hasMoreTokens()) {
                        line = r.readLine();
                        if (line == null) {
                            return null;
                        }
                        st = new StringTokenizer(line);
                    }
                    token = st.nextToken();
                } catch (IOException e) {
                }
            }
            return token;
        }

        private String nextToken() {
            String ans = peekToken();
            token = null;
            return ans;
        }
    }
}
