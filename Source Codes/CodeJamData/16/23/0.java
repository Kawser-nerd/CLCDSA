import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.util.Arrays;
import java.util.AbstractSet;
import java.util.InputMismatchException;
import java.util.Random;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.Map;
import java.io.OutputStreamWriter;
import java.util.NoSuchElementException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Iterator;
import java.io.BufferedWriter;
import java.util.Set;
import java.io.IOException;
import java.util.AbstractMap;
import java.io.Writer;
import java.util.Map.Entry;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Egor Kulikov (egor@egork.net)
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
                if (toRun == null || candidate.lastModified() > toRun.lastModified()) {
                    toRun = candidate;
                }
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
        OutputWriter out = new OutputWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            Scheduler scheduler = new Scheduler(in, out, () -> new Task() {
                int n;
                int[] first;
                int[] second;


                public void read(InputReader in) {
                    n = in.readInt();
                    Indexer<String> f = new Indexer<>();
                    Indexer<String> s = new Indexer<>();
                    first = new int[n];
                    second = new int[n];
                    for (int i = 0; i < n; i++) {
                        first[i] = f.get(in.readString());
                        second[i] = s.get(in.readString());
                    }
                }

                int answer;


                public void solve() {
                    int fiCount = ArrayUtils.maxElement(first) + 1;
                    int seCount = ArrayUtils.maxElement(second) + 1;
                    Graph graph = new Graph(fiCount + seCount + 2);
                    int source = fiCount + seCount;
                    int sink = source + 1;
                    for (int i = 0; i < n; i++) {
                        graph.addFlowEdge(first[i], fiCount + second[i], 1);
                    }
                    for (int i = 0; i < fiCount; i++) {
                        graph.addFlowEdge(source, i, 1);
                    }
                    for (int i = 0; i < seCount; i++) {
                        graph.addFlowEdge(i + fiCount, sink, 1);
                    }
                    long flow = MaxFlow.dinic(graph, source, sink);
                    answer = (int) (n - fiCount - seCount + flow);
                }


                public void write(OutputWriter out, int testNumber) {
                    out.printLine("Case #" + testNumber + ":", answer);
                }
            }, 4);
        }

    }

    static interface IntCollection extends IntStream {
        public int size();

        default public boolean isEmpty() {
            return size() == 0;
        }

        default public void add(int value) {
            throw new UnsupportedOperationException();
        }

        default public IntCollection addAll(IntStream values) {
            for (IntIterator it = values.intIterator(); it.isValid(); it.advance()) {
                add(it.value());
            }
            return this;
        }

    }

    static interface TaskFactory {
        public Task newTask();

    }

    static interface IntList extends IntReversableCollection {
        public abstract int get(int index);

        public abstract void addAt(int index, int value);

        public abstract void removeAt(int index);

        default public IntIterator intIterator() {
            return new IntIterator() {
                private int at;
                private boolean removed;

                public int value() {
                    if (removed) {
                        throw new IllegalStateException();
                    }
                    return get(at);
                }

                public boolean advance() {
                    at++;
                    removed = false;
                    return isValid();
                }

                public boolean isValid() {
                    return !removed && at < size();
                }

                public void remove() {
                    removeAt(at);
                    at--;
                    removed = true;
                }
            };
        }


        default public void add(int value) {
            addAt(size(), value);
        }

    }

    static class MaxFlow {
        private final Graph graph;
        private int source;
        private int destination;
        private IntQueue queue;
        private int[] distance;
        private int[] nextEdge;

        public MaxFlow(Graph graph, int source, int destination) {
            this.graph = graph;
            this.source = source;
            this.destination = destination;
            int vertexCount = graph.vertexCount();
            queue = new IntArrayQueue(vertexCount);
            distance = new int[vertexCount];
            nextEdge = new int[vertexCount];
        }

        public static long dinic(Graph graph, int source, int destination) {
            return new MaxFlow(graph, source, destination).dinic();
        }

        public long dinic() {
            long totalFlow = 0;
            while (true) {
                edgeDistances();
                if (distance[destination] == -1) {
                    break;
                }
                Arrays.fill(nextEdge, -2);
                totalFlow += dinicImpl(source, Long.MAX_VALUE);
            }
            return totalFlow;
        }

        private void edgeDistances() {
            Arrays.fill(distance, -1);
            distance[source] = 0;
            queue.add(source);
            while (!queue.isEmpty()) {
                int current = queue.poll();
                int id = graph.firstOutbound(current);
                while (id != -1) {
                    if (graph.capacity(id) != 0) {
                        int next = graph.destination(id);
                        if (distance[next] == -1) {
                            distance[next] = distance[current] + 1;
                            queue.add(next);
                        }
                    }
                    id = graph.nextOutbound(id);
                }
            }
        }

        private long dinicImpl(int source, long flow) {
            if (source == destination) {
                return flow;
            }
            if (flow == 0 || distance[source] == distance[destination]) {
                return 0;
            }
            int id = nextEdge[source];
            if (id == -2) {
                nextEdge[source] = id = graph.firstOutbound(source);
            }
            long totalPushed = 0;
            while (id != -1) {
                int nextDestinationID = graph.destination(id);
                if (graph.capacity(id) != 0 && distance[nextDestinationID] == distance[source] + 1) {
                    long pushed = dinicImpl(nextDestinationID, Math.min(flow, graph.capacity(id)));
                    if (pushed != 0) {
                        graph.pushFlow(id, pushed);
                        flow -= pushed;
                        totalPushed += pushed;
                        if (flow == 0) {
                            return totalPushed;
                        }
                    }
                }
                nextEdge[source] = id = graph.nextOutbound(id);
            }
            return totalPushed;
        }

    }

    static class ArrayUtils {
        public static int maxElement(int[] array) {
            return new IntArray(array).max();
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

        public final int addFlowEdge(int from, int to, long capacity) {
            return addFlowWeightedEdge(from, to, 0, capacity);
        }

        public final int vertexCount() {
            return vertexCount;
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

        public final long capacity(int id) {
            if (capacity == null) {
                return 0;
            }
            return capacity[id];
        }

        public final long flow(int id) {
            if (reverseEdge == null) {
                return 0;
            }
            return capacity[reverseEdge[id]];
        }

        public final void pushFlow(int id, long flow) {
            if (flow == 0) {
                return;
            }
            if (flow > 0) {
                if (capacity(id) < flow) {
                    throw new IllegalArgumentException("Not enough capacity");
                }
            } else {
                if (flow(id) < -flow) {
                    throw new IllegalArgumentException("Not enough capacity");
                }
            }
            capacity[id] -= flow;
            capacity[reverseEdge[id]] += flow;
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

    static interface Task {
        public void read(InputReader in);

        public void solve();

        public void write(OutputWriter out, int testNumber);

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
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

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }

    static interface IntReversableCollection extends IntCollection {
    }

    static interface IntIterator {
        public int value() throws NoSuchElementException;

        public boolean advance();

        public boolean isValid();

    }

    static interface Edge {
    }

    static class Indexer<K> extends EHashMap<K, Integer> {
        private int index = 0;


        public Integer get(Object key) {
            if (!containsKey(key)) {
                put((K) key, index++);
            }
            return super.get(key);
        }

    }

    static class EHashMap<E, V> extends AbstractMap<E, V> {
        private static final int[] shifts = new int[10];
        private int size;
        private HashEntry<E, V>[] data;
        private int capacity;
        private Set<Entry<E, V>> entrySet;

        static {
            Random random = new Random(System.currentTimeMillis());
            for (int i = 0; i < 10; i++) {
                shifts[i] = 1 + 3 * i + random.nextInt(3);
            }
        }

        public EHashMap() {
            this(4);
        }

        private void setCapacity(int size) {
            capacity = Integer.highestOneBit(4 * size);
            //noinspection unchecked
            data = new HashEntry[capacity];
        }

        public EHashMap(int maxSize) {
            setCapacity(maxSize);
            entrySet = new AbstractSet<Entry<E, V>>() {

                public Iterator<Entry<E, V>> iterator() {
                    return new Iterator<Entry<E, V>>() {
                        private HashEntry<E, V> last = null;
                        private HashEntry<E, V> current = null;
                        private HashEntry<E, V> base = null;
                        private int lastIndex = -1;
                        private int index = -1;

                        public boolean hasNext() {
                            if (current == null) {
                                for (index++; index < capacity; index++) {
                                    if (data[index] != null) {
                                        base = current = data[index];
                                        break;
                                    }
                                }
                            }
                            return current != null;
                        }

                        public Entry<E, V> next() {
                            if (!hasNext()) {
                                throw new NoSuchElementException();
                            }
                            last = current;
                            lastIndex = index;
                            current = current.next;
                            if (base.next != last) {
                                base = base.next;
                            }
                            return last;
                        }

                        public void remove() {
                            if (last == null) {
                                throw new IllegalStateException();
                            }
                            size--;
                            if (base == last) {
                                data[lastIndex] = last.next;
                            } else {
                                base.next = last.next;
                            }
                        }
                    };
                }


                public int size() {
                    return size;
                }
            };
        }

        public EHashMap(Map<E, V> map) {
            this(map.size());
            putAll(map);
        }


        public Set<Entry<E, V>> entrySet() {
            return entrySet;
        }


        public void clear() {
            Arrays.fill(data, null);
            size = 0;
        }

        private int index(Object o) {
            return getHash(o.hashCode()) & (capacity - 1);
        }

        private int getHash(int h) {
            int result = h;
            for (int i : shifts) {
                result ^= h >>> i;
            }
            return result;
        }


        public V remove(Object o) {
            if (o == null) {
                return null;
            }
            int index = index(o);
            HashEntry<E, V> current = data[index];
            HashEntry<E, V> last = null;
            while (current != null) {
                if (current.key.equals(o)) {
                    if (last == null) {
                        data[index] = current.next;
                    } else {
                        last.next = current.next;
                    }
                    size--;
                    return current.value;
                }
                last = current;
                current = current.next;
            }
            return null;
        }


        public V put(E e, V value) {
            if (e == null) {
                return null;
            }
            int index = index(e);
            HashEntry<E, V> current = data[index];
            if (current != null) {
                while (true) {
                    if (current.key.equals(e)) {
                        V oldValue = current.value;
                        current.value = value;
                        return oldValue;
                    }
                    if (current.next == null) {
                        break;
                    }
                    current = current.next;
                }
            }
            if (current == null) {
                data[index] = new HashEntry<E, V>(e, value);
            } else {
                current.next = new HashEntry<E, V>(e, value);
            }
            size++;
            if (2 * size > capacity) {
                HashEntry<E, V>[] oldData = data;
                setCapacity(size);
                for (HashEntry<E, V> entry : oldData) {
                    while (entry != null) {
                        HashEntry<E, V> next = entry.next;
                        index = index(entry.key);
                        entry.next = data[index];
                        data[index] = entry;
                        entry = next;
                    }
                }
            }
            return null;
        }


        public V get(Object o) {
            if (o == null) {
                return null;
            }
            int index = index(o);
            HashEntry<E, V> current = data[index];
            while (current != null) {
                if (current.key.equals(o)) {
                    return current.value;
                }
                current = current.next;
            }
            return null;
        }


        public boolean containsKey(Object o) {
            if (o == null) {
                return false;
            }
            int index = index(o);
            HashEntry<E, V> current = data[index];
            while (current != null) {
                if (current.key.equals(o)) {
                    return true;
                }
                current = current.next;
            }
            return false;
        }


        public int size() {
            return size;
        }

        private static class HashEntry<E, V> implements Entry<E, V> {
            private final E key;
            private V value;
            private HashEntry<E, V> next;

            private HashEntry(E key, V value) {
                this.key = key;
                this.value = value;
            }

            public E getKey() {
                return key;
            }

            public V getValue() {
                return value;
            }

            public V setValue(V value) {
                V oldValue = this.value;
                this.value = value;
                return oldValue;
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

    }

    static class IntArray extends IntAbstractStream implements IntList {
        private int[] data;

        public IntArray(int[] arr) {
            data = arr;
        }

        public int size() {
            return data.length;
        }

        public int get(int at) {
            return data[at];
        }

        public void addAt(int index, int value) {
            throw new UnsupportedOperationException();
        }

        public void removeAt(int index) {
            throw new UnsupportedOperationException();
        }

    }

    static abstract class IntAbstractStream implements IntStream {

        public String toString() {
            StringBuilder builder = new StringBuilder();
            boolean first = true;
            for (IntIterator it = intIterator(); it.isValid(); it.advance()) {
                if (first) {
                    first = false;
                } else {
                    builder.append(' ');
                }
                builder.append(it.value());
            }
            return builder.toString();
        }


        public boolean equals(Object o) {
            if (!(o instanceof IntStream)) {
                return false;
            }
            IntStream c = (IntStream) o;
            IntIterator it = intIterator();
            IntIterator jt = c.intIterator();
            while (it.isValid() && jt.isValid()) {
                if (it.value() != jt.value()) {
                    return false;
                }
                it.advance();
                jt.advance();
            }
            return !it.isValid() && !jt.isValid();
        }


        public int hashCode() {
            int result = 0;
            for (IntIterator it = intIterator(); it.isValid(); it.advance()) {
                result *= 31;
                result += it.value();
            }
            return result;
        }

    }

    static interface IntStream extends Iterable<Integer>, Comparable<IntStream> {
        public IntIterator intIterator();

        default public Iterator<Integer> iterator() {
            return new Iterator<Integer>() {
                private IntIterator it = intIterator();

                public boolean hasNext() {
                    return it.isValid();
                }

                public Integer next() {
                    int result = it.value();
                    it.advance();
                    return result;
                }
            };
        }

        default public int compareTo(IntStream c) {
            IntIterator it = intIterator();
            IntIterator jt = c.intIterator();
            while (it.isValid() && jt.isValid()) {
                int i = it.value();
                int j = jt.value();
                if (i < j) {
                    return -1;
                } else if (i > j) {
                    return 1;
                }
                it.advance();
                jt.advance();
            }
            if (it.isValid()) {
                return 1;
            }
            if (jt.isValid()) {
                return -1;
            }
            return 0;
        }

        default public int max() {
            int result = Integer.MIN_VALUE;
            for (IntIterator it = intIterator(); it.isValid(); it.advance()) {
                int current = it.value();
                if (current > result) {
                    result = current;
                }
            }
            return result;
        }

    }

    static class Scheduler {
        private final AtomicInteger testsRemaining;
        private final AtomicInteger threadsRemaining;

        public Scheduler(InputReader in, OutputWriter out, TaskFactory factory, int numParallel) {
            try {
                testsRemaining = new AtomicInteger(in.readInt());
                threadsRemaining = new AtomicInteger(numParallel);
                Task[] tasks = new Task[testsRemaining.get()];
                for (int i = 0; i < tasks.length; i++) {
                    tasks[i] = factory.newTask();
                }
                for (Task task : tasks) {
                    task.read(in);
                    new Thread(() -> {
                        boolean freeThread = false;
                        synchronized (this) {
                            do {
                                try {
                                    wait(10);
                                } catch (InterruptedException ignored) {
                                }
                                if (threadsRemaining.get() != 0) {
                                    synchronized (threadsRemaining) {
                                        if (threadsRemaining.get() != 0) {
                                            threadsRemaining.decrementAndGet();
                                            freeThread = true;
                                        }
                                    }
                                }
                            } while (!freeThread);
                        }
                        task.solve();
                        System.err.println(testsRemaining.decrementAndGet());
                        threadsRemaining.incrementAndGet();
                    }).start();
                }
                synchronized (this) {
                    while (testsRemaining.get() > 0) {
                        wait(10);
                    }
                }
                for (int i = 0; i < tasks.length; i++) {
                    tasks[i].write(out, i + 1);
                }
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }

    }

    static class IntArrayQueue implements IntQueue {
        private int[] data;
        private int from;
        private int to;

        public IntArrayQueue(int capacity) {
            data = new int[Integer.highestOneBit(capacity) << 1];
        }

        public IntArrayQueue() {
            this(3);
        }

        public IntArrayQueue(int[] array) {
            this(array.length);
            to = array.length;
            System.arraycopy(array, 0, data, 0, to);
        }

        public IntArrayQueue(IntStream s) {
            addAll(s);
        }

        public IntArrayQueue(IntCollection c) {
            this(c.size());
            addAll(c);
        }

        public int size() {
            return (to - from) & (data.length - 1);
        }

        public void add(int v) {
            ensureCapacity(size() + 1);
            data[to++] = v;
            to &= data.length - 1;
        }

        public int poll() {
            if (from == to) {
                throw new NoSuchElementException();
            }
            int result = data[from++];
            from &= data.length - 1;
            return result;
        }

        public IntIterator intIterator() {
            return new IntIterator() {
                private int at = from;

                public int value() {
                    if (at == to) {
                        throw new NoSuchElementException();
                    }
                    return data[at];
                }

                public boolean advance() {
                    if (!isValid()) {
                        throw new NoSuchElementException();
                    }
                    at++;
                    at &= data.length - 1;
                    return isValid();
                }

                public boolean isValid() {
                    return at != to;
                }

                public void remove() {
                    throw new UnsupportedOperationException();
                }
            };
        }

        private void ensureCapacity(int capacity) {
            if (data.length <= capacity) {
                int[] newData = new int[Integer.highestOneBit(capacity) << 1];
                if (from <= to) {
                    System.arraycopy(data, from, newData, 0, size());
                } else {
                    System.arraycopy(data, from, newData, 0, data.length - from);
                    System.arraycopy(data, 0, newData, data.length - from, to);
                }
                to = size();
                from = 0;
                data = newData;
            }
        }

    }

    static interface IntQueue extends IntCollection {
        public int poll();

    }
}

