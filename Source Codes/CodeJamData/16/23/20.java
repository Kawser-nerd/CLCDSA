import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            List<String> L = new ArrayList<>();
            List<String> R = new ArrayList<>();
            List<List<Integer>> adj = new ArrayList<>();
            for (int i = 0; i < n; ++i) {
                String a = in.next();
                String b = in.next();
                int x = add(L, a);
                int y = add(R, b);
                while (adj.size() < L.size()) {
                    adj.add(new ArrayList<>());
                }
                adj.get(x).add(y);
            }
            int res = L.size() + R.size() - maxMatch(L, R, adj);
            out.printf("Case #%d: %d\n", testNumber, n - res);
        }

        int add(List<String> a, String s) {
            for (int i = 0; i < a.size(); ++i) {
                if (a.get(i).equals(s)) {
                    return i;
                }
            }
            a.add(s);
            return a.size() - 1;
        }

        int maxMatch(List<String> L, List<String> R, List<List<Integer>> adj) {
            int res = 0;
            int[] xy = new int[L.size()];
            int[] yx = new int[R.size()];
            Arrays.fill(xy, -1);
            Arrays.fill(yx, -1);
            for (int i = 0; i < L.size(); ++i) {
                if (xy[i] == -1) {
                    boolean[] used = new boolean[L.size()];
                    if (dfs(i, used, xy, yx, adj)) {
                        ++res;
                    }
                }
            }
            System.err.printf("max match: %d\n", res);
            return res;
        }

        boolean dfs(int at, boolean[] used, int[] xy, int[] yx, List<List<Integer>> adj) {
            if (used[at]) {
                return false;
            }
            used[at] = true;
            for (int to : adj.get(at)) {
                if (yx[to] == -1 || dfs(yx[to], used, xy, yx, adj)) {
                    yx[to] = at;
                    xy[at] = to;
                    return true;
                }
            }
            return false;
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

        public int nextInt() {
            String s = next();
            if (s == null) {
                return 0;
            }
            return Integer.parseInt(s);
        }

    }
}

