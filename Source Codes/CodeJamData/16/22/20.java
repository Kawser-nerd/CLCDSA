import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        InputStream inputStream;
        try {
            final String regex = "B-(small|large).*[.]in";
            File directory = new File(".");
            File[] candidates = directory.listFiles(new FilenameFilter() {
                public boolean accept(File dir, String name) {
                    return name.matches(regex);
                }
            });
            File toRun = null;
            for (File candidate : candidates) {
                if (toRun == null || candidate.lastModified() > toRun.lastModified())
                    toRun = candidate;
            }
            inputStream = new FileInputStream(toRun);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        OutputStream outputStream;
        try {
            outputStream = new FileOutputStream("b.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskB solver = new TaskB();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
//        for (int it = 0; it < 100; ++it) {
//            int n = 5;
//            String a = rand(n);
//            String b = rand(n);
//            String[] r1 = slow(a, b);
//            String[] r2 = fast(a, b);
//            if (r1[0].equals(r2[0]) && r1[1].equals(r2[1])) {
//                System.err.print(".");
//            } else {
//                System.err.printf("Fail: %s %s, %s %s, %s %s\n", a, b, r1[0], r1[1], r2[0], r2[1]);
//            }
//        }

            String a = in.next();
            String b = in.next();
            String[] res = fast(a, b);
            out.printf("Case #%d: %s %s\n", testNumber, res[0], res[1]);
        }

        String[] fast(String a, String b) {
            String[] res = new String[2];
            res[0] = minimize(a);
            res[1] = maximize(b);
            for (int p = 0; p <= a.length(); ++p) {
                String x = match(a, b, p);
                String y = match(b, a, p);
                if (x.length() > 0 && y.length() > 0) {
                    check(res, minimize(x), maximize(y));
                    check(res, maximize(x), minimize(y));
                }
            }
            for (int p = 0; p < a.length(); ++p) {
                String x = match(a, b, p);
                String y = match(b, a, p);
                if (x.length() > 0 && y.length() > 0) {
                    for (int xd = 0; xd <= 9; ++xd) {
                        for (int yd = xd - 1; yd <= xd + 1; ++yd) {
                            String x2 = match(x, p, xd);
                            String y2 = match(y, p, yd);
                            if (x2.length() > 0 && y2.length() > 0) {
                                check(res, minimize(x2), maximize(y2));
                                check(res, maximize(x2), minimize(y2));
                            }
                        }
                    }
                }
            }
            return res;
        }

        String match(String a, int pref, int digit) {
            if (digit < 0 || digit > 9) {
                return "";
            }
            char c = a.charAt(pref);
            if (c != '?' && c != digit + '0') {
                return "";
            }
            c = (char) (digit + '0');
            String res = "";
            res += a.substring(0, pref);
            res += c;
            res += a.substring(pref + 1);
            if (res.length() != a.length()) {
                System.err.println("digit replace failed");
            }
            return res;
        }

        String match(String a, String b, int pref) {
            String res = "";
            for (int i = 0; i < pref; ++i) {
                char ca = a.charAt(i);
                char cb = b.charAt(i);
                if (ca == '?') {
                    if (cb == '?') {
                        ca = '0';
                    } else {
                        ca = cb;
                    }
                } else {
                    if (cb != '?' && cb != ca) {
                        return "";
                    }
                }
                res += ca;
            }
            for (int i = pref; i < a.length(); ++i) {
                res += a.charAt(i);
            }
            return res;
        }

        void check(String[] a, String sx1, String sx2) {
            long a1 = toLong(a[0]);
            long a2 = toLong(a[1]);
            long x1 = toLong(sx1);
            long x2 = toLong(sx2);
            long ad = Math.abs(a1 - a2);
            long xd = Math.abs(x1 - x2);
            if (ad > xd || (ad == xd && a1 > x1) || (ad == xd && a1 == x1 && a2 > x2)) {
                a[0] = sx1;
                a[1] = sx2;
            }
        }

        String minimize(String s) {
            String res = "";
            for (char c : s.toCharArray()) {
                if (c == '?') {
                    c = '0';
                }
                res += c;
            }
            return res;
        }

        String maximize(String s) {
            String res = "";
            for (char c : s.toCharArray()) {
                if (c == '?') {
                    c = '9';
                }
                res += c;
            }
            return res;
        }

        long toLong(String s) {
            long res = 0;
            for (char c : s.toCharArray()) {
                if (c == '?') {
                    System.err.println("bad string");
                }
                res = res * 10 + (c - '0');
            }
            return res;
        }

    }

    static class InputReader {
        BufferedReader bufReader;
        StringTokenizer stringTokenizer;
        boolean isEof = false;

        public InputReader(InputStream stream) {
            bufReader = new BufferedReader(new InputStreamReader(stream));
        }

        public String next() {
            while (stringTokenizer == null || !stringTokenizer.hasMoreTokens()) {
                try {
                    String line = bufReader.readLine();
                    if (line == null) {
                        isEof = true;
                        return null;
                    }
                    stringTokenizer = new StringTokenizer(line);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
            }
            return stringTokenizer.nextToken();
        }

    }
}

