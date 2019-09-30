import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Random;
import java.util.Scanner;

public class B implements Runnable {

    @SuppressWarnings("unused")
    public void run() {
        Scanner in = new Scanner(System.in);
        for (int casei : ZeroTo.get(in.nextInt())) {
            int n = in.nextInt();
            MutableUndirectedGraph<Integer> g = MutableUndirectedGraph.create();
            for (int i : FromTo.get(1, n + 1)) g.insertVertex(i);
            for (int i : ZeroTo.get(n - 1)) g.addEdge(in.nextInt(), in.nextInt());
            AdjacencyList<Integer, UndirectedEdge<Integer>> adj = AdjacencyListFromGraph.createFromUndirected(g);
            int min = 1000000000;
            for (int root : FromTo.get(1, n + 1)) min = Math.min(min, calcMinAndSize(adj, root, 0).v1);
            System.out.println("Case #" + (casei + 1) + ": " + min);
        }
        in.close();
    }

    private Pair<Integer, Integer> calcMinAndSize(AdjacencyList<Integer, UndirectedEdge<Integer>> adj, int v, int parentOrZero) {
        int min;
        int subTreeSize = 1;
        DynamicArray<Pair<Integer, Integer>> subResult = DynamicArray.create();
        for (UndirectedEdge<Integer> e : adj.getEdges(v)) {
            int opposite = OppositeInUndirectedEdge.get(e, v);
            if (opposite != parentOrZero) {
                Pair<Integer, Integer> sub = calcMinAndSize(adj, opposite, v);
                subResult.addToLast(sub);
                subTreeSize += sub.v2;
            }
        }
        if (subResult.size() == 0) {
            min = 0;
        } else if (subResult.size() == 2) {
            min = subResult.get(0).v1 + subResult.get(1).v1;
        } else if (subResult.size() == 1) {
            min = subResult.get(0).v2;
        } else {
            GoodSortingAlgorithm.getInstance().sort(subResult, new Comparator<Pair<Integer, Integer>>() {

                public int compare(Pair<Integer, Integer> o1, Pair<Integer, Integer> o2) {
                    return IntegerNumberSystem.getInstance().compare(o1.v2 - o1.v1, o2.v2 - o2.v1);
                }
            });
            min = 0;
            for (int i : ZeroTo.get(subResult.size())) {
                if (i < subResult.size() - 2) min += subResult.get(i).v2; else min += subResult.get(i).v1;
            }
        }
        return Pair.create(min, subTreeSize);
    }

    public static void main(String[] args) throws Exception {
        System.setIn(new BufferedInputStream(new FileInputStream("input.txt")));
        new B().run();
    }
}

class GoodSortingAlgorithm {

    private static final SortingAlgorithm INSTANCE = RandomizedQuicksort.getInstance();

    public static SortingAlgorithm getInstance() {
        return INSTANCE;
    }
}

class RandomizedQuicksort {

    private static Random RANDOM = new Random();

    public static SortingAlgorithm getInstance() {
        return new SortingAlgorithm() {

            public <T> void sort(MutableArray<T> a, Comparator<T> comparator) {
                sortRecursively(a, 0, a.size(), comparator);
            }
        };
    }

    private static <T> void sortRecursively(MutableArray<T> a, int start, int end, Comparator<T> comp) {
        if (end - start <= 1) return;
        int randomIndex = RANDOM.nextInt(end - start) + start;
        ArraySwapper.swap(a, start, randomIndex);
        int pos = start;
        for (int i = start + 1; i < end; i++) {
            int c = comp.compare(a.get(i), a.get(start));
            if (c < 0 || c == 0 && RANDOM.nextBoolean()) ArraySwapper.swap(a, i, ++pos);
        }
        ArraySwapper.swap(a, start, pos);
        sortRecursively(a, start, pos, comp);
        sortRecursively(a, pos + 1, end, comp);
    }

    private RandomizedQuicksort() {
    }
}

class ArraySwapper {

    public static <T> void swap(MutableArray<T> a, int p1, int p2) {
        T t = a.get(p1);
        a.set(p1, a.get(p2));
        a.set(p2, t);
    }
}

interface MutableArray<T> extends Array<T> {

    void set(int index, T value);
}

interface Array<T> extends Collection<T> {

    T get(int index);
}

interface Collection<T> extends Iterable<T> {

