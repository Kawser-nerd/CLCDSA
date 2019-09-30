import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Comparator;
import java.util.NoSuchElementException;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author ogiekako
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        MyScanner in = new MyScanner(inputStream);
        MyPrintWriter out = new MyPrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, MyScanner in, MyPrintWriter out) {
            String A = in.next(), B = in.next();
            int n = A.length();
            int m = 0;
            for (char b : B.toCharArray()) {
                if (b == '1') m++;
            }
            if (m == 0) {
                out.println(A.equals(B) ? 0 : -1);
                return;
            }

            B = B + B + B + B + B;
            int[] bs = new int[m * 5];
            m = 0;
            for (int i = 0; i < B.length(); i++) {
                if (B.charAt(i) == '1') {
                    bs[m++] = i;
                }
            }
            int res = Integer.MAX_VALUE;
            for (int x = -n; x <= n; x++) {
                ArrayList<E> es = new ArrayList<E>();
                int add = 0;
                for (int i = 0; i < n; i++) {
                    if (A.charAt(i) == '1' && B.charAt(2 * n + i + x) == '0') {
                        add++;
                        E e = new E();
                        int k = Arrays.binarySearch(bs, 2 * n + i + x);
                        int l = -k - 2;
                        int r = -k - 1;
                        e.l = 2 * n + i - bs[l];
                        e.r = bs[r] - (2 * n + i);
                        if (bs[l] < Math.min(2 * n + i, 2 * n + i + x) && Math.max(2 * n + i, 2 * n + i + x) < bs[r]) {
                            es.add(e);
                        }
                    } else if (A.charAt(i) == '0' && B.charAt(2 * n + i + x) == '1') {
                        add++;
                    }
                }
                E zero = new E();
                zero.l = 0;
                zero.r = 0;
                es.add(zero);
                Collections.sort(es, Comparator.reverseOrder());
                int r = 0;
                for (E e : es) {
                    int l = e.l;
                    res = Math.min(res, add + Math.min(2 * l + r + Math.abs(r - x), 2 * r + l + Math.abs(l + x)));
                    r = Math.max(r, e.r);
                }
//            Debug.debug(res, es, x);
            }
            out.println(res);
        }

        class E implements Comparable<E> {
            int l;
            int r;


            public int compareTo(E o) {
                return l - o.l;
            }


            public String toString() {
                return l + " " + r;
            }

        }

    }

    static class MyPrintWriter {
        PrintWriter out;

        public MyPrintWriter(OutputStream outputStream) {
            out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public MyPrintWriter(Writer writer) {
            out = new PrintWriter(writer);
        }

        public void println(int a) {
            out.println(a);
        }

        public void close() {
            out.close();
        }

    }

    static class MyScanner {
        private final InputStream in;
        private static final int BUFSIZE = 65536;
        int bufLen;
        int bufPtr;
        byte[] buf = new byte[BUFSIZE];
        private char[] strBuf = new char[BUFSIZE];

        public MyScanner(InputStream in) {
            this.in = in;
        }

        public int read() {
            if (bufLen == -1)
                throw new InputMismatchException();
            if (bufPtr >= bufLen) {
                bufPtr = 0;
                try {
                    bufLen = in.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (bufLen <= 0)
                    return -1;
            }
            return buf[bufPtr++];
        }

        public String next() {
            int strLen = 0;
            int c;
            do {
                c = read();
                if (c == -1) throw new NoSuchElementException();
            } while (Character.isWhitespace(c));
            do {
                if (strLen + 1 >= strBuf.length) {
                    char[] tmp = new char[strBuf.length * 2];
                    System.arraycopy(strBuf, 0, tmp, 0, strBuf.length);
                    strBuf = tmp;
                }
                strBuf[strLen++] = (char) c;
                c = read();
            } while (c != -1 && !Character.isWhitespace(c));
            return new String(strBuf, 0, strLen);
        }

    }
}