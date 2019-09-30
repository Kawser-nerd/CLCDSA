package gcj.round1._11;

import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

/**
 *
 * @author epizend
 */
public class B {

    public static void main(String[] args) throws Exception {
        Kattio io = new Kattio(new FileInputStream("/home/epizend/Downloads/B-large (1).in"),new FileOutputStream("b.out"));
        //Kattio io = new Kattio(System.in);
        int T = io.getInt();
        int at = 0;
        CASE: while (at++ < T) {
            long L = io.getLong();
            long t = io.getLong();
            long N = io.getLong();
            int C = io.getInt();
            //io.println("case " + at + " " + L + " " + t + " " + N + " " + C);
            long[] cc = new long[C];
            for (int i = 0; i < C; i++) {
                cc[i] = io.getInt();
            }
            //Resa mellan i och i+1
            long travelled = 0;
            PriorityQueue<Long> q = new PriorityQueue<Long>(10000, new Comparator<Long>() {

                @Override
                public int compare(Long t, Long t1) {
                    return t1.compareTo(t);
                }
            });
            int i = 0;
            for (i = 0; i < N; i++) {
                if (travelled + (cc[i % C] * 2) > t) {
                    break;
                } else {
                    travelled += cc[i % C] * 2;
                }
                if (i == N - 1) {
                    io.println("Case #" + at + ": " + travelled);
                    continue CASE;
                }
            }

            //io.println("before " + travelled);
            long psleft = (cc[i % C]) - (t - travelled) / 2;
            travelled += (t - travelled);

            q.add(psleft);
            i++;
            for (; i < N; i++) {
                q.add(cc[i % C]);
            }
            while (!q.isEmpty()) {
                long dist = q.poll();
                //io.println("dist "+dist+" = "+dist * (L > 0 ? 1 : 2));
                travelled += dist * (L > 0 ? 1 : 2);
                L--;
            }
            io.println("Case #" + at + ": " + travelled);
        }
        io.flush();
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