    int size();

    boolean isEmpty();
}

interface SortingAlgorithm {

    <T> void sort(MutableArray<T> a, Comparator<T> comparator);
}

class FromTo {

    public static Iterable<Integer> get(int begin, int end) {
        return IntSequenceIterable.create(begin, 1, end - begin);
    }
}

class IntSequenceIterable {

    public static Iterable<Integer> create(final int from, final int step, final int size) {
        return new Iterable<Integer>() {

            public Iterator<Integer> iterator() {
                return IntSequenceIterator.create(from, step, size);
            }
        };
    }

    private IntSequenceIterable() {
    }
}

class IntSequenceIterator {

    public static Iterator<Integer> create(final int start, final int step, final int size) {
        return new ReadOnlyIterator<Integer>() {

            int nextIndex = 0;

            public boolean hasNext() {
                return nextIndex < size;
            }

            public Integer next() {
                return start + step * (nextIndex++);
            }
        };
    }

    private IntSequenceIterator() {
    }
}

abstract class ReadOnlyIterator<T> implements Iterator<T> {

    public final void remove() {
        throw new UnsupportedOperationException();
    }
}

class Pair<T1, T2> implements EqualityTester<Pair<T1, T2>> {

    public static <T1, T2> Pair<T1, T2> create(T1 v1, T2 v2) {
        return new Pair<T1, T2>(v1, v2);
    }

    public final T1 v1;

    public final T2 v2;

    public Pair(T1 v1, T2 v2) {
        this.v1 = v1;
        this.v2 = v2;
    }

    public boolean equals(Object obj) {
        return StrictEqualityTester.areEqual(this, obj, this);
    }

    public boolean areEqual(Pair<T1, T2> o1, Pair<T1, T2> o2) {
        return o1.v1.equals(o2.v1) && o1.v2.equals(o2.v2);
    }

    public int hashCode() {
        return PairHash.hash(v1.hashCode(), v2.hashCode());
    }

    public String toString() {
        return "(" + v1 + "," + v2 + ")";
    }
}

class PairHash {

    public static int hash(int h1, int h2) {
        return ThomasWangHash.hash64bit((((long) h1) << 32) | h2);
    }
}

class ThomasWangHash {

    public static int hash32bit(int key) {
        key = ~key + (key << 15);
        key = key ^ (key >>> 12);
        key = key + (key << 2);
        key = key ^ (key >>> 4);
        key = key * 2057;
        key = key ^ (key >>> 16);
        return key;
    }

    public static int hash64bit(long key) {
        key = (~key) + (key << 18);
        key = key ^ (key >>> 31);
        key = key * 21;
        key = key ^ (key >>> 11);
        key = key + (key << 6);
        key = key ^ (key >>> 22);
        return (int) key;
    }
}

interface EqualityTester<T> {

    boolean areEqual(T o1, T o2);
}

class StrictEqualityTester {

    @SuppressWarnings("unchecked")
    public static <T> boolean areEqual(T me, Object you, EqualityTester<T> tester) {
        if (me == you) return true;
        if (you == null) return false;
        if (you.getClass() != me.getClass()) return false;
        return tester.areEqual(me, (T) you);
    }
}

class ZeroTo {

    public static Iterable<Integer> get(int end) {
        return IntSequenceIterable.create(0, 1, end);
    }
}

class DynamicArray<T> implements MutableArray<T>, EqualityTester<Array<T>> {

    public static <T> DynamicArray<T> create() {
        return new DynamicArray<T>();
    }

    private T[] a;

    private int asize;

    @SuppressWarnings("unchecked")
    public DynamicArray() {
        asize = 0;
        a = (T[]) new Object[1];
    }

    public T get(int index) {
        return a[index];
    }

    public void set(int index, T value) {
        a[index] = value;
    }

    public int size() {
        return asize;
    }

    public void clear() {
        asize = 0;
    }

    @SuppressWarnings("unchecked")
    public void reserve(int size) {
        if (a.length < size) {
            T[] na = (T[]) new Object[size];
            for (int i = 0; i < a.length; i++) na[i] = a[i];
            a = na;
        }
    }

    @SuppressWarnings("unchecked")
    public void addToLast(T value) {
        if (a.length == asize) {
            T[] ta = (T[]) new Object[asize * 2];
            for (int i = 0; i < asize; i++) ta[i] = a[i];
            a = ta;
        }
        a[asize++] = value;
    }

