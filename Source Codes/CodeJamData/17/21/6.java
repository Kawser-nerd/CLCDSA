import java.io.*;
import java.util.*;
import java.util.regex.*;
import java.math.*;

import static java.lang.System.out;

public class Round1BA {

    Kattio io;

    public void go() {
        try {
            io = new Kattio(System.in, new FileOutputStream(new File("out.txt")));
            int zzz = io.nextInt();
            for (int zz = 0; zz < zzz; zz++) {
                int dest = io.nextInt();
                int numHorses = io.nextInt();
                int[][] horses = new int[numHorses][2];
                for (int i = 0; i < numHorses; i++) {
                    horses[i][0] = io.nextInt();
                    horses[i][1] = io.nextInt();
                }
                Arrays.sort(horses, (one, two) -> two[0] - one[0]);
                double maxTime = 0;
                for (int i = 0; i < numHorses; i++) {
                    maxTime = Math.max(maxTime, (double) (dest - horses[i][0]) / horses[i][1]);
                }
                io.printf("Case #%d: %.6f%n", zz + 1, dest / maxTime);
            }

            io.flush();
            io.close();
        } catch (IOException e){
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Round1BA().go();
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
