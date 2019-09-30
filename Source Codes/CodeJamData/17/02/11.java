import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Quan To
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
        private int[] d;
        private int[] a;
        private int nDigits;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            long n = in.nextLong();
            List<Integer> digits = new ArrayList<>();
            while (n > 0) {
                digits.add((int) (n % 10L));
                n /= 10L;
            }

            nDigits = digits.size();
            d = new int[nDigits];
            a = new int[nDigits];
            for (int i = 0, j = nDigits - 1; i < d.length; ++i, --j) {
                d[i] = digits.get(j);
            }

            for (int i = d[0]; i >= 0; --i) {
                a[0] = i;
                if (backtrack(1, i < d[0])) {
                    out.printf("Case #%d: ", testNumber);
                    int x = 0;
                    while (a[x] == 0) {
                        ++x;
                    }
                    for (; x < a.length; ++x) {
                        out.print(a[x]);
                    }
                    out.println();
                    return;
                }
            }
        }

        private boolean backtrack(int x, boolean smaller) {
            if (x == nDigits) {
                return true;
            }
            int limit = smaller ? 9 : d[x];
            for (int i = limit; i >= a[x - 1]; --i) {
                a[x] = i;
                if (backtrack(x + 1, smaller || i < d[x])) {
                    return true;
                }
            }
            return false;
        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}