    public T removeLast() {
        T r = a[asize - 1];
        a[--asize] = null;
        return r;
    }

    public boolean equals(Object obj) {
        return StrictEqualityTester.areEqual(this, obj, this);
    }

    public boolean areEqual(Array<T> o1, Array<T> o2) {
        return IterableEqualityTester.areEqual(o1, o2);
    }

    public int hashCode() {
        return OrderFreeIterableHash.hash(this);
    }

    public final boolean isEmpty() {
        return asize == 0;
    }

    public final Iterator<T> iterator() {
        return ArrayIterator.create(this);
    }

    public final String toString() {
        return IterableToString.toString(this);
    }
}

class IterableEqualityTester {

    public static <T> boolean areEqual(Iterable<T> o1, Iterable<T> o2) {
        Iterator<T> iter1 = o1.iterator();
        Iterator<T> iter2 = o2.iterator();
        while (true) {
            if (iter1.hasNext() != iter2.hasNext()) return false;
            if (!iter1.hasNext()) return true;
            T v1 = iter1.next();
            T v2 = iter2.next();
            if (!v1.equals(v2)) return false;
        }
    }
}

class IterableToString {

    public static <T> String toString(Iterable<T> iterable) {
        return IteratorToString.toString(iterable.iterator());
    }

    private IterableToString() {
    }
}

class IteratorToString {

    public static <T> String toString(Iterator<T> iter) {
        StringBuilder sb = new StringBuilder();
        sb.append('(');
        while (iter.hasNext()) {
            T v = iter.next();
            sb.append(v);
            if (iter.hasNext()) sb.append(',');
        }
        sb.append(')');
        return sb.toString();
    }

    private IteratorToString() {
    }
}

class OrderFreeIterableHash {

    public static <T> int hash(Iterable<T> iterable) {
        int r = 0;
        for (T v : iterable) r ^= ThomasWangHash.hash32bit(v.hashCode());
        return r;
    }
}

class ArrayIterator {

    public static <T> Iterator<T> create(final Array<T> a) {
        return new ReadOnlyIterator<T>() {

            int p = 0;

            public boolean hasNext() {
                return p < a.size();
            }

            public T next() {
                return a.get(p++);
            }
        };
    }

    private ArrayIterator() {
    }
}

interface AdjacencyList<V, E> {

    Collection<V> getVertices();

    Iterable<E> getEdges(V from);
}

class AdjacencyListFromGraph {

    public static <V, E extends DirectedEdge<V>> AdjacencyList<V, E> create(final Graph<V, E> g) {
        Map<V, DynamicArray<E>> index = initIndexMap(g.getVertices());
        for (E e : g.getEdges()) index.get(e.from()).addToLast(e);
        return create(g.getVertices(), index);
    }

    public static <V, E extends UndirectedEdge<V>> AdjacencyList<V, E> createFromUndirected(final Graph<V, E> g) {
        Map<V, DynamicArray<E>> index = initIndexMap(g.getVertices());
        for (E e : g.getEdges()) {
            index.get(e.v1()).addToLast(e);
            index.get(e.v2()).addToLast(e);
        }
        return create(g.getVertices(), index);
    }

    private static <V, E> Map<V, DynamicArray<E>> initIndexMap(final Collection<V> vertices) {
        MutableMap<V, DynamicArray<E>> index = GoodMutableMapFactory.getInstance().create();
        for (V v : vertices) index.put(v, new DynamicArray<E>());
        return index;
    }

    private static <V, E> AdjacencyList<V, E> create(final Collection<V> vertices, final Map<V, DynamicArray<E>> index) {
        return new AdjacencyList<V, E>() {

            public Collection<V> getVertices() {
                return vertices;
            }

            public Iterable<E> getEdges(V from) {
                return index.get(from);
            }

            public String toString() {
                String r = "Graph({" + IterableToString.toString(vertices) + "},{";
                for (V v : getVertices()) r += IterableToString.toString(getEdges(v));
                return r + "})";
            }
        };
    }

    private AdjacencyListFromGraph() {
    }
}

class GoodMutableMapFactory {

    public static MutableMapFactory getInstance() {
        return JavaHashMapFactory.getInstance();
    }
}

class JavaHashMapFactory {

