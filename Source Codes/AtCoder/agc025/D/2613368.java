import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.AbstractSet;
import java.util.Random;
import java.util.InputMismatchException;
import java.util.TreeSet;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Map;
import java.io.OutputStreamWriter;
import java.util.NoSuchElementException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Iterator;
import java.io.BufferedWriter;
import java.util.Set;
import java.util.NavigableSet;
import java.io.IOException;
import java.util.List;
import java.util.AbstractMap;
import java.util.Map.Entry;
import java.io.Writer;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int d1 = in.readInt();
            int d2 = in.readInt();
            List<IntIntPair> answer = solve(n, d1, d2);
            for (IntIntPair result : answer) {
                out.printLine(result.first, result.second);
            }
            if (true) {
                return;
            }
            if (d1 % 4 != 0 && d2 % 4 != 0) {
                for (int i = 0; i < 2 * n; i += 2) {
                    for (int j = 0; j < 2 * n; j += 2) {
                        out.printLine(i, j);
                    }
                }
                return;
            }
            List<Pair<IntIntPair, Integer>> doubleBad = new ArrayList<>();
            List<IntIntPair> bad = new ArrayList<>();
            int j = 1000;
            for (int i = 0; i * i <= d1; i++) {
                while (i * i + j * j > d1) {
                    j--;
                }
                if (i * i + j * j == d1) {
                    bad.add(new IntIntPair(i, j));
                    if (i != 0) {
                        bad.add(new IntIntPair(-i, j));
                        if (j != 0) {
                            bad.add(new IntIntPair(-i, -j));
                        }
                    }
                    if (j != 0) {
                        bad.add(new IntIntPair(i, -j));
                    }
                }
            }
            if (d1 != d2) {
                j = 1000;
                for (int i = 0; i * i <= d2; i++) {
                    while (i * i + j * j > d2) {
                        j--;
                    }
                    if (i * i + j * j == d2) {
                        bad.add(new IntIntPair(i, j));
                        if (i != 0) {
                            bad.add(new IntIntPair(-i, j));
                            if (j != 0) {
                                bad.add(new IntIntPair(-i, -j));
                            }
                        }
                        if (j != 0) {
                            bad.add(new IntIntPair(i, -j));
                        }
                    }
                }
            }
            Set<IntIntPair> setBad = new HashSet<>(bad);
            Counter<IntIntPair> counter = new Counter<>();
            for (IntIntPair pair : bad) {
                for (IntIntPair intPair : bad) {
                    int x = pair.first + intPair.first;
                    int y = pair.second + intPair.second;
                    if (x == 0 && y == 0) {
                        continue;
                    }
                    IntIntPair key = new IntIntPair(x, y);
                    if (setBad.contains(key)) {
                        continue;
                    }
                    counter.add(key);
                }
            }
            for (Map.Entry<IntIntPair, Long> entry : counter.entrySet()) {
                doubleBad.add(Pair.makePair(entry.getKey(), (int) (long) entry.getValue()));
            }
            int[] qty = new int[4 * n * n];
            for (int i = 0; i < 2 * n; i++) {
                for (int k = 0; k < 2 * n; k++) {
                    int at = i * 2 * n + k;
                    for (IntIntPair pair : bad) {
                        if (MiscUtils.isValidCell(i + pair.first, k + pair.second, 2 * n, 2 * n)) {
                            qty[at]++;
                        }
                    }
                }
            }
            int[] ord = new int[4 * n * n];
            IntHashSet was = new IntHashSet();
            Random random = new Random(4);
            for (int i = 0; i < 4 * n * n; i++) {
                int current;
                do {
                    current = random.nextInt(1000000000);
                } while (was.contains(current));
                was.add(current);
                ord[i] = current;
            }
            NavigableSet<Integer> order = new TreeSet<>((a, b) -> qty[a] != qty[b] ? qty[a] - qty[b] : ord[a] - ord[b]);
            for (int i = 0; i < 4 * n * n; i++) {
                order.add(i);
            }
            boolean[] cant = new boolean[4 * n * n];
            for (int i = 0; i < n * n; i++) {
                int current = order.pollFirst();
                cant[current] = true;
                int row = current / (2 * n);
                int column = current % (2 * n);
                for (IntIntPair pair : bad) {
                    int nRow = pair.first + row;
                    int nCol = pair.second + column;
                    if (!MiscUtils.isValidCell(nRow, nCol, 2 * n, 2 * n)) {
                        continue;
                    }
                    int key = nRow * 2 * n + nCol;
                    if (cant[key]) {
                        continue;
                    }
                    cant[key] = true;
                    order.remove(key);
                    for (IntIntPair by : bad) {
                        int xRow = nRow + by.first;
                        int xCol = nCol + by.second;
                        if (!MiscUtils.isValidCell(xRow, xCol, 2 * n, 2 * n)) {
                            continue;
                        }
                        int xKey = xRow * 2 * n + xCol;
                        if (cant[xKey]) {
                            continue;
                        }
                        order.remove(xKey);
                        qty[xKey]--;
                        order.add(xKey);
                    }
                }
                out.printLine(row, column);
//            System.err.println(row + " " + column);
            }
        }

        List<IntIntPair> solve(int n, int d1, int d2) {
            List<IntIntPair> answer = new ArrayList<>();
            if (d1 % 4 != 0 && d2 % 4 != 0) {
                for (int i = 0; i < 2 * n; i += 2) {
                    for (int j = 0; j < 2 * n; j += 2) {
                        answer.add(new IntIntPair(i, j));
                    }
                }
                return answer;
            }
            if (d1 % 4 == 0 && d2 % 4 == 0) {
                List<IntIntPair> call = solve((n + 1) / 2, d1 / 4, d2 / 4);
                for (IntIntPair pair : call) {
                    if (pair.first < n && pair.second < n) {
                        if (answer.size() < n * n) {
                            answer.add(new IntIntPair(2 * pair.first, 2 * pair.second));
                        }
                        if (answer.size() < n * n) {
                            answer.add(new IntIntPair(2 * pair.first, 2 * pair.second + 1));
                        }
                        if (answer.size() < n * n) {
                            answer.add(new IntIntPair(2 * pair.first + 1, 2 * pair.second));
                        }
                        if (answer.size() < n * n) {
                            answer.add(new IntIntPair(2 * pair.first + 1, 2 * pair.second + 1));
                        }
                    }
                }
                return answer;
            }
            if (d2 % 4 == 0) {
                return solve(n, d2, d1);
            }
            List<IntIntPair> call = solve((n + 1) / 2, d1 / 4);
            for (IntIntPair pair : call) {
                if (pair.first < n && pair.second < n) {
                    if (answer.size() < n * n) {
                        answer.add(new IntIntPair(2 * pair.first, 2 * pair.second));
                    }
                    if (answer.size() < n * n && d2 % 2 == 0) {
                        answer.add(new IntIntPair(2 * pair.first, 2 * pair.second + 1));
                    }
                    if (answer.size() < n * n && d2 % 2 == 1) {
                        answer.add(new IntIntPair(2 * pair.first + 1, 2 * pair.second + 1));
                    }
                }
            }
            return answer;
        }

        private List<IntIntPair> solve(int n, int d) {
            List<IntIntPair> answer = new ArrayList<>();
            if (d % 4 == 0) {
                List<IntIntPair> call = solve((n + 1) / 2, d / 4);
                for (IntIntPair pair : call) {
                    if (pair.first < n && pair.second < n) {
                        answer.add(new IntIntPair(2 * pair.first, 2 * pair.second));
                        answer.add(new IntIntPair(2 * pair.first, 2 * pair.second + 1));
                        answer.add(new IntIntPair(2 * pair.first + 1, 2 * pair.second));
                        answer.add(new IntIntPair(2 * pair.first + 1, 2 * pair.second + 1));
                    }
                }
                return answer;
            }
            if (d % 2 == 0) {
                for (int i = 0; i < 2 * n; i += 2) {
                    for (int j = 0; j < 2 * n; j++) {
                        answer.add(new IntIntPair(i, j));
                    }
                }
                return answer;
            }
            for (int i = 0; i < 2 * n; i++) {
                for (int j = i % 2; j < 2 * n; j += 2) {
                    answer.add(new IntIntPair(i, j));
                }
            }
            return answer;
        }

    }

    static interface IntIterator {
        public int value() throws NoSuchElementException;

        public boolean advance();

        public boolean isValid();

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

    static interface IntSet extends IntCollection {
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

    }

    static class IntIntPair implements Comparable<IntIntPair> {
        public final int first;
        public final int second;

        public IntIntPair(int first, int second) {
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

            IntIntPair pair = (IntIntPair) o;

            return first == pair.first && second == pair.second;
        }


        public int hashCode() {
            int result = first;
            result = 31 * result + second;
            return result;
        }


        public String toString() {
            return "(" + first + "," + second + ")";
        }

        @SuppressWarnings({"unchecked"})
        public int compareTo(IntIntPair o) {
            int value = Integer.compare(first, o.first);
            if (value != 0) {
                return value;
            }
            return Integer.compare(second, o.second);
        }

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
        public static boolean isValidCell(int row, int column, int rowCount, int columnCount) {
            return row >= 0 && row < rowCount && column >= 0 && column < columnCount;
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

    static class IntHashSet extends IntAbstractStream implements IntSet {
        private static final Random RND = new Random();
        private static final int[] SHIFTS = new int[4];
        private static final byte PRESENT_MASK = 1;
        private static final byte REMOVED_MASK = 2;
        private int size;
        private int realSize;
        private int[] values;
        private byte[] present;
        private int step;
        private int ratio;

        static {
            for (int i = 0; i < 4; i++) {
                SHIFTS[i] = RND.nextInt(31) + 1;
            }
        }

        public IntHashSet() {
            this(3);
        }

        public IntHashSet(int capacity) {
            capacity = Math.max(capacity, 3);
            values = new int[capacity];
            present = new byte[capacity];
            ratio = 2;
            initStep(capacity);
        }

        public IntHashSet(IntCollection c) {
            this(c.size());
            addAll(c);
        }

        public IntHashSet(int[] arr) {
            this(new IntArray(arr));
        }

        private void initStep(int capacity) {
            step = RND.nextInt(capacity - 2) + 1;
            while (IntegerUtils.gcd(step, capacity) != 1) {
                step++;
            }
        }


        public IntIterator intIterator() {
            return new IntIterator() {
                private int position = size == 0 ? values.length : -1;

                public int value() throws NoSuchElementException {
                    if (position == -1) {
                        advance();
                    }
                    if (position >= values.length) {
                        throw new NoSuchElementException();
                    }
                    if ((present[position] & PRESENT_MASK) == 0) {
                        throw new IllegalStateException();
                    }
                    return values[position];
                }

                public boolean advance() throws NoSuchElementException {
                    if (position >= values.length) {
                        throw new NoSuchElementException();
                    }
                    position++;
                    while (position < values.length && (present[position] & PRESENT_MASK) == 0) {
                        position++;
                    }
                    return isValid();
                }

                public boolean isValid() {
                    return position < values.length;
                }

                public void remove() {
                    if ((present[position] & PRESENT_MASK) == 0) {
                        throw new IllegalStateException();
                    }
                    present[position] = REMOVED_MASK;
                }
            };
        }


        public int size() {
            return size;
        }


        public void add(int value) {
            ensureCapacity((realSize + 1) * ratio + 2);
            int current = getHash(value);
            while (present[current] != 0) {
                if ((present[current] & PRESENT_MASK) != 0 && values[current] == value) {
                    return;
                }
                current += step;
                if (current >= values.length) {
                    current -= values.length;
                }
            }
            while ((present[current] & PRESENT_MASK) != 0) {
                current += step;
                if (current >= values.length) {
                    current -= values.length;
                }
            }
            if (present[current] == 0) {
                realSize++;
            }
            present[current] = PRESENT_MASK;
            values[current] = value;
            size++;
        }

        private int getHash(int value) {
            int hash = IntHash.hash(value);
            int result = hash;
            for (int i : SHIFTS) {
                result ^= hash >> i;
            }
            result %= values.length;
            if (result < 0) {
                result += values.length;
            }
            return result;
        }

        private void ensureCapacity(int capacity) {
            if (values.length < capacity) {
                capacity = Math.max(capacity * 2, values.length);
                rebuild(capacity);
            }
        }

        private void rebuild(int capacity) {
            initStep(capacity);
            int[] oldValues = values;
            byte[] oldPresent = present;
            values = new int[capacity];
            present = new byte[capacity];
            size = 0;
            realSize = 0;
            for (int i = 0; i < oldValues.length; i++) {
                if ((oldPresent[i] & PRESENT_MASK) == PRESENT_MASK) {
                    add(oldValues[i]);
                }
            }
        }


        public boolean contains(int value) {
            int current = getHash(value);
            while (present[current] != 0) {
                if (values[current] == value && (present[current] & PRESENT_MASK) != 0) {
                    return true;
                }
                current += step;
                if (current >= values.length) {
                    current -= values.length;
                }
            }
            return false;
        }

    }

    static class Counter<K> extends EHashMap<K, Long> {
        public Counter() {
            super();
        }

        public Counter(int capacity) {
            super(capacity);
        }

        public long add(K key) {
            long result = get(key);
            put(key, result + 1);
            return result + 1;
        }


        public Long get(Object key) {
            if (containsKey(key)) {
                return super.get(key);
            }
            return 0L;
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

    static class IntHash {
        private IntHash() {
        }

        public static int hash(int c) {
            return c;
        }

    }

    static class IntegerUtils {
        public static int gcd(int a, int b) {
            a = Math.abs(a);
            b = Math.abs(b);
            while (b != 0) {
                int temp = a % b;
                a = b;
                b = temp;
            }
            return a;
        }

    }

    static interface IntReversableCollection extends IntCollection {
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

    static interface IntCollection extends IntStream {
        public int size();

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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.