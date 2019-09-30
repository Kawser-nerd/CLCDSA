import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Set;
import java.util.InputMismatchException;
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
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt();
            String s1 = in.next();
            String s2 = in.next();

            UnionFindTree uft = new UnionFindTree(27);
            Set<Character> appered = new HashSet<>();

            for (int i = 0; i < n; i++) {
                char c1 = s1.charAt(i);
                char c2 = s2.charAt(i);
                if (Character.isDigit(c1) && Character.isDigit(c2))
                    continue;

                if (Character.isDigit(c1))
                    uft.unite(c2 - 'A', 26);
                else if (Character.isDigit(c2))
                    uft.unite(c1 - 'A', 26);
                else
                    uft.unite(c1 - 'A', c2 - 'A');

                if (Character.isAlphabetic(c1))
                    appered.add(c1);
                if (Character.isAlphabetic(c2))
                    appered.add(c2);
            }

            for (char c = 'A'; c <= 'Z'; c++) {
                if (!appered.contains(c))
                    uft.unite(c - 'A', 26);
            }

            Set<Integer> group = new HashSet<>();
            for (int i = 0; i < 27; i++) {
                group.add(uft.find(i));
            }
            int count = group.size() - 1;

            if (Character.isAlphabetic(s1.charAt(0)) && !uft.same(s1.charAt(0) - 'A', 26))
                out.println(9L * (long) Math.pow(10, count - 1));
            else if (Character.isAlphabetic(s2.charAt(0)) && !uft.same(s2.charAt(0) - 'A', 26))
                out.println(9L * (long) Math.pow(10, count - 1));
            else
                out.println((long) Math.pow(10, count));
        }

    }

    static class UnionFindTree {
        private int[] parent;
        private int[] rank;
        private int size;

        public UnionFindTree(int size) {
            this.size = size;
            parent = new int[size];
            rank = new int[size];
            for (int i = 0; i < size; i++) {
                parent[i] = i;
                rank[i] = 0;
            }
        }

        public int find(int index) {
            if (parent[index] == index) return index;
            else {
                parent[index] = find(parent[index]);
                return parent[index];
            }
        }

        public boolean same(int index1, int index2) {
            return find(index1) == find(index2);
        }

        public void unite(int index1, int index2) {
            int parent1 = find(index1);
            int parent2 = find(index2);
            if (parent1 == parent2) return;

            if (rank[parent1] < rank[parent2]) {
                parent[parent1] = parent2;
            } else {
                parent[parent2] = parent1;
                if (rank[parent1] == rank[parent2]) rank[parent1]++;
            }
        }

    }

    static class FastScanner {
        private InputStream in;
        private byte[] buffer = new byte[1024];
        private int bufPointer;
        private int bufLength;

        public FastScanner(InputStream in) {
            this.in = in;
            this.bufPointer = 0;
            this.bufLength = 0;
        }

        private int readByte() {
            if (bufPointer >= bufLength) {
                if (bufLength == -1)
                    throw new InputMismatchException();

                bufPointer = 0;
                try {
                    bufLength = in.read(buffer);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }

                if (bufLength <= 0)
                    return -1;
            }
            return buffer[bufPointer++];
        }

        private static boolean isPrintableChar(int c) {
            return c >= 33 && c <= 126;
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public String next() {
            StringBuilder sb = new StringBuilder();

            int b = readByte();
            while (!isPrintableChar(b))
                b = readByte();

            while (isPrintableChar(b)) {
                sb.appendCodePoint(b);
                b = readByte();
            }

            return sb.toString();
        }

        public int nextInt() {
            int n = 0;

            int b = readByte();
            while (isSpaceChar(b))
                b = readByte();

            boolean minus = (b == '-');
            if (minus)
                b = readByte();

            while (b >= '0' && b <= '9') {
                n *= 10;
                n += b - '0';
                b = readByte();
            }

            if (!isSpaceChar(b))
                throw new NumberFormatException();

            return minus ? -n : n;
        }

    }
}