    public static MutableMapFactory getInstance() {
        return new MutableMapFactory() {

            public <K, V> MutableMap<K, V> create() {
                return MutableMapUsingJavaMap.wrap(new HashMap<K, V>());
            }
        };
    }

    private JavaHashMapFactory() {
    }
}

interface MutableMap<K, V> extends Map<K, V> {

    void clear();

    void put(K key, V value);

    void remove(K key);
}

interface Map<K, V> extends Collection<KeyValuePair<K, V>> {

    boolean containsKey(K key);

    V get(K key);

    V get(K key, V def);
}

interface KeyValuePair<K, V> {

    K getKey();

    V getValue();
}

interface MutableMapFactory {

    <K, V> MutableMap<K, V> create();
}

class MutableMapUsingJavaMap {

    public static <K, V> MutableMap<K, V> wrap(final java.util.Map<K, V> map) {
        return new MutableMap<K, V>() {

            boolean nullValuePut = false;

            public boolean containsKey(K key) {
                return map.containsKey(key);
            }

            public V get(K key) {
                V r = map.get(key);
                if (r != null) {
                    return r;
                } else {
                    AssertStatus.assertTrue(nullValuePut && map.containsKey(key), "the key in not int the map");
                    return null;
                }
            }

            public V get(K key, V def) {
                if (!containsKey(key)) return def;
                return map.get(key);
            }

            public void put(K key, V value) {
                if (value == null) nullValuePut = true;
                map.put(key, value);
            }

            public void clear() {
                map.clear();
            }

            public boolean isEmpty() {
                return map.isEmpty();
            }

            public Iterator<KeyValuePair<K, V>> iterator() {
                return MapIteratorFromJavaMap.create(map);
            }

            public int size() {
                return map.size();
            }

            public void remove(K key) {
                map.remove(key);
            }

            public String toString() {
                return map.toString();
            }

            public boolean equals(Object obj) {
                return StrictEqualityTester.areEqual(this, obj, new EqualityTester<Map<K, V>>() {

                    public boolean areEqual(Map<K, V> m1, Map<K, V> m2) {
                        return MapEqualityTester.areEqual(m1, m2);
                    }
                });
            }

            public int hashCode() {
                return OrderFreeIterableHash.hash(this);
            }
        };
    }
}

class AssertStatus {

    public static void assertTrue(boolean v) {
        assertTrue(v, "");
    }

    public static void assertNotNull(Object v) {
        assertTrue(v != null, "Object is cannot be a null");
    }

    public static void assertNotNull(Object v, String message) {
        assertTrue(v != null);
    }

    public static void assertTrue(boolean v, String message) {
        if (!v) throw new RuntimeException(message);
    }
}

class MapEqualityTester {

    public static <K, V> boolean areEqual(Map<K, V> m1, Map<K, V> m2) {
        if (m1.size() != m2.size()) return false;
        for (KeyValuePair<K, V> pair : m1) {
            K key1 = pair.getKey();
            V value1 = pair.getValue();
            if (!m2.containsKey(key1)) return false;
            return MapValueEqualityTester.areEqual(value1, m2.get(key1));
        }
        return true;
    }

    private MapEqualityTester() {
    }
}

class MapValueEqualityTester {

    public static <V> boolean areEqual(V valueOrNull1, V valueOrNull2) {
        if (valueOrNull1 == null) {
            if (valueOrNull2 != null) return false;
        } else {
            if (!valueOrNull1.equals(valueOrNull2)) return false;
        }
        return true;
    }

    private MapValueEqualityTester() {
    }
}

class MapIteratorFromJavaMap {

    public static <K, V> Iterator<KeyValuePair<K, V>> create(final java.util.Map<K, V> map) {
        return ConvertedDataIterator.create(map.entrySet().iterator(), new DataConverter<java.util.Map.Entry<K, V>, KeyValuePair<K, V>>() {

            public KeyValuePair<K, V> convert(java.util.Map.Entry<K, V> e) {
                return new EntryWrapper<K, V>(e);
            }
        });
    }

    private static class EntryWrapper<K, V> implements KeyValuePair<K, V>, EqualityTester<EntryWrapper<K, V>> {

        private java.util.Map.Entry<K, V> e;

        private EntryWrapper(java.util.Map.Entry<K, V> e) {
            this.e = e;
        }

        public K getKey() {
            return e.getKey();
        }

