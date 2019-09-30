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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int m = in.readInt();
            int[] a = new int[n - 1];
            int[] b = new int[n - 1];
            in.readIntArrays(a, b);
            int[] u = new int[m];
            int[] v = new int[m];
            in.readIntArrays(u, v);
            MiscUtils.decreaseByOne(a, b, u, v);
            BidirectionalGraph graph = BidirectionalGraph.createGraph(n, a, b);
            LCA lca = new LCA(graph);
            int[] parent = new int[n];
            for (int i = 1; i < n; i++) {
                for (int j = graph.firstOutbound(i); j != -1; j = graph.nextOutbound(j)) {
                    if (lca.getLevel(graph.destination(j)) < lca.getLevel(i)) {
                        parent[i] = graph.destination(j);
                        break;
                    }
                }
            }
            int[] first = ArrayUtils.createArray(n, -1);
            int[] second = ArrayUtils.createArray(n, -1);
            int[] not = new int[2 * m];
            for (int i = 0; i < m; i++) {
                not[i] = i + m;
                not[i + m] = i;
            }
            for (int i = 0; i < m; i++) {
                int root = lca.getLCA(u[i], v[i]);
                int lastFirst = -1;
                for (int j = u[i]; j != root; j = parent[j]) {
                    if (first[j] == -1) {
                        first[j] = i;
                    } else if (second[j] == -1) {
                        second[j] = i;
                        lastFirst = first[j];
                    } else if (first[j] == lastFirst) {
                        second[j] = i;
                    } else if (second[j] == lastFirst) {
                        first[j] = i;
                    }
                }
                lastFirst = -1;
                for (int j = v[i]; j != root; j = parent[j]) {
                    if (first[j] == -1) {
                        first[j] = not[i];
                    } else if (second[j] == -1) {
                        second[j] = not[i];
                        lastFirst = first[j];
                    } else if (first[j] == lastFirst) {
                        second[j] = not[i];
                    } else if (second[j] == lastFirst) {
                        first[j] = not[i];
                    }
                }
            }
            Graph sat = new Graph(2 * m);
            int t = 0;
            for (int i = 1; i < n; i++) {
                if (second[i] != -1) {
                    sat.addSimpleEdge(first[i], not[second[i]]);
                    sat.addSimpleEdge(second[i], not[first[i]]);
                    sat.addSimpleEdge(not[first[i]], second[i]);
                    sat.addSimpleEdge(not[second[i]], first[i]);
                    t += 2;
                } else if (first[i] != -1) {
                    t++;
                }
            }
            Pair<int[], Graph> result = StronglyConnectedComponents.kosaraju(sat);
            int[] value = new int[m];
            boolean[] taken = new boolean[result.second.vertexCount()];
            for (int i = 0; i < m; i++) {
                if (result.first[i] == result.first[not[i]]) {
                    throw new RuntimeException();
                }
                if (taken[result.first[i]]) {
                    value[i] = 1;
                    continue;
                }
                if (taken[result.first[not[i]]]) {
                    value[i] = -1;
                    continue;
                }
                if (result.first[i] < result.first[not[i]]) {
                    value[i] = -1;
                } else {
                    value[i] = 1;
                }
                go(result.second, value[i] == 1 ? result.first[i] : result.first[not[i]], taken);
            }
            for (int i = 0; i < m; i++) {
                if (value[i] == -1) {
                    int temp = u[i];
                    u[i] = v[i];
                    v[i] = temp;
                }
            }
            out.printLine(t);
            for (int i = 0; i < m; i++) {
                out.printLine(u[i] + 1, v[i] + 1);
            }
        }

        private void go(Graph graph, int vertex, boolean[] taken) {
            if (taken[vertex]) {
                return;
            }
            taken[vertex] = true;
            for (int i = graph.firstOutbound(vertex); i != -1; i = graph.nextOutbound(i)) {
                go(graph, graph.destination(i), taken);
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

    static class StronglyConnectedComponents {
        private final Graph graph;
        private int[] order;
        private boolean[] visited;
        private int index = 0;
        private int vertexCount;
        private int[] condensed;
        private int[] next;
        private int key;
        private int[] queue;
        private int queueSize;

        private StronglyConnectedComponents(Graph graph) {
            this.graph = graph;
            vertexCount = graph.vertexCount();
            order = new int[vertexCount];
            visited = new boolean[vertexCount];
            condensed = new int[vertexCount];
        }

        public static Pair<int[], Graph> kosaraju(Graph graph) {
            return new StronglyConnectedComponents(graph).kosaraju();
        }

        private Pair<int[], Graph> kosaraju() {
            for (int i = 0; i < vertexCount; i++) {
                if (!visited[i]) {
                    firstDFS(i);
                }
            }
            Arrays.fill(visited, false);
            Graph result = new Graph(0);
            index = 0;
            next = ArrayUtils.createArray(graph.vertexCount(), -1);
            queue = new int[graph.vertexCount()];
            for (int i = vertexCount - 1; i >= 0; i--) {
                if (!visited[order[i]]) {
                    key = i;
                    queueSize = 0;
                    secondDFS(order[i]);
                    result.addVertices(1);
                    for (int j = 0; j < queueSize; j++) {
                        result.addSimpleEdge(queue[j], index);
                    }
                    index++;
                }
            }
            return Pair.makePair(condensed, result);
        }

        private void secondDFS(int vertexID) {
            if (visited[vertexID]) {
                if (condensed[vertexID] != index) {
                    if (next[condensed[vertexID]] != key) {
                        next[condensed[vertexID]] = key;
                        queue[queueSize++] = condensed[vertexID];
                    }
                }
                return;
            }
            condensed[vertexID] = index;
            visited[vertexID] = true;
            int edgeID = graph.firstInbound(vertexID);
            while (edgeID != -1) {
                secondDFS(graph.source(edgeID));
                edgeID = graph.nextInbound(edgeID);
            }
        }

        private void firstDFS(int vertexID) {
            if (visited[vertexID]) {
                return;
            }
            visited[vertexID] = true;
            int edgeID = graph.firstOutbound(vertexID);
            while (edgeID != -1) {
                firstDFS(graph.destination(edgeID));
                edgeID = graph.nextOutbound(edgeID);
            }
            order[index++] = vertexID;
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

        public final int firstInbound(int vertex) {
            initInbound();
            int id = firstInbound[vertex];
            while (id != -1 && isRemoved(id)) {
                id = nextInbound[id];
            }
            return id;
        }

        public final int nextInbound(int id) {
            initInbound();
            id = nextInbound[id];
            while (id != -1 && isRemoved(id)) {
                id = nextInbound[id];
            }
            return id;
        }

        public final int source(int id) {
            return from[id];
        }

        public final int destination(int id) {
            return to[id];
        }

        public final void addVertices(int count) {
            ensureVertexCapacity(vertexCount + count);
            Arrays.fill(firstOutbound, vertexCount, vertexCount + count, -1);
            if (firstInbound != null) {
                Arrays.fill(firstInbound, vertexCount, vertexCount + count, -1);
            }
            vertexCount += count;
        }

        private void initInbound() {
            if (firstInbound == null) {
                firstInbound = new int[firstOutbound.length];
                Arrays.fill(firstInbound, 0, vertexCount, -1);
                nextInbound = new int[from.length];
                for (int i = 0; i < edgeCount; i++) {
                    nextInbound[i] = firstInbound[to[i]];
                    firstInbound[to[i]] = i;
                }
            }
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

        private void ensureVertexCapacity(int size) {
            if (firstOutbound.length < size) {
                int newSize = Math.max(size, 2 * firstOutbound.length);
                firstOutbound = resize(firstOutbound, newSize);
                if (firstInbound != null) {
                    firstInbound = resize(firstInbound, newSize);
                }
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

    static class ArrayUtils {
        public static int[] createArray(int count, int value) {
            int[] array = new int[count];
            Arrays.fill(array, value);
            return array;
        }

    }

    static class Pair<U, V> implements Comparable<Pair<U, V>> {
        public final U first;
        public final V second;

        public static <U, V> Pair<U, V> makePair(U first, V second) {
            return new Pair<U, V>(first, second);
        }

        private Pair(U first, V second) {
            this.first = first;
            this.second = second;
        }


        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (o == null || getClass() != o.getClass()) {
                return false;
            }

            Pair pair = (Pair) o;

            return !(first != null ? !first.equals(pair.first) : pair.first != null) &&
                    !(second != null ? !second.equals(pair.second) : pair.second != null);
        }


        public int hashCode() {
            int result = first != null ? first.hashCode() : 0;
            result = 31 * result + (second != null ? second.hashCode() : 0);
            return result;
        }


        public String toString() {
            return "(" + first + "," + second + ")";
        }

        @SuppressWarnings({"unchecked"})
        public int compareTo(Pair<U, V> o) {
            int value = ((Comparable<U>) first).compareTo(o.first);
            if (value != 0) {
                return value;
            }
            return ((Comparable<V>) second).compareTo(o.second);
        }

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

        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

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

    static interface Edge {
    }

    static abstract class ReadOnlyIntervalTree extends IntervalTree {
        protected long[] value;
        protected long[] array;

        protected ReadOnlyIntervalTree(long[] array) {
            super(array.length, false);
            this.array = array;
            init();
        }


        protected void initData(int size, int nodeCount) {
            value = new long[nodeCount];
        }


        protected void initAfter(int root, int left, int right, int middle) {
            value[root] = joinValue(value[2 * root + 1], value[2 * root + 2]);
        }


        protected void initBefore(int root, int left, int right, int middle) {
        }


        protected void initLeaf(int root, int index) {
            value[root] = array[index];
        }


        protected long queryPostProcess(int root, int left, int right, int from, int to, int middle, long leftResult,
                                        long rightResult) {
            return joinValue(leftResult, rightResult);
        }


        protected void queryPreProcess(int root, int left, int right, int from, int to, int middle) {
        }


        protected long queryFull(int root, int left, int right, int from, int to) {
            return value[root];
        }


        protected long emptySegmentResult() {
            return neutralValue();
        }

        protected abstract long neutralValue();

        protected abstract long joinValue(long left, long right);

    }

    static class LCA {
        private final long[] order;
        private final int[] position;
        private final Graph graph;
        private final IntervalTree lcaTree;
        private final int[] level;

        public LCA(Graph graph) {
            this(graph, 0);
        }

        public LCA(Graph graph, int root) {
            this.graph = graph;
            order = new long[2 * graph.vertexCount() - 1];
            position = new int[graph.vertexCount()];
            level = new int[graph.vertexCount()];
            int[] index = new int[graph.vertexCount()];
            for (int i = 0; i < index.length; i++) {
                index[i] = graph.firstOutbound(i);
            }
            int[] last = new int[graph.vertexCount()];
            int[] stack = new int[graph.vertexCount()];
            stack[0] = root;
            int size = 1;
            int j = 0;
            last[root] = -1;
            Arrays.fill(position, -1);
            while (size > 0) {
                int vertex = stack[--size];
                if (position[vertex] == -1) {
                    position[vertex] = j;
                }
                order[j++] = vertex;
                if (last[vertex] != -1) {
                    level[vertex] = level[last[vertex]] + 1;
                }
                while (index[vertex] != -1 && last[vertex] == graph.destination(index[vertex])) {
                    index[vertex] = graph.nextOutbound(index[vertex]);
                }
                if (index[vertex] != -1) {
                    stack[size++] = vertex;
                    stack[size++] = graph.destination(index[vertex]);
                    last[graph.destination(index[vertex])] = vertex;
                    index[vertex] = graph.nextOutbound(index[vertex]);
                }
            }
            lcaTree = new ReadOnlyIntervalTree(order) {

                protected long joinValue(long left, long right) {
                    if (left == -1) {
                        return right;
                    }
                    if (right == -1) {
                        return left;
                    }
                    if (level[((int) left)] < level[((int) right)]) {
                        return left;
                    }
                    return right;
                }


                protected long neutralValue() {
                    return -1;
                }
            };
            lcaTree.init();
        }

        public int getLCA(int first, int second) {
            return (int) lcaTree
                    .query(Math.min(position[first], position[second]), Math.max(position[first], position[second]));
        }

        public int getLevel(int vertex) {
            return level[vertex];
        }

    }

    static abstract class IntervalTree {
        protected int size;

        protected IntervalTree(int size) {
            this(size, true);
        }

        public IntervalTree(int size, boolean shouldInit) {
            this.size = size;
            int nodeCount = Math.max(1, Integer.highestOneBit(size) << 2);
            initData(size, nodeCount);
            if (shouldInit) {
                init();
            }
        }

        protected abstract void initData(int size, int nodeCount);

        protected abstract void initAfter(int root, int left, int right, int middle);

        protected abstract void initBefore(int root, int left, int right, int middle);

        protected abstract void initLeaf(int root, int index);

        protected abstract long queryPostProcess(int root, int left, int right, int from, int to, int middle,
                                                 long leftResult, long rightResult);

        protected abstract void queryPreProcess(int root, int left, int right, int from, int to, int middle);

        protected abstract long queryFull(int root, int left, int right, int from, int to);

        protected abstract long emptySegmentResult();

        public void init() {
            if (size == 0) {
                return;
            }
            init(0, 0, size - 1);
        }

        private void init(int root, int left, int right) {
            if (left == right) {
                initLeaf(root, left);
            } else {
                int middle = (left + right) >> 1;
                initBefore(root, left, right, middle);
                init(2 * root + 1, left, middle);
                init(2 * root + 2, middle + 1, right);
                initAfter(root, left, right, middle);
            }
        }

        public long query(int from, int to) {
            return query(0, 0, size - 1, from, to);
        }

        protected long query(int root, int left, int right, int from, int to) {
            if (left > to || right < from) {
                return emptySegmentResult();
            }
            if (left >= from && right <= to) {
                return queryFull(root, left, right, from, to);
            }
            int middle = (left + right) >> 1;
            queryPreProcess(root, left, right, from, to, middle);
            long leftResult = query(2 * root + 1, left, middle, from, to);
            long rightResult = query(2 * root + 2, middle + 1, right, from, to);
            return queryPostProcess(root, left, right, from, to, middle, leftResult, rightResult);
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

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }

        public void printLine(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

        public void printLine(int i) {
            writer.println(i);
        }

    }
}