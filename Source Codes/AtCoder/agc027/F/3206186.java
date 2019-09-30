import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Egor Kulikov (egor@egork.net)
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskF solver = new TaskF();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++) {
            solver.solve(i, in, out);
        }
        out.close();
    }

    static class TaskF {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int[] a = new int[n - 1];
            int[] b = new int[n - 1];
            int[] c = new int[n - 1];
            int[] d = new int[n - 1];
            in.readIntArrays(a, b);
            in.readIntArrays(c, d);
            MiscUtils.decreaseByOne(a, b, c, d);
            Graph start = BidirectionalGraph.createGraph(n, a, b);
            Graph end = BidirectionalGraph.createGraph(n, c, d);
            int[] pStart = new int[n];
            int[] pEnd = new int[n];
            boolean[] move = new boolean[n];
            int answer = n + 1;
            for (int i = 0; i < n; i++) {
                buildParent(start, i, -1, pStart);
                buildParent(end, i, -1, pEnd);
                for (int j = 0; j < n; j++) {
                    move[j] = pStart[j] != pEnd[j];
                }
                boolean ok = true;
                for (int j = 0; j < n; j++) {
                    if (j != i && !move[j] && move[pStart[j]]) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) {
                    continue;
                }
                Graph top = new Graph(n);
                for (int j = 0; j < n; j++) {
                    if (move[j] && move[pStart[j]]) {
                        top.addSimpleEdge(j, pStart[j]);
                    }
                    if (move[j] && move[pEnd[j]]) {
                        top.addSimpleEdge(pEnd[j], j);
                    }
                }
                if (GraphAlgorithms.topologicalSort(top) == null) {
                    continue;
                }
                answer = Math.min(answer, ArrayUtils.count(move, true));
            }
            Graph wasStart = start;
            for (int i = 0; i < n; i++) {
                if (wasStart.nextOutbound(wasStart.firstOutbound(i)) == -1) {
                    int k = wasStart.destination(wasStart.firstOutbound(i));
                    int edge = -1;
                    for (int j = 0; j < n - 1; j++) {
                        if (a[j] == i || b[j] == i) {
                            edge = j;
                        }
                    }
                    for (int l = 0; l < n; l++) {
                        if (l != k && l != i) {
                            if (a[edge] == i) {
                                b[edge] = l;
                            } else {
                                a[edge] = l;
                            }
                            start = BidirectionalGraph.createGraph(n, a, b);
                            buildParent(start, i, -1, pStart);
                            buildParent(end, i, -1, pEnd);
                            for (int j = 0; j < n; j++) {
                                move[j] = pStart[j] != pEnd[j];
                            }
                            boolean ok = true;
                            for (int j = 0; j < n; j++) {
                                if (j != i && !move[j] && move[pStart[j]]) {
                                    ok = false;
                                    break;
                                }
                            }
                            if (!ok) {
                                continue;
                            }
                            Graph top = new Graph(n);
                            for (int j = 0; j < n; j++) {
                                if (move[j] && move[pStart[j]]) {
                                    top.addSimpleEdge(j, pStart[j]);
                                }
                                if (move[j] && move[pEnd[j]]) {
                                    top.addSimpleEdge(pEnd[j], j);
                                }
                            }
                            if (GraphAlgorithms.topologicalSort(top) == null) {
                                continue;
                            }
                            answer = Math.min(answer, n);
                        }
                    }
                    if (a[edge] == i) {
                        b[edge] = k;
                    } else {
                        a[edge] = k;
                    }
                }
            }
            if (answer == n + 1) {
                answer = -1;
            }
            out.printLine(answer);
        }

        private void buildParent(Graph graph, int vertex, int last, int[] parent) {
            parent[vertex] = last;
            for (int i = graph.firstOutbound(vertex); i != -1; i = graph.nextOutbound(i)) {
                int to = graph.destination(i);
                if (to == last) {
                    continue;
                }
                buildParent(graph, to, vertex, parent);
            }
        }

    }

    static class ArrayUtils {
        public static int count(boolean[] array, boolean value) {
            int result = 0;
            for (boolean i : array) {
                if (i == value) {
                    result++;
                }
            }
            return result;
        }

    }

    static class MiscUtils {
        public static void decreaseByOne(int[]... arrays) {
            for (int[] array : arrays) {
                for (int i = 0; i < array.length; i++) {
                    array[i]--;
                }
            }
        }

    }

    static class BidirectionalGraph extends Graph {
        public int[] transposedEdge;

        public BidirectionalGraph(int vertexCount) {
            this(vertexCount, vertexCount);
        }

        public BidirectionalGraph(int vertexCount, int edgeCapacity) {
            super(vertexCount, 2 * edgeCapacity);
            transposedEdge = new int[2 * edgeCapacity];
        }

        public static BidirectionalGraph createGraph(int vertexCount, int[] from, int[] to) {
            BidirectionalGraph graph = new BidirectionalGraph(vertexCount, from.length);
            for (int i = 0; i < from.length; i++) {
                graph.addSimpleEdge(from[i], to[i]);
            }
            return graph;
        }

        public int addEdge(int fromID, int toID, long weight, long capacity, int reverseEdge) {
            int lastEdgeCount = edgeCount;
            super.addEdge(fromID, toID, weight, capacity, reverseEdge);
            super.addEdge(toID, fromID, weight, capacity, reverseEdge == -1 ? -1 : reverseEdge + 1);
            this.transposedEdge[lastEdgeCount] = lastEdgeCount + 1;
            this.transposedEdge[lastEdgeCount + 1] = lastEdgeCount;
            return lastEdgeCount;
        }

        protected int entriesPerEdge() {
            return 2;
        }

        protected void ensureEdgeCapacity(int size) {
            if (size > edgeCapacity()) {
                super.ensureEdgeCapacity(size);
                transposedEdge = resize(transposedEdge, edgeCapacity());
            }
        }

    }

    static class Graph {
        public static final int REMOVED_BIT = 0;
        protected int vertexCount;
        protected int edgeCount;
        private int[] firstOutbound;
        private int[] firstInbound;
        private Edge[] edges;
        private int[] nextInbound;
        private int[] nextOutbound;
        private int[] from;
        private int[] to;
        private long[] weight;
        public long[] capacity;
        private int[] reverseEdge;
        private int[] flags;

        public Graph(int vertexCount) {
            this(vertexCount, vertexCount);
        }

        public Graph(int vertexCount, int edgeCapacity) {
            this.vertexCount = vertexCount;
            firstOutbound = new int[vertexCount];
            Arrays.fill(firstOutbound, -1);

            from = new int[edgeCapacity];
            to = new int[edgeCapacity];
            nextOutbound = new int[edgeCapacity];
            flags = new int[edgeCapacity];
        }

        public int addEdge(int fromID, int toID, long weight, long capacity, int reverseEdge) {
            ensureEdgeCapacity(edgeCount + 1);
            if (firstOutbound[fromID] != -1) {
                nextOutbound[edgeCount] = firstOutbound[fromID];
            } else {
                nextOutbound[edgeCount] = -1;
            }
            firstOutbound[fromID] = edgeCount;
            if (firstInbound != null) {
                if (firstInbound[toID] != -1) {
                    nextInbound[edgeCount] = firstInbound[toID];
                } else {
                    nextInbound[edgeCount] = -1;
                }
                firstInbound[toID] = edgeCount;
            }
            this.from[edgeCount] = fromID;
            this.to[edgeCount] = toID;
            if (capacity != 0) {
                if (this.capacity == null) {
                    this.capacity = new long[from.length];
                }
                this.capacity[edgeCount] = capacity;
            }
            if (weight != 0) {
                if (this.weight == null) {
                    this.weight = new long[from.length];
                }
                this.weight[edgeCount] = weight;
            }
            if (reverseEdge != -1) {
                if (this.reverseEdge == null) {
                    this.reverseEdge = new int[from.length];
                    Arrays.fill(this.reverseEdge, 0, edgeCount, -1);
                }
                this.reverseEdge[edgeCount] = reverseEdge;
            }
            if (edges != null) {
                edges[edgeCount] = createEdge(edgeCount);
            }
            return edgeCount++;
        }

        protected final GraphEdge createEdge(int id) {
            return new GraphEdge(id);
        }

        public final int addFlowWeightedEdge(int from, int to, long weight, long capacity) {
            if (capacity == 0) {
                return addEdge(from, to, weight, 0, -1);
            } else {
                int lastEdgeCount = edgeCount;
                addEdge(to, from, -weight, 0, lastEdgeCount + entriesPerEdge());
                return addEdge(from, to, weight, capacity, lastEdgeCount);
            }
        }

        protected int entriesPerEdge() {
            return 1;
        }

        public final int addWeightedEdge(int from, int to, long weight) {
            return addFlowWeightedEdge(from, to, weight, 0);
        }

        public final int addSimpleEdge(int from, int to) {
            return addWeightedEdge(from, to, 0);
        }

        public final int vertexCount() {
            return vertexCount;
        }

        public final int edgeCount() {
            return edgeCount;
        }

        protected final int edgeCapacity() {
            return from.length;
        }

        public final int firstOutbound(int vertex) {
            int id = firstOutbound[vertex];
            while (id != -1 && isRemoved(id)) {
                id = nextOutbound[id];
            }
            return id;
        }

        public final int nextOutbound(int id) {
            id = nextOutbound[id];
            while (id != -1 && isRemoved(id)) {
                id = nextOutbound[id];
            }
            return id;
        }

        public final int destination(int id) {
            return to[id];
        }

        public final boolean flag(int id, int bit) {
            return (flags[id] >> bit & 1) != 0;
        }

        public final boolean isRemoved(int id) {
            return flag(id, REMOVED_BIT);
        }

        protected void ensureEdgeCapacity(int size) {
            if (from.length < size) {
                int newSize = Math.max(size, 2 * from.length);
                if (edges != null) {
                    edges = resize(edges, newSize);
                }
                from = resize(from, newSize);
                to = resize(to, newSize);
                nextOutbound = resize(nextOutbound, newSize);
                if (nextInbound != null) {
                    nextInbound = resize(nextInbound, newSize);
                }
                if (weight != null) {
                    weight = resize(weight, newSize);
                }
                if (capacity != null) {
                    capacity = resize(capacity, newSize);
                }
                if (reverseEdge != null) {
                    reverseEdge = resize(reverseEdge, newSize);
                }
                flags = resize(flags, newSize);
            }
        }

        protected final int[] resize(int[] array, int size) {
            int[] newArray = new int[size];
            System.arraycopy(array, 0, newArray, 0, array.length);
            return newArray;
        }

        private long[] resize(long[] array, int size) {
            long[] newArray = new long[size];
            System.arraycopy(array, 0, newArray, 0, array.length);
            return newArray;
        }

        private Edge[] resize(Edge[] array, int size) {
            Edge[] newArray = new Edge[size];
            System.arraycopy(array, 0, newArray, 0, array.length);
            return newArray;
        }

        protected class GraphEdge implements Edge {
            protected int id;

            protected GraphEdge(int id) {
                this.id = id;
            }

        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void close() {
            writer.close();
        }

        public void printLine(int i) {
            writer.println(i);
        }

    }

    static class GraphAlgorithms {
        public static int[] topologicalSort(Graph graph) {
            int count = graph.vertexCount();
            int[] order = new int[count];
            int[] degree = new int[count];
            int size = 0;
            for (int i = 0; i < graph.edgeCount(); i++) {
                if (!graph.isRemoved(i)) {
                    degree[graph.destination(i)]++;
                }
            }
            for (int i = 0; i < count; i++) {
                if (degree[i] == 0) {
                    order[size++] = i;
                }
            }
            for (int i = 0; i < size; i++) {
                int current = order[i];
                for (int j = graph.firstOutbound(current); j != -1; j = graph.nextOutbound(j)) {
                    int next = graph.destination(j);
                    if (--degree[next] == 0) {
                        order[size++] = next;
                    }
                }
            }
            if (size != count) {
                return null;
            }
            return order;
        }

    }

    static interface Edge {
    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public void readIntArrays(int[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readInt();
                }
            }
        }

        public int read() {
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
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int readInt() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public String readString() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public String next() {
            return readString();
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }
}