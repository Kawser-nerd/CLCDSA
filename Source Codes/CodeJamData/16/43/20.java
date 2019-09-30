import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Andrey Rechitsky (arechitsky@gmail.com)
 */
public class Main {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        InputStream inputStream;
        try {
            final String regex = "C-(small|large).*[.]in";
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
            outputStream = new FileOutputStream("c.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        FastScanner in = new FastScanner(inputStream);
        FastPrinter out = new FastPrinter(outputStream);
        TaskC solver = new TaskC();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, FastScanner in, FastPrinter out) {
            HashMap<Integer, Integer> rel = new HashMap<>();
            int r = in.nextInt();
            int c = in.nextInt();
            for (int i = 0; i < r + c; i++) {
                int a = in.nextInt() - 1;
                int b = in.nextInt() - 1;
                rel.put(a, b);
                rel.put(b, a);
            }

            out.printLine("Case #%d:", testNumber);
            for (int mask = 0; mask < 1 << (r * c); mask++) {
                char[][] field = new char[r][c];
                for (int i = 0; i < r * c; i++) {
                    field[i / c][i % c] = (mask & (1 << i)) > 0 ? '/' : '\\';
                }
                if (check(r, c, field, rel)) {
                    for (int i = 0; i < r; i++) {
                        for (int j = 0; j < c; j++) {
                            out.print(field[i][j]);
                        }
                        out.printLine();
                    }
                    return;
                }
            }

            out.printLine("IMPOSSIBLE");
        }

        boolean check(int r, int c, char[][] field, HashMap<Integer, Integer> rel) {
            int[] dr = {-1, 0, 1, 0};
            int[] dc = {0, 1, 0, -1};
            for (int i = 0; i < 2 * (r + c); i++) {
                int dir, rr, cc;
                if (i < c) {
                    dir = 2;
                    rr = 0;
                    cc = i;
                } else if (i < c + r) {
                    dir = 3;
                    rr = i - c;
                    cc = c - 1;
                } else if (i < 2 * c + r) {
                    dir = 0;
                    rr = r - 1;
                    cc = 2 * c + r - 1 - i;
                } else {
                    dir = 1;
                    rr = 2 * c + 2 * r - 1 - i;
                    cc = 0;
                }
                while (true) {
                    if (field[rr][cc] == '/') {
                        dir = dir / 2 * 2 + 1 - dir % 2;
                    } else {
                        dir = ((dir + 1) % 4 / 2 * 2 - 1 + dir % 2 + 4) % 4;
                    }
                    if (!isOk(r, c, rr + dr[dir], cc + dc[dir])) {
                        if (getExit(r, c, rr, cc, dir) == rel.get(i)) break;
                        return false;
                    }
                    rr = rr + dr[dir];
                    cc = cc + dc[dir];
                }
            }
            return true;
        }

        boolean isOk(int r, int c, int rr, int cc) {
            return rr >= 0 && cc >= 0 && rr < r && cc < c;
        }

        int getExit(int r, int c, int rr, int cc, int dir) {
            if (dir == 0) {
                return cc;
            } else if (dir == 1) {
                return rr + c;
            } else if (dir == 2) {
                return r + 2 * c - 1 - cc;
            } else
                return 2 * r + 2 * c - 1 - rr;
        }

    }

    static class FastPrinter {
        private final PrintWriter writer;

        public FastPrinter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public FastPrinter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void close() {
            writer.close();
        }

        public void printLine(String s) {
            writer.println(s);
        }

        public void printLine(String format, Object... args) {
            printLine(String.format(format, args));
        }

        public void printLine() {
            writer.println();
        }

        public void print(char c) {
            writer.print(c);
        }

    }

    static class FastScanner {
        private BufferedReader reader;
        private StringTokenizer st;

        public FastScanner(InputStream stream) {
            this.reader = new BufferedReader(new InputStreamReader(stream));
            this.st = new StringTokenizer("");
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public String next() {
            while (!st.hasMoreTokens()) {
                st = new StringTokenizer(readLine());
            }
            return st.nextToken();
        }

        private String readLine() {
            String line = tryReadLine();
            if (line == null) throw new InputMismatchException();
            return line;
        }

        private String tryReadLine() {
            try {
                return reader.readLine();
            } catch (IOException e) {
                throw new InputMismatchException();
            }
        }

    }
}

