// package agc.agc019;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        char[] a = in.nextToken().toCharArray();
        char[] b = in.nextToken().toCharArray();

        out.println(solve(a, b));
        out.flush();
    }

    private static int solve(char[] a, char[] b) {
        int n = a.length;
        boolean aHasOne = false;
        boolean bHasOne = false;
        for (int i = 0; i < n ; i++) {
            if (a[i] == '1') {
                aHasOne = true;
            }
            if (b[i] == '1') {
                bHasOne = true;
            }
        }
        if (!bHasOne) {
            return aHasOne ? -1 : 0;
        }

        int[] distancePlus = new int[n];
        int[] distanceMinus = new int[n];
        Arrays.fill(distanceMinus, n);
        Arrays.fill(distancePlus, n);

        int lastOne = -1;
        for (int i = 0 ; i < 2*n ; i++) {
            int idx = i%n;
            if (b[idx] == '1') {
                lastOne = i;
            }
            if (a[idx] == '1' && lastOne >= 0) {
                distanceMinus[idx] = Math.min(distanceMinus[idx], i-lastOne);
            }
        }
        lastOne = -1;
        for (int i = 2*n-1 ; i >= 0 ; i--) {
            int idx = i%n;
            if (b[idx] == '1') {
                lastOne = i;
            }
            if (a[idx] == '1' && lastOne >= 0) {
                distancePlus[idx] = Math.min(distancePlus[idx], lastOne-i);
            }
        }

        int minimumAnswer = Integer.MAX_VALUE;

        List<int[]> tp = new ArrayList<>();
        for (int lastOffset = 0 ; lastOffset < n ; lastOffset++) {
            int finalCost = 0;
            tp.clear();

            for (int i = 0 ; i < n ; i++) {
                int idx = (i + lastOffset) % n;
                if (b[idx] == '1') {
                    if (a[i] == '0') {
                        // need to flip here
                        finalCost++;
                    }
                } else {
                    if (a[i] == '1') {
                        // need to flip somewhere on the way
                        tp.add(new int[]{distancePlus[i], distanceMinus[i]});
                        finalCost++;
                    }
                }
            }

            // compute the best way-cost
            int wayCost = n + Math.min(lastOffset, n-lastOffset);

            // where to turn around ?
            Collections.sort(tp, (x, y) -> x[0] - y[0]);

            int tn = tp.size();
            int[] plusOrder = new int[tn];
            for (int i = 0; i < tn ; i++) {
                plusOrder[i] = tp.get(i)[0];
            }
            int[] minusMax = new int[tn+1];
            for (int i = tn-1 ; i >= 0 ; i--) {
                int[] mp = tp.get(i);
                minusMax[i] = Math.max(minusMax[i+1], mp[1]);
            }

//            debug("==");
//            debug(lastOffset, tn);
//            for (int[] t : tp) {
//                debug(t);
//            }
//            debug(plusOrder);
//            debug(minusMax);
//            debug("=");

            int head = 0;
            for (int maxGoPlus = 0 ; maxGoPlus < n ; maxGoPlus++) {
                while (head < tn && plusOrder[head] <= maxGoPlus) {
                    head++;
                }
                int maxGoMinus = minusMax[head];

                // go plus first
                {
                    int way0 = maxGoPlus * 2 + maxGoMinus;
                    int ct = (n-maxGoMinus)%n;
                    int diff = Math.min(Math.abs(ct - lastOffset), n-Math.abs(ct - lastOffset));
                    way0 += diff;
                    wayCost = Math.min(wayCost, way0);
                }


                // go minus first
                {
                    int way0 = maxGoMinus * 2 + maxGoPlus;
                    int ct = maxGoPlus;
                    int diff = Math.min(Math.abs(ct - lastOffset), n-Math.abs(ct - lastOffset));
                    way0 += diff;
                    wayCost = Math.min(wayCost, way0);
                }
            }

            minimumAnswer = Math.min(minimumAnswer, wayCost + finalCost);
        }
        return minimumAnswer;
    }

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