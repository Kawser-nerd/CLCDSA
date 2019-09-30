import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Iterator;
import java.util.Collection;
import java.io.IOException;
import java.util.Queue;
import java.util.ArrayDeque;
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
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] from = new int[n];
            IntList[] graph = new IntList[n];
            int[] deg = new int[n];
            for (int i = 0; i < n; ++i) {
                graph[i] = new IntList();
            }
            for (int i = 0; i < n; ++i) {
                from[i] = in.nextInt() - 1;
                graph[from[i]].add(i);
                deg[from[i]]++;
            }
            Queue<Integer> q = new ArrayDeque<>();
            for (int i = 0; i < n; ++i) {
                if (deg[i] == 0) {
                    q.add(i);
                }
            }
            boolean[] used = new boolean[n];
            int[] color = new int[n];
            while (!q.isEmpty()) {
                int node = q.poll();
                for (IntIterator it = graph[node].iterator(); it.hasNext(); ) {
                    int to = it.nextInt();
                    used[color[to]] = true;
                }
                while (used[color[node]]) {
                    color[node]++;
                }
                Arrays.fill(used, 0, color[node], false);
                if (--deg[from[node]] == 0) {
                    q.add(from[node]);
                }
            }
            int k = 0;
            for (int i = 0; i < n; ++i) {
                if (deg[i] != 0) {
                    k++;
                    for (IntIterator it = graph[i].iterator(); it.hasNext(); ) {
                        int to = it.nextInt();
                        if (deg[to] == 0) {
                            used[color[to]] = true;
                        }
                    }
                    while (used[color[i]]) {
                        color[i]++;
                    }
                    Arrays.fill(used, 0, color[i], false);
                }
            }
            int[] initColor = color.clone();
            int[] nodes = new int[k];
            k = 0;
            for (int i = 0; i < n; ++i) {
                if (deg[i] != 0) {
                    nodes[k++] = i;
                    for (int j = from[i]; j != i; j = from[j]) {
                        nodes[k++] = j;
                    }
                    break;
                }
            }
            TwoSat s = new TwoSat(n);
            for (int i = 0; i < k; ++i) {
                int node = nodes[i];
                int next = nodes[(i + 1) % k];
                if (color[node] == color[next]) {
                    s.addXor(node, next);
                } else if (color[node] + 1 == color[next]) {
                    s.addOr(s.non(node), next);
                } else if (color[next] + 1 == color[node]) {
                    s.addOr(s.non(next), node);
                }
            }
            s.solveSystem();
            out.println(s.hasSolution() ? "POSSIBLE" : "IMPOSSIBLE");

        }

    }

    static class TwoSat {
        private static final int initialCapacity = 1;
        private int[] firstEdge;
        private int[] edgeTo;
        private int[] nextEdge;
        private int[] t_firstEdge;
        private int[] t_edgeTo;
        private int[] t_nextEdge;
        private boolean[] values;
        int size;
        int edges;
        int capacity;

        public TwoSat(int size) {
            this.size = size;
            firstEdge = new int[2 * size];
            Arrays.fill(firstEdge, -1);
            t_firstEdge = firstEdge.clone();
            edgeTo = new int[initialCapacity];
            nextEdge = new int[initialCapacity];
            t_edgeTo = new int[initialCapacity];
            t_nextEdge = new int[initialCapacity];
            edges = 0;
            capacity = initialCapacity;
            values = null;
        }

        public void addOr(int from, int to) {
            addImply(non(from), to);
            addImply(non(to), from);
        }

        public void addXor(int from, int to) {
            addOr(from, to);
            addOr(non(from), non(to));
        }

        private void addImply(int from, int to) {
            ensureEdgeCapacity(edges + 1);
            edgeTo[edges] = to;
            nextEdge[edges] = firstEdge[from];
            firstEdge[from] = edges;

            t_edgeTo[edges] = from;
            t_nextEdge[edges] = t_firstEdge[to];
            t_firstEdge[to] = edges++;
        }

        public void solveSystem() {
            boolean[] used = new boolean[2 * size];
            int[] order = new int[2 * size];
            int pos = 0;
            for (int i = 0; i < 2 * size; ++i)
                if (!used[i])
                    pos = dfs1(used, order, pos, i);
            values = new boolean[2 * size];
            for (int i = 2 * size - 1; i >= 0; --i) {
                int node = order[i];
                if (!values[node] && !values[non(node)])
                    dfs2(used, node);
            }

            for (int i = 0; i < 2 * size; ++i) {
                for (int p = firstEdge[i]; p != -1; p = nextEdge[p]) {
                    int to = edgeTo[p];
                    if (values[i] && !values[to]) {
                        values = new boolean[0];
                        return;
                    }
                }
                if (values[i] == values[non(i)]) {
                    values = new boolean[0];
                    return;
                }
            }
        }

        public boolean hasSolution() {
            if (values == null) solveSystem();
            return values.length != 0;
        }

        public int non(int x) {
            return x < size ? x + size : x - size;
        }

        private void ensureEdgeCapacity(int edges) {
            if (edges > capacity) {
                capacity = 2 * capacity + 1;
                edgeTo = resize(edgeTo, capacity);
                nextEdge = resize(nextEdge, capacity);
                t_edgeTo = resize(t_edgeTo, capacity);
                t_nextEdge = resize(t_nextEdge, capacity);
            }
        }

        private int[] resize(int[] a, int newSize) {
            int[] b = new int[newSize];
            System.arraycopy(a, 0, b, 0, a.length);
            return b;
        }

        private int dfs1(boolean[] used, int[] order, int pos, int node) {
            used[node] = true;
            for (int p = firstEdge[node]; p != -1; p = nextEdge[p])
                if (!used[edgeTo[p]])
                    pos = dfs1(used, order, pos, edgeTo[p]);
            order[pos++] = node;
            return pos;
        }

        private void dfs2(boolean[] used, int node) {
            used[node] = false;
            values[non(node)] = true;
            for (int p = t_firstEdge[node]; p != -1; p = t_nextEdge[p])
                if (used[t_edgeTo[p]])
                    dfs2(used, t_edgeTo[p]);
        }

    }

    static interface IntIterator extends Iterator<Integer> {
        int nextInt();

    }

    static class IntList implements Iterable<Integer> {
        int[] elem;
        int size;

        public IntList() {
            this(0, 0, 1);
        }

        public IntList(int size) {
            this(size, 0, Math.max(1, size));
        }

        public IntList(int size, int value) {
            this(size, value, Math.max(1, size));
        }

        public IntList(int size, int value, int capacity) {
            elem = new int[capacity];
            Arrays.fill(elem, 0, size, value);
            this.size = size;
        }

        private IntList(int... e) {
            elem = e.clone();
            size = e.length;
        }

        public void add(int e) {
            if (size + 1 > elem.length) {
                increaseCapacity();
            }
            elem[size++] = e;
        }

        private void increaseCapacity() {
            changeCapacity(3 * elem.length / 2 + 1);
        }

        private void changeCapacity(int newCapacity) {
            int[] nElem = new int[newCapacity];
            System.arraycopy(elem, 0, nElem, 0, Math.min(elem.length, newCapacity));
            elem = nElem;
        }

        public IntIterator iterator() {
            return new IntIterator() {
                int pos = 0;


                public Integer next() {
                    return IntList.this.elem[pos++];
                }


                public boolean hasNext() {
                    return pos < IntList.this.size;
                }


                public int nextInt() {
                    return IntList.this.elem[pos++];
                }
            };
        }

        public int hashCode() {
            int hashCode = 0;
            for (int i = 0; i < size; ++i) {
                hashCode = 31 * hashCode + elem[i];
            }
            return hashCode;
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
}