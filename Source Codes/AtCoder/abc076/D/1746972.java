import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Pradyumn
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastReader in = new FastReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, FastReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] time = new int[n];
            for (int i = 0; i < n; i++) time[i] = in.nextInt();
            int[] maxV = new int[n + 1];
            for (int i = 0; i < n; i++) maxV[i] = in.nextInt();
            maxV[n] = 0;
            double distance = 0;
            double curV = 0;
            int tOld = 0;
            for (int i = 0; i < n; i++) {
                //Train will accelerate for some period of time, reach the cap for some period of time, and decelerate.
                int tNew = tOld; //tTerm = terminal velocity
                double tTerm = tOld + maxV[i] - curV;
                double accTime = tOld + time[i];
                for (int j = i + 1; j <= n; j++) { //When do we need to decelerate to reach this speed?
                    tNew += time[j - 1];
                    int newGoal = maxV[j]; //Need to be at newGoal by time tNew
                    //curV + (tRes - tOld) - (tNew - tRes) = newGoal.  2 * tRes = newGoal + tOld + tNew - curV
                    double tRes = -1 * curV;
                    tRes += tOld + tNew + newGoal;
                    tRes /= 2;
                    if (tRes > tTerm) {
                        //curV + (tTerm - tOld) - (tNew - tRes) = newGoal.
                        //tRes = newGoal + tOld + tNew - curV - tTerm
                        tRes = -1 * curV + -1 * tTerm;
                        tRes += newGoal + tOld + tNew;
                    }

                    if (tRes < accTime) accTime = tRes;
                }
                tNew = tOld + time[i];
                if (accTime > tTerm) {
                    //Accelerating tOld through tTerm
                    //No change tTerm through accTime
                    //Decelerating accTime through tNew
                    distance += curV * (tTerm - tOld) + (tTerm - tOld) * (tTerm - tOld) / 2;
                    curV += tTerm - tOld;
                    distance += curV * (accTime - tTerm);
                    distance += curV * (tNew - accTime) - (tNew - accTime) * (tNew - accTime) / 2;
                    curV -= tNew - accTime;
                } else {
                    //Accelerating tOld through accTime
                    //Decelerating accTime through tNew
                    distance += curV * (accTime - tOld) + (accTime - tOld) * (accTime - tOld) / 2;
                    curV += accTime - tOld;
                    distance += curV * (tNew - accTime) - (tNew - accTime) * (tNew - accTime) / 2;
                    curV -= tNew - accTime;
                }

            }
            out.printf("%.15f\n", distance);
        }

    }

    static class FastReader {
        private InputStream stream;
        private byte[] buf = new byte[8192];
        private int curChar;
        private int pnumChars;
        private FastReader.SpaceCharFilter filter;

        public FastReader(InputStream stream) {
            this.stream = stream;
        }

        private int pread() {
            if (pnumChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= pnumChars) {
                curChar = 0;
                try {
                    pnumChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (pnumChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int nextInt() {
            int c = pread();
            while (isSpaceChar(c))
                c = pread();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = pread();
            }
            int res = 0;
            do {
                if (c == ',') {
                    c = pread();
                }
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = pread();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        private boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }

        private static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        private interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }
}