        public V getValue() {
            return e.getValue();
        }

        public boolean equals(Object obj) {
            return StrictEqualityTester.areEqual(this, obj, this);
        }

        public boolean areEqual(EntryWrapper<K, V> o1, EntryWrapper<K, V> o2) {
            return KeyValuePairEqualityTester.are(o1, o2);
        }

        public int hashCode() {
            return KeyValuePairHash.hash(this);
        }
    }

    private MapIteratorFromJavaMap() {
    }
}

class KeyValuePairEqualityTester {

    public static <K, V> boolean are(KeyValuePair<K, V> o1, KeyValuePair<K, V> o2) {
        return o1.getKey().equals(o2.getKey()) && MapValueEqualityTester.areEqual(o1.getValue(), o2.getValue());
    }

    private KeyValuePairEqualityTester() {
    }
}

class KeyValuePairHash {

    public static <K, V> int hash(KeyValuePair<K, V> pair) {
        if (pair.getValue() == null) return pair.getKey().hashCode();
        return PairHash.hash(pair.getKey().hashCode(), pair.getValue().hashCode());
    }

    private KeyValuePairHash() {
    }
}

class ConvertedDataIterator {

    public static <T1, T2> Iterator<T2> create(final Iterator<T1> original, final DataConverter<T1, T2> converter) {
        return new ReadOnlyIterator<T2>() {

            public boolean hasNext() {
                return original.hasNext();
            }

            public T2 next() {
                return converter.convert(original.next());
            }
        };
    }

    private ConvertedDataIterator() {
    }
}

interface DataConverter<T1, T2> {

    T2 convert(T1 v);
}

interface DirectedEdge<V> {

    V from();

    V to();
}

class MutableGraph<V, E> implements Graph<V, E> {

    public static <V, E> MutableGraph<V, E> create() {
        return new MutableGraph<V, E>();
    }

    private MutableSet<V> vertices = GoodMutableSetFactory.getInstance().create();

    private DynamicArray<E> edges = DynamicArray.create();

    public void insertVertex(V v) {
        vertices.insert(v);
    }

    public void addEdge(E edge) {
        edges.addToLast(edge);
    }

    public Set<V> getVertices() {
        return vertices;
    }

    public Iterable<E> getEdges() {
        return edges;
    }

    public String toString() {
        return GraphToString.toString(this);
    }
}

class GoodMutableSetFactory {

    public static MutableSetFactory getInstance() {
        return JavaHashSetFactory.getInstance();
    }
}

class JavaHashSetFactory {

    public static MutableSetFactory getInstance() {
        return new MutableSetFactory() {

            public <T> MutableSet<T> create() {
                return new MutableSetUsingJavaSet<T>(new HashSet<T>());
            }
        };
    }
}

interface MutableSet<T> extends Set<T> {

    void clear();

    void insert(T v);

    void remove(T v);
}

interface Set<T> extends Collection<T> {

    boolean contains(T v);
}

interface MutableSetFactory {

    <T> MutableSet<T> create();
}

class MutableSetUsingJavaSet<T> implements MutableSet<T> {

    private final java.util.Set<T> javaset;

    public MutableSetUsingJavaSet(java.util.Set<T> set) {
        this.javaset = set;
    }

    public void clear() {
        javaset.clear();
    }

    public boolean contains(T v) {
        return javaset.contains(v);
    }

    public void insert(T v) {
        javaset.add(v);
    }

    public Iterator<T> iterator() {
        return javaset.iterator();
    }

    public int size() {
        return javaset.size();
    }

    public void remove(T v) {
        javaset.remove(v);
    }

    public boolean isEmpty() {
        return size() == 0;
    }

    public String toString() {
        return IterableToString.toString(this);
    }
}

interface Graph<V, E> {

    Collection<V> getVertices();

    Iterable<E> getEdges();
}

class GraphToString {

    public static <V, E> String toString(Graph<V, E> g) {
        String r = "";
        for (E e : g.getEdges()) {
            if (r.length() != 0) r += ", ";
            r += e.toString();
        }
        return "Graph({" + IterableToString.toString(g.getVertices()) + "},{" + IterableToString.toString(g.getEdges()) + "})";
    }
}

interface UndirectedEdge<V> {

    V v1();

    V v2();
}

class MutableUndirectedGraph<V> implements Graph<V, UndirectedEdge<V>> {

