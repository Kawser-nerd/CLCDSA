// package arc.arc079;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        int[] p = new int[n];
        for (int i = 0; i < n ; i++) {
            p[i] = in.nextInt()-1;
        }
        int cycleHead = 0;
        for (int i = 0; i < n ; i++) {
            cycleHead = p[cycleHead];
        }

        int head = cycleHead;
        List<Integer> cy = new ArrayList<>();
        for (int i = 0; i < n ; i++) {
            cy.add(head);
            head = p[head];
            if (head == cycleHead) {
                break;
            }
        }

        List<Integer>[] graph = new List[n];
        for (int i = 0; i < n ; i++) {
            graph[i] = new ArrayList<>();
        }
        int[] degree = new int[n];
        for (int i = 0; i < n ; i++) {
            degree[p[i]]++;
            graph[p[i]].add(i);
        }

        int[] value = new int[n];
        Arrays.fill(value, -1);

        int[] que = new int[n*4];
        int qh = 0, qt = 0;
        for (int i = 0; i < n ; i++) {
            if (degree[i] == 0) {
                que[qh++] = i;
            }
        }
        while (qt < qh) {
            int now = que[qt++];
            value[now] = take(value, graph, now);
            degree[p[now]]--;
            if (degree[p[now]] == 0) {
                que[qh++] = p[now];
            }
        }

        Set<Integer> set = new HashSet<>();
        set.clear();
        int chead = cy.get(0);
        for (int to : graph[chead]) {
            set.add(value[to]);
        }
        boolean answer = false;
        int tr = 0;
        for (int i = 0; i < n ; i++) {
            if (!set.contains(i)) {
                value[chead] = i;
                answer |= isValid(value.clone(), graph, p, cy);
                if (++tr >= 2) {
                    break;
                }
            }
        }

        out.println(answer ? "POSSIBLE" : "IMPOSSIBLE");
        out.flush();
    }

    private static boolean isValid(int[] value, List<Integer>[] graph, int[] p, List<Integer> cy) {
        int chead = cy.get(0);
        int head = chead;
        while (true) {
            head = p[head];
            if (head == chead) {
                break;
            }
            value[head] = take(value, graph, head);
        }
        return take(value, graph, chead) == value[chead];
    }

    private static int take(int[] value, List<Integer>[] graph, int v) {
        Set<Integer> set = new HashSet<>();
        for (int to : graph[v]) {
            set.add(value[to]);
        }
        for (int i = 0 ; i < graph.length ; i++) {
            if (!set.contains(i)) {
                return i;
            }
        }
        throw new RuntimeException("ohno");
    }

    public static void debug(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }

    public static class InputReader {
        private static final int BUFFER_LENGTH = 1 << 12;
        private InputStream stream;
        private byte[] buf = new byte[BUFFER_LENGTH];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        private int next() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public char nextChar() {
            return (char) skipWhileSpace();
        }

        public String nextToken() {
            int c = skipWhileSpace();
            StringBuilder res = new StringBuilder();
            do {
                res.append((char) c);
                c = next();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public int nextInt() {
            return (int) nextLong();
        }

        public long nextLong() {
            int c = skipWhileSpace();
            long sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = next();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = next();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public double nextDouble() {
            return Double.valueOf(nextToken());
        }

        int skipWhileSpace() {
            int c = next();
            while (isSpaceChar(c)) {
                c = next();
            }
            return c;
        }

        boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.