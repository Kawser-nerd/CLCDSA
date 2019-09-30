import java.io.*;
import java.util.*;
import java.util.regex.*;
import java.math.*;

import static java.lang.System.out;

public class FashionPolice {

    Kattio io;

    public void go() {
        io = new Kattio(System.in);
        int zz = io.nextInt();
        for (int zzz = 0; zzz < zz; zzz++) {
            int numJackets = io.nextInt();
            int numPants = io.nextInt();
            int numShirts = io.nextInt();
            int maxPairs = io.nextInt();
            int[][][] pairs = new int[3][][];
            pairs[0] = new int[numJackets][numPants];
            pairs[1] = new int[numPants][numShirts];
            pairs[2] = new int[numJackets][numShirts];
            int count = 0;
            boolean[][][] good = new boolean[numJackets][numPants][numShirts];
            for (int i = 0; i < numJackets; i++) {
                for (int e = 0; e < numPants; e++) {
                    for (int w = 0; w < Math.min(numShirts, maxPairs); w++) {
                        good[i][e][(i+e+w)%numShirts] = true;
                        count++;
                    }
                }
            }
//            if (numJackets*numPants*numShirts != count)
                if (numJackets*numPants*Math.min(numShirts, maxPairs) == count) {
                    io.printf("Case #%d: %d%n", zzz + 1, count);
                    for (int i = 0; i < numJackets; i++) {
                        for (int e = 0; e < numPants; e++) {
                            for (int w = 0; w < numShirts; w++) {
                                if (good[i][e][w]) {
                                    io.printf("%d %d %d%n", i + 1, e + 1, w + 1);
                                }
                            }
                        }
                    }
                }
        }

        io.flush();
        io.close();
    }

    public static void main(String[] args) {
        new FashionPolice().go();
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
