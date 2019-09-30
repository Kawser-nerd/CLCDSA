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
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.Random;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.Map;
import java.io.OutputStreamWriter;
import java.util.NoSuchElementException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.util.Iterator;
import java.io.BufferedWriter;
import java.util.Set;
import java.io.IOException;
import java.util.List;
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
            final String regex = "A-(small|large).*[.]in";
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
            outputStream = new FileOutputStream("a.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            Scheduler scheduler = new Scheduler(in, out, () -> new Task() {
                private TaskA.Node terminal;
                long a;
                long b;
                String r;


                public void read(InputReader in) {
                    a = in.readLong();
                    b = in.readLong();
                    r = in.readString();
                }

                TaskA.Node root;
                Map<Pair<Set<TaskA.Node>, Integer>, Long> answer = new HashMap<>();
                long result;


                public void solve() {
                    terminal = new TaskA.Node(true);
                    root = parse(0, r.length(), terminal);
                    result = 0;
                    NumberIterator iterator = new NumberIterator() {

                        protected void process(long prefix, int remainingDigits) {
                            String s = Long.toString(prefix);
                            Set<TaskA.Node> current = new HashSet<>();
                            epsLinks(root, current);
                            for (char c : s.toCharArray()) {
                                current = advance(current, c - '0');
                            }
                            result += solve(current, remainingDigits);
                        }
                    };
                    iterator.run(a, b);
                }

                private long solve(Set<TaskA.Node> current, int remainingDigits) {
                    Pair<Set<TaskA.Node>, Integer> key = Pair.makePair(current, remainingDigits);
                    if (answer.containsKey(key)) {
                        return answer.get(key);
                    }
                    long result = 0;
                    if (remainingDigits == 0) {
                        if (current.contains(terminal)) {
                            result = 1;
                        }
                    } else {
                        for (int i = 0; i < 10; i++) {
                            result += solve(advance(current, i), remainingDigits - 1);
                        }
                    }
                    answer.put(key, result);
                    return result;
                }

                Set<TaskA.Node> advance(Set<TaskA.Node> set, int by) {
                    Set<TaskA.Node> result = new HashSet<>();
                    for (TaskA.Node node : set) {
                        for (TaskA.Node to : node.links.get(by)) {
                            epsLinks(to, result);
                        }
                    }
                    return result;
                }

                private void epsLinks(TaskA.Node node, Set<TaskA.Node> result) {
                    if (result.contains(node)) {
                        return;
                    }
                    result.add(node);
                    for (TaskA.Node to : node.links.get(-1)) {
                        epsLinks(to, result);
                    }
                }

                private TaskA.Node parse(int from, int to, TaskA.Node leadTo) {
                    if (from + 1 == to) {
                        TaskA.Node node = new TaskA.Node(false);
                        node.links.get(r.charAt(from) - '0').add(leadTo);
                        return node;
                    }
                    int level = 0;
                    for (int i = from; i < to; i++) {
                        char c = r.charAt(i);
                        if (c != '*' && level == 0 && i != from) {
                            TaskA.Node node = parse(i, to, leadTo);
                            return parse(from, i, node);
                        }
                        if (c == '(') {
                            level++;
                        } else if (c == ')') {
                            level--;
                        }
                    }
                    if (r.charAt(to - 1) == ')') {
                        TaskA.Node root = new TaskA.Node(false);
                        level = 0;
                        int start = from + 1;
                        for (int i = from + 1; i < to - 1; i++) {
                            char c = r.charAt(i);
                            if (c == '(') {
                                level++;
                            } else if (c == ')') {
                                level--;
                            } else if (c == '|' && level == 0) {
                                root.links.get(-1).add(parse(start, i, leadTo));
                                start = i + 1;
                            }
                        }
                        root.links.get(-1).add(parse(start, to - 1, leadTo));
                        return root;
                    }
                    TaskA.Node root = new TaskA.Node(false);
                    root.links.get(-1).add(leadTo);
                    root.links.get(-1).add(parse(from + 1, to - 2, root));
                    return root;
                }


                public void write(OutputWriter out, int testNumber) {
                    out.printLine("Case #" + testNumber + ":", result);
                }
            }, 4);
        }

        static class Node {
            boolean terminal;
            Map<Integer, List<TaskA.Node>> links = new CPPMap<>(new Factory<List<TaskA.Node>>() {

                public List<TaskA.Node> create() {
                    return new ArrayList<>();
                }
            });

            public Node(boolean terminal) {
                this.terminal = terminal;
            }

        }

    }

    static class CPPMap<K, V> extends EHashMap<K, V> {
        private final Factory<V> defaultValueFactory;

        public CPPMap(Factory<V> defaultValueFactory) {
            this.defaultValueFactory = defaultValueFactory;
        }


        public V get(Object key) {
            if (containsKey(key)) {
                return super.get(key);
            }
            V value = defaultValueFactory.create();
            try {
                //noinspection unchecked
                super.put((K) key, value);
                return value;
            } catch (ClassCastException e) {
                return value;
            }
        }

    }

    static abstract class NumberIterator {
        protected final long base;
        protected final long[] power;

        protected NumberIterator() {
            this(10);
        }

        protected NumberIterator(int base) {
            this.base = base;
            power = IntegerUtils.generatePowers(base, Long.MAX_VALUE);
        }

        protected abstract void process(long prefix, int remainingDigits);

        public void run(long from, long to) {
            if (from < 0 || from > to) {
                throw new IllegalArgumentException();
            }
            to++;
            for (int i = 0; ; i++) {
                if (i != power.length - 1 && from / power[i + 1] != to / power[i + 1]) {
                    long prefix = from / power[i + 1] * base;
                    for (int j = (int) (from / power[i] % base); j < base; j++) {
                        process(prefix + j, i);
                    }
                    from /= power[i + 1];
                    from++;
                    from *= power[i + 1];
                } else {
                    long upTo = to / power[i] % base;
                    long prefix = from / power[i] / base * base;
                    for (int j = (int) (from / power[i] % base); j < upTo; j++) {
                        process(prefix + j, i);
                    }
                    for (int k = i - 1; k >= 0; k--) {
                        upTo = to / power[k] % base;
                        prefix = to / power[k + 1] * base;
                        for (int j = 0; j < upTo; j++) {
                            process(prefix + j, k);
                        }
                    }
                    break;
                }
            }
        }

    }

    static interface Factory<V> {
        public V create();

    }

    static interface Task {
        public void read(InputReader in);

        public void solve();

        public void write(OutputWriter out, int testNumber);

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

    static interface TaskFactory {
        public Task newTask();

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

        public long readLong() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
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

    static class IntegerUtils {
        public static long[] generatePowers(long base, int count, long mod) {
            long[] result = new long[count];
            if (count != 0) {
                result[0] = 1 % mod;
            }
            for (int i = 1; i < count; i++) {
                result[i] = result[i - 1] * base % mod;
            }
            return result;
        }

        public static long[] generatePowers(long base, long maxValue) {
            if (maxValue <= 0) {
                return new long[0];
            }
            int size = 1;
            long current = 1;
            while (maxValue / base >= current) {
                current *= base;
                size++;
            }
            return generatePowers(base, size, Long.MAX_VALUE);
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

    static class EHashMap<E, V> extends AbstractMap<E, V> {
        private static final int[] shifts = new int[10];
        private int size;
        private EHashMap.HashEntry<E, V>[] data;
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
            data = new EHashMap.HashEntry[capacity];
        }

        public EHashMap(int maxSize) {
            setCapacity(maxSize);
            entrySet = new AbstractSet<Entry<E, V>>() {

                public Iterator<Entry<E, V>> iterator() {
                    return new Iterator<Entry<E, V>>() {
                        private EHashMap.HashEntry<E, V> last = null;
                        private EHashMap.HashEntry<E, V> current = null;
                        private EHashMap.HashEntry<E, V> base = null;
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
            EHashMap.HashEntry<E, V> current = data[index];
            EHashMap.HashEntry<E, V> last = null;
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
            EHashMap.HashEntry<E, V> current = data[index];
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
                data[index] = new EHashMap.HashEntry<E, V>(e, value);
            } else {
                current.next = new EHashMap.HashEntry<E, V>(e, value);
            }
            size++;
            if (2 * size > capacity) {
                EHashMap.HashEntry<E, V>[] oldData = data;
                setCapacity(size);
                for (EHashMap.HashEntry<E, V> entry : oldData) {
                    while (entry != null) {
                        EHashMap.HashEntry<E, V> next = entry.next;
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
            EHashMap.HashEntry<E, V> current = data[index];
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
            EHashMap.HashEntry<E, V> current = data[index];
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
            private EHashMap.HashEntry<E, V> next;

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
}

