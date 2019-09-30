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
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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
            final String regex = "D-(small|large).*[.]in";
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
            outputStream = new FileOutputStream("d.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskD {
        private char[][] result;
        private int sumDiagBase;
        private int difDiagBase;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            sumDiagBase = -1;
            difDiagBase = n;

            char[][] cells = new char[n + 1][n + 1];
            for (int r = 1; r <= n; ++r) {
                Arrays.fill(cells[r], '.');
            }

            boolean[] rowAvailable = new boolean[n + 1];
            Arrays.fill(rowAvailable, true);

            boolean[] colAvailable = new boolean[n + 1];
            Arrays.fill(colAvailable, true);

            boolean[] sumDiagAvailable = new boolean[2 * n];
            Arrays.fill(sumDiagAvailable, true);

            boolean[] difDiagAvailable = new boolean[2 * n];
            Arrays.fill(difDiagAvailable, true);

            for (int i = 0; i < m; ++i) {
                char model = in.next().charAt(0);
                int r = in.nextInt();
                int c = in.nextInt();
                cells[r][c] = model;

                if (model == 'o' || model == 'x') {
                    rowAvailable[r] = colAvailable[c] = false;
                }
                if (model == 'o' || model == '+') {
                    sumDiagAvailable[getSumDiag(r, c)] = difDiagAvailable[getDifDiag(r, c)] = false;
                }
            }

            BipartiteGraph graph1 = new BipartiteGraph(n, n);
            for (int r = 1; r <= n; ++r) {
                for (int c = 1; c <= n; ++c) {
                    if (rowAvailable[r] && colAvailable[c]) {
                        char model = cells[r][c];
                        if (model == '.' || model == '+') {
                            graph1.addEdge(r, c);
                        }
                    }
                }
            }

            BipartiteGraph graph2 = new BipartiteGraph(2 * n - 1, 2 * n - 1);
            for (int r = 1; r <= n; ++r) {
                for (int c = 1; c <= n; ++c) {
                    int sumDiag = getSumDiag(r, c);
                    int difDiag = getDifDiag(r, c);
                    if (sumDiagAvailable[sumDiag] && difDiagAvailable[difDiag]) {
                        char model = cells[r][c];
                        if (model == '.' || model == 'x') {
                            graph2.addEdge(sumDiag, difDiag);
                        }
                    }
                }
            }

            result = new char[n + 1][n + 1];
            for (int r = 1; r <= n; ++r) {
                System.arraycopy(cells[r], 1, result[r], 1, n);
            }

            int[] match1 = graph1.getResult();
            for (int r = 1; r <= n; ++r) {
                int c = match1[r];
                if (c != 0) {
                    update(r, c, 'x');
                }
            }

            int[] match2 = graph2.getResult();
            for (int sumDiag = 1; sumDiag <= 2 * n - 1; ++sumDiag) {
                int difDiag = match2[sumDiag];
                if (difDiag == 0) {
                    continue;
                }

                int sum = sumDiag - sumDiagBase;
                int dif = difDiag - difDiagBase;
                int r = (sum + dif) / 2;
                int c = sum - r;
                update(r, c, '+');
            }

            int totalPoint = 0;
            int count = 0;
            for (int r = 1; r <= n; ++r) {
                for (int c = 1; c <= n; ++c) {
                    switch (result[r][c]) {
                        case 'o':
                            totalPoint += 2;
                            break;
                        case '+':
                        case 'x':
                            ++totalPoint;
                            break;
                    }

                    if (result[r][c] != cells[r][c]) {
                        ++count;
                    }
                }
            }

            out.printf("Case #%d: %d %d\n", testNumber, totalPoint, count);
            for (int r = 1; r <= n; ++r) {
                for (int c = 1; c <= n; ++c) {
                    if (result[r][c] != cells[r][c]) {
                        out.printf("%c %d %d\n", result[r][c], r, c);
                    }
                }
            }
        }

        private int getSumDiag(int r, int c) {
            return sumDiagBase + (r + c);
        }

        private int getDifDiag(int r, int c) {
            return difDiagBase + (r - c);
        }

        private void update(int r, int c, char ch) {
            if (result[r][c] == '.') {
                result[r][c] = ch;
            } else {
                result[r][c] = 'o';
            }
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

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }

    static class BipartiteGraph {
        private int numLeftVertex;
        private int numRightVertex;
        private int[] matchLeft;
        private int[] matchRight;
        private boolean[] visited;
        private List<Integer>[] adj;

        public BipartiteGraph(int numLeftVertex, int numRightVertex) {
            this.numLeftVertex = numLeftVertex;
            this.numRightVertex = numRightVertex;
            adj = new List[this.numLeftVertex + 1];
            for (int i = 1; i <= this.numLeftVertex; ++i) {
                adj[i] = new ArrayList<>();
            }
        }

        public void addEdge(int left, int right) {
            adj[left].add(right);
        }

        public int[] getResult() {
            matchLeft = new int[numLeftVertex + 1];
            matchRight = new int[numRightVertex + 1];
            visited = new boolean[numLeftVertex + 1];

            for (int l = 1; l <= numLeftVertex; ++l) {
                Arrays.fill(visited, false);
                visit(l);
            }
            return matchLeft;
        }

        private boolean visit(int l) {
            if (visited[l]) {
                return false;
            }
            visited[l] = true;
            for (int r : adj[l]) {
                if (matchRight[r] == 0 || visit(matchRight[r])) {
                    matchLeft[l] = r;
                    matchRight[r] = l;
                    return true;
                }
            }
            return false;
        }

    }
}

