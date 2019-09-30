import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        int[] firstEdge;
        int[] deg;
        int[] nextEdge;
        int[] to;
        int[] cost;
        int edges;
        int[] treeSize;
        int centroid;
        int listPos;
        long[] costList;

        private void addEdge(int from, int to, int cost) {
            this.to[edges] = to;
            this.cost[edges] = cost;
            nextEdge[edges] = firstEdge[from];
            firstEdge[from] = edges++;
            deg[from]++;
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            firstEdge = new int[n];
            Arrays.fill(firstEdge, -1);
            deg = new int[n];
            nextEdge = new int[2 * n - 2];
            to = new int[2 * n - 2];
            cost = new int[2 * n - 2];
            edges = 0;
            for (int i = 1; i < n; ++i) {
                int x = in.nextInt() - 1;
                int y = in.nextInt() - 1;
                int cost = in.nextInt();
                addEdge(x, y, cost);
                addEdge(y, x, cost);
            }
            treeSize = new int[n];
            centroid = -1;
            findCentroid(0, -1, n);
            long[][] lists = new long[deg[centroid]][];
            int pos = 0;
            costList = new long[n];
            for (int e = firstEdge[centroid]; e != -1; e = nextEdge[e]) {
                int to = this.to[e];
                listPos = 0;
                dfs(to, centroid, this.cost[e]);
                long[] clist = Arrays.copyOf(costList, listPos);
                Arrays.sort(clist);
                lists[pos++] = clist;
            }
            int lenMax = 0;
            for (int i = 0; i < lists.length; ++i) {
                lenMax = Math.max(lenMax, lists[i].length);
            }
            if (lenMax * 2 == n) {
                for (int i = 0; i < lists.length; ++i) {
                    if (lenMax == lists[i].length) {
                        ArraysUtils.swap(lists, 0, i);
                        break;
                    }
                }
            } else {
                long min = Long.MAX_VALUE;
                for (long[] l : lists) {
                    min = Math.min(min, l[0]);
                }
                for (int i = 0; i < lists.length; ++i) {
                    if (lists[i][0] == min) {
                        ArraysUtils.swap(lists, i, 0);
                        break;
                    }
                }
            }
            long ans = 0;
            for (long[] l : lists) {
                for (int i = 0; i < l.length; ++i) {
                    ans += 2 * l[i];
                }
            }
            ans -= lists[0][0];
            out.println(ans);
        }

        private void dfs(int node, int prev, long dist) {
            costList[listPos++] = dist;
            for (int e = firstEdge[node]; e != -1; e = nextEdge[e]) {
                int to = this.to[e];
                int cost = this.cost[e];
                if (to != prev) {
                    dfs(to, node, dist + cost);
                }
            }
        }

        private void findCentroid(int node, int prev, int total) {
            treeSize[node] = 1;
            boolean isCentroid = true;
            for (int e = firstEdge[node]; e != -1; e = nextEdge[e]) {
                int to = this.to[e];
                if (to != prev) {
                    findCentroid(to, node, total);
                    treeSize[node] += treeSize[to];
                    isCentroid &= treeSize[to] * 2 <= total;
                }
            }
            isCentroid &= (total - treeSize[node]) * 2 <= total;
            if (isCentroid) {
                centroid = node;
            }
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1)
                throw new UnknownError();
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new UnknownError();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public String next() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuffer res = new StringBuffer();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));

            return res.toString();
        }

        private boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }

    static class ArraysUtils {
        public static void swap(Object[] a, int i, int j) {
            Object aux = a[i];
            a[i] = a[j];
            a[j] = aux;
        }

    }
}