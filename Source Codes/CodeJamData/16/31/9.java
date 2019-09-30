import java.io.*;
import java.util.*;
import java.util.regex.*;
import java.math.*;

import static java.lang.System.out;

public class SenateEvacuation {

    Kattio io;

    public void go() {
        io = new Kattio(System.in);
        int zz = io.nextInt();
        for (int zzz = 0; zzz < zz; zzz++) {
            int numGroups = io.nextInt();
            int numSenators = 0;
            int[] senators = new int[numGroups];
            for (int i = 0; i < numGroups; i++) {
                senators[i] = io.nextInt();
                numSenators += senators[i];
            }
            io.printf("Case #%d:", zzz+1);
            while (numSenators > 2) {
                int maxIndex = 0;
                int max = 0;
                int numLargest = 0;
                for (int i = 0; i < numGroups; i++) {
                    if (senators[i] > max) {
                        max = senators[i];
                        maxIndex = i;
                        numLargest = 1;
                    } else if (senators[i] == max) {
                        numLargest++;
                    }
                }
                if (numLargest == 1 || max == 1) {
                    senators[maxIndex]--;
                    numSenators--;
                    io.printf(" %s", (char) (maxIndex + 'A'));
                } else {
                    int count = 0;
                    io.print(" ");
                    for (int i = 0; i < numGroups && count < 2; i++) {
                        if (senators[i] == max) {
                            count++;
                            io.print((char)(i+'A'));
                            senators[i]--;
                            numSenators--;
                        }
                    }
                }
            }
            io.print(" ");
            for (int i = 0; i < numGroups; i++) {
                if (senators[i] == 1) {
                    io.print((char)(i+'A'));
                }
            }
            io.println();
        }

        io.flush();
        io.close();
    }

    public static void main(String[] args) {
        new SenateEvacuation().go();
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
