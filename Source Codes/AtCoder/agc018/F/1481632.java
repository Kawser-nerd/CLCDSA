import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Iterator;
import java.io.IOException;
import java.util.NoSuchElementException;
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
        int[] parent1;
        int[] parent2;
        IntList[] tree1;
        IntList[] tree2;
        int root1 = -1;
        int root2 = -1;
        IntList[] adj;
        int[] values;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            parent1 = new int[n];
            tree1 = new IntList[n];
            for (int i = 0; i < n; ++i) {
                tree1[i] = new IntList();
            }
            for (int i = 0; i < n; ++i) {
                parent1[i] = in.nextInt() - 1;
                if (parent1[i] == -2) {
                    parent1[i] = -1;
                    root1 = i;
                } else {
                    tree1[parent1[i]].add(i);
                }
            }
            parent2 = new int[n];
            tree2 = new IntList[n];
            for (int i = 0; i < n; ++i) {
                tree2[i] = new IntList();
            }
            for (int i = 0; i < n; ++i) {
                parent2[i] = in.nextInt() - 1;
                if (parent2[i] == -2) {
                    root2 = i;
                    parent2[i] = -1;
                } else {
                    tree2[parent2[i]].add(i);
                }
            }
            adj = new IntList[n];
            for (int i = 0; i < n; ++i) {
                if (tree1[i].size() % 2 != tree2[i].size() % 2) {
                    out.println("IMPOSSIBLE");
                    return;
                }
                adj[i] = new IntList();
            }
            values = new int[n];
            Arrays.fill(values, -2);
            dfsMatch(tree1, root1);
            dfsMatch(tree2, root2);
            for (int i = 0; i < n; ++i) {
                if (values[i] == -2) {
                    values[i] = 1;
                    putValues(i);
                }
            }
            out.println("POSSIBLE");
            for (int i = 0; i < n; ++i) {
                if (i > 0) {
                    out.print(" ");
                }
                out.print(values[i]);
            }
            out.println();
        }

        private int dfsMatch(IntList[] tree, int node) {
            for (int i = 0; i + 1 < tree[node].size(); i += 2) {
                int to1 = tree[node].get(i);
                int to2 = tree[node].get(i + 1);
                int n1 = dfsMatch(tree, to1);
                int n2 = dfsMatch(tree, to2);
                adj[n1].add(n2);
                adj[n2].add(n1);
            }
            if (tree[node].size() % 2 == 0) {
                return node;
            } else {
                values[node] = 0;
                return dfsMatch(tree, tree[node].last());
            }
        }

        private void putValues(int node) {
            for (int to : adj[node]) {
                if (values[to] == -2) {
                    values[to] = -values[node];
                    putValues(to);
                }
            }
        }

    }

    static class IntList implements Iterable<Integer> {
        int[] elem;
        int length;

        public IntList() {
            this(0, 0, 1);
        }

        public IntList(int length) {
            this(length, 0, Math.max(1, length));
        }

        public IntList(int length, int value) {
            this(length, value, Math.max(1, length));
        }

        public IntList(int length, int value, int capacity) {
            elem = new int[capacity];
            Arrays.fill(elem, 0, length, value);
            this.length = length;
        }

        private IntList(int... e) {
            elem = e.clone();
            length = e.length;
        }

        public void add(int e) {
            if (length + 1 > elem.length) {
                increaseCapacity();
            }
            elem[length++] = e;
        }

        public int get(int pos) {
            if (pos < 0 || pos >= length) {
                throw new IndexOutOfBoundsException(String.valueOf(pos));
            }
            return elem[pos];
        }

        public int last() {
            if (length == 0) {
                throw new NoSuchElementException();
            }
            return elem[length - 1];
        }

        private void increaseCapacity() {
            changeCapacity(3 * elem.length / 2 + 1);
        }

        private void changeCapacity(int newCapacity) {
            int[] nElem = new int[newCapacity];
            System.arraycopy(elem, 0, nElem, 0, Math.min(elem.length, newCapacity));
            elem = nElem;
        }

        public Iterator<Integer> iterator() {
            return new Iterator<Integer>() {
                int pos = 0;


                public Integer next() {
                    return IntList.this.elem[pos++];
                }


                public boolean hasNext() {
                    return pos < IntList.this.length;
                }
            };
        }

        public int size() {
            return length;
        }

        public int hashCode() {
            int hashCode = 0;
            for (int i = 0; i < length; ++i) {
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