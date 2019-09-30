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
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskB solver = new TaskB();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            out.print("Case #" + testNumber + ": ");
            int n = in.nextInt();
            int r = in.nextInt(); // 001
            int o = in.nextInt(); // 011
            int y = in.nextInt(); // 010
            int g = in.nextInt(); // 110
            int b = in.nextInt(); // 100
            int v = in.nextInt();// 101
            if (o == b && o + b == n) {
                for (int i = 0; i < o; i++) {
                    out.print("OB");
                }
                out.println();
                return;
            }
            if (g == r && g + r == n) {
                for (int i = 0; i < g; i++) {
                    out.print("GR");
                }
                out.println();
                return;
            }
            if (v == y && v + y == n) {
                for (int i = 0; i < v; i++) {
                    out.print("VY");
                }
                out.println();
                return;
            }
            if (n == 1) {
                if (r > 0) out.print("R");
                if (o > 0) out.print("O");
                if (y > 0) out.print("Y");
                if (g > 0) out.print("G");
                if (b > 0) out.print("B");
                if (v > 0) out.print("V");
                out.println();
                return;
            }

            List<String>[] blocks = new List[3];
            for (int i = 0; i < 3; i++) {
                blocks[i] = new ArrayList<>();
            }

            if (g > 0) {
                StringBuilder sb = new StringBuilder();
                sb.append("R");
                for (int i = 0; i < g; i++) {
                    sb.append("GR");
                }
                blocks[0].add(sb.toString());
                r -= g + 1;
                g = 0;
            }

            if (v > 0) {
                StringBuilder sb = new StringBuilder();
                sb.append("Y");
                for (int i = 0; i < v; i++) {
                    sb.append("VY");
                }
                blocks[1].add(sb.toString());
                y -= v + 1;
                v = 0;
            }

            if (o > 0) {
                StringBuilder sb = new StringBuilder();
                sb.append("B");
                for (int i = 0; i < o; i++) {
                    sb.append("OB");
                }
                blocks[2].add(sb.toString());
                b -= o + 1;
                o = 0;
            }
            if (r < 0 || y < 0 || b < 0) {
                out.println("IMPOSSIBLE");
                return;
            }
            while (r > 0) {
                blocks[0].add("R");
                --r;
            }
            while (y > 0) {
                blocks[1].add("Y");
                --y;
            }
            while (b > 0) {
                blocks[2].add("B");
                --b;
            }

            int largest = 0;
            int total = 0;
            for (int i = 0; i < 3; i++) {
                if (blocks[largest].size() < blocks[i].size()) {
                    largest = i;
                }
                total += blocks[i].size();
            }

            if (blocks[largest].size() > total / 2) {
                out.println("IMPOSSIBLE");
                return;
            }

            String[] ans = new String[total];
            int cur = largest;
            for (int step = 0; step < 2; step++) {
                for (int i = step; i < total; i += 2) {
                    while (blocks[cur].isEmpty()) {
                        cur = (cur + 1) % 3;
                    }
                    ans[i] = blocks[cur].get(blocks[cur].size() - 1);
                    blocks[cur].remove(blocks[cur].size() - 1);
                }
            }
            for (String s : ans) {
                out.print(s);
            }
            out.println();
        }

    }

    static class FastScanner {
        private BufferedReader in;
        private StringTokenizer st;

        public FastScanner(InputStream stream) {
            in = new BufferedReader(new InputStreamReader(stream));
        }

        public String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(in.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}

