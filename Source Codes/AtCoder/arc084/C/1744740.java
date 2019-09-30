// package arc.arc084;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        k = in.nextInt();
        n = in.nextInt();


        int[] ret = new int[n];
        if (k == 1) {
            for (int i = 0; i < (n+1) / 2; i++) {
                ret[i] = 1;
            }
        } else if (k % 2 == 0) {
            ret[0] = k / 2;
            for (int i = 1 ; i < n ; i++) {
                ret[i] = k;
            }
        } else {
            for (int i = 0; i < n ; i++) {
                ret[i] = (k+1)/2;
            }
            long shouldBack = n/2;

            int pos = n-1;
            while (shouldBack > 0) {
                shouldBack--;
                ret[pos]--;
                if (ret[pos] == 0) {
                    pos--;
                } else {
                    for (int tp = pos+1 ; tp < n ; tp++) {
                        ret[tp] = k;
                    }
                    pos = n-1;
                }
            }
        }

        for (int i = 0; i < n ; i++) {
            if (ret[i] == 0) {
                break;
            }
            if (i >= 1) {
                out.print(' ');
            }
            out.print(ret[i]);
        }

        out.println();
        out.flush();
//
//         solveBF();
    }

    static void solveBF() {
        dfs(new ArrayList<>());

        Collections.sort(list, (o1, o2) -> {
            int l1 = o1.size();
            int l2 = o2.size();
            for (int i = 0; i < Math.min(l1, l2) ; i++) {
                int d = o1.get(i) - o2.get(i);
                if (d != 0) {
                    return d;
                }
            }
            return l1 - l2;
        });

        int cnt = 0;
        debug(list.get(list.size() / 2));
    }


    static int n;
    static int k;

    static void dfs(List<Integer> ho) {
        if (ho.size() > n) {
            return;
        }
        list.add(ho);
        for (int l = 1 ; l <= k ; l++) {
            List<Integer> ll = new ArrayList<>(ho);
            ll.add(l);
            dfs(ll);
        }
    }

    static List<List<Integer>> list = new ArrayList<>();

    public static void debug(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }

    public static class InputReader {
        private static final int BUFFER_LENGTH = 1 << 12;
        private InputStream stream;
        private byte[] buf = new byte[BUFFER_LENGTH];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        private int next() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public char nextChar() {
            return (char) skipWhileSpace();
        }

        public String nextToken() {
            int c = skipWhileSpace();
            StringBuilder res = new StringBuilder();
            do {
                res.append((char) c);
                c = next();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public int nextInt() {
            return (int) nextLong();
        }

        public long nextLong() {
            int c = skipWhileSpace();
            long sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = next();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = next();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public double nextDouble() {
            return Double.valueOf(nextToken());
        }

        int skipWhileSpace() {
            int c = next();
            while (isSpaceChar(c)) {
                c = next();
            }
            return c;
        }

        boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
    }
}