    public static <V> MutableUndirectedGraph<V> create() {
        return new MutableUndirectedGraph<V>();
    }

    private final MutableGraph<V, UndirectedEdge<V>> g = MutableGraph.create();

    public void insertVertex(V v) {
        g.insertVertex(v);
    }

    public void addEdge(V v1, V v2) {
        assertVertexExist(v1);
        assertVertexExist(v2);
        g.addEdge(SimpleUndirectedEdge.create(v1, v2));
    }

    public Collection<V> getVertices() {
        return g.getVertices();
    }

    private void assertVertexExist(V v) {
        AssertStatus.assertTrue(g.getVertices().contains(v), "vertex is not in graph");
    }

    public Iterable<UndirectedEdge<V>> getEdges() {
        return g.getEdges();
    }

    public String toString() {
        return GraphToString.toString(this);
    }
}

class SimpleUndirectedEdge {

    public static <V> UndirectedEdge<V> create(final V v1, final V v2) {
        return new UndirectedEdge<V>() {

            public V v1() {
                return v1;
            }

            public V v2() {
                return v2;
            }

            public String toString() {
                return v1 + "-" + v2;
            }
        };
    }
}

class OppositeInUndirectedEdge {

    public static <V, E extends UndirectedEdge<V>> V get(E e, V v) {
        return v.equals(e.v1()) ? e.v2() : e.v1();
    }

    private OppositeInUndirectedEdge() {
    }
}

class IntegerNumberSystem implements IntegerDivisableNumberSystem<Integer> {

    private static final IntegerNumberSystem INSTANCE = new IntegerNumberSystem();

    public static IntegerNumberSystem getInstance() {
        return INSTANCE;
    }

    private IntegerNumberSystem() {
    }

    public Integer getZero() {
        return Integer.valueOf(0);
    }

    public Integer getByInt(int v) {
        return v;
    }

    public boolean isPositive(Integer v) {
        return v.intValue() > 0;
    }

    public boolean isZero(Integer v) {
        return v.intValue() == 0;
    }

    public boolean isNegative(Integer v) {
        return v.intValue() < 0;
    }

    public int getSign(Integer v) {
        return Integer.signum(v);
    }

    public boolean areEqual(Integer o1, Integer o2) {
        return o1.equals(o2);
    }

    public Integer getOne() {
        return Integer.valueOf(1);
    }

    public boolean isOne(Integer v) {
        return v.intValue() == 1;
    }

    public Integer add(Integer v1, Integer v2) {
        return safeCastFromLong((long) v1 + (long) v2);
    }

    public Integer subtract(Integer minuend, Integer subtrahend) {
        return safeCastFromLong((long) minuend - (long) subtrahend);
    }

    public Integer multiply(Integer v1, Integer v2) {
        return safeCastFromLong((long) v1 * (long) v2);
    }

    public Integer integerDivide(Integer dividend, Integer divisor) {
        return Integer.valueOf(dividend / divisor);
    }

    public Integer integerRemainder(Integer dividend, Integer divisor) {
        return Integer.valueOf(dividend % divisor);
    }

    private Integer safeCastFromLong(long v) {
        if (v != (int) v) throw OverflowException.create();
        return Integer.valueOf((int) v);
    }

    public int compare(Integer o1, Integer o2) {
        return o1.compareTo(o2);
    }
}

interface IntegerDivisableNumberSystem<T> extends MultipliableNumberSystem<T>, Comparator<T> {

    T integerDivide(T dividend, T divisor);

    T integerRemainder(T dividend, T divisor);
}

interface MultipliableNumberSystem<T> extends AddableNumberSystem<T> {

    T multiply(T v1, T v2);

    T getOne();

    boolean isOne(T v);
}

interface AddableNumberSystem<T> extends NumberSystem<T> {

    T add(T v1, T v2);

    T subtract(T minuend, T subtrahend);

    T getZero();

    T getByInt(int v);

    boolean isPositive(T v);

    boolean isZero(T v);

    boolean isNegative(T v);

    int getSign(T v);
}

interface NumberSystem<T> extends EqualityTester<T>, Comparator<T> {
}

class OverflowException {

    public static ArithmeticException create() {
        return new ArithmeticException("Overflow");
    }
}

// Combined by CodeCombine CLI (https://github.com/abbajoa/codecombine)
