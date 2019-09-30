import java.io.*;
import java.util.*;
import java.util.regex.*;
import java.math.*;

import static java.lang.System.out;

public class Slides {

    Kattio io;

    public void go() {
        io = new Kattio(System.in);
        int zz = io.nextInt();
        for (int zzz = 0; zzz < zz; zzz++) {
            int numBuildings = io.nextInt();
            long neededWays = io.nextLong();
            int length = length(neededWays-1);
            if (length > numBuildings-2) {
                io.printf("Case #%d: IMPOSSIBLE%n", zzz+1);
                continue;
            }
            int[][] mat = new int[numBuildings][numBuildings];
            for (int i = 1; i < mat.length; i++) {
                mat[0][i] = 1;
            }
            int chLength = length;
            for (int i = mat.length-1-chLength; chLength > 0; i++) {
                for (int e = mat.length-chLength; e < mat.length; e++) {
                    mat[i][e] = 1;
                }
                chLength--;
            }
            neededWays--;
            int b = mat.length-1-length;
            while (neededWays > 0) {
                if (neededWays%2 == 0) {
                    mat[b][mat.length-1] = 0;
                }
                neededWays /= 2;
                b++;
            }
            io.printf("Case #%d: POSSIBLE%n", zzz+1);
            for (int i = 0; i < mat.length; i++) {
                for (int e = 0; e < mat.length; e++) {
                    io.print(mat[i][e]);
                }
                io.println();
            }
        }

        io.flush();
        io.close();
    }

    public int length(long n) {
        int len = 0;
        while (n > 0) {
            len++;
            n /= 2;
        }
        return len;
    }

    public static void main(String[] args) {
        new Slides().go();
    }

    private class Kattio extends PrintWriter {

        private BufferedReader r;
        private String line;
        private StringTokenizer st;
        private String token;

        public Kattio(InputStream i) {
            super(new BufferedOutputStream(System.out));
            r = new BufferedReader(new InputStreamReader(i));
        }

        public Kattio(InputStream i, OutputStream o) {
            super(new BufferedOutputStream(o));
            r = new BufferedReader(new InputStreamReader(i));
        }

        public boolean hasNext() {
            return peekToken() != null;
        }

        public int nextInt() {
            return Integer.parseInt(nextToken());
        }

        public double nextDouble() {
            return Double.parseDouble(nextToken());
        }

        public long nextLong() {
            return Long.parseLong(nextToken());
        }

        public String next() {
            return nextToken();
        }

        public String nextLine() {
            token = null;
            st = null;
            try {
                return r.readLine();
            } catch (IOException e) {
                return null;
            }
        }

        private String peekToken() {
            if (token == null)
                try {
                    while (st == null || !st.hasMoreTokens()) {
                        line = r.readLine();
                        if (line == null) return null;
                        st = new StringTokenizer(line);
                    }
                    token = st.nextToken();
                } catch (IOException e) {
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
