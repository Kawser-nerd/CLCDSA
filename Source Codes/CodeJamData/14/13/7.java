import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.util.Iterator;
import java.util.Random;
import java.util.Scanner;

public class C implements Runnable {

    public void run() {
        int simCount = 1000;
        long goodsum = 0;
        long badsum = 0;
        for (int j : ZeroTo.get(simCount)) {
            int n = 1000;
            DynamicArray<Long> good = DynamicArray.create();
            DynamicArray<Long> bad = DynamicArray.create();
            for (int i : ZeroTo.get(n)) {
                good.addToLast((long) i);
                bad.addToLast((long) i);
            }
            Random rand = new Random();
            for (int k : ZeroTo.get(n)) {
                ArraySwapper.swap(good, k, k + rand.nextInt(n - k));
                ArraySwapper.swap(bad, k, rand.nextInt(n));
            }
            goodsum += calcDiffSum(good);
            badsum += calcDiffSum(bad);
        }
        long mid = (goodsum + badsum) / (simCount * 2);
        Scanner in = new Scanner(System.in);
        for (int casei : ZeroTo.get(in.nextInt())) {
            int n = in.nextInt();
            DynamicArray<Long> a = DynamicArray.create();
            for (int i : ZeroTo.get(n)) a.addToLast(in.nextLong());
            System.out.println("Case #" + (casei + 1) + ": " + (calcDiffSum(a) > mid ? "GOOD" : "BAD"));
        }
        in.close();
    }

    private long calcDiffSum(DynamicArray<Long> a) {
        long sum = 0;
        for (int i : ZeroTo.get(a.size())) {
            long diff = Math.abs(a.get(i) - i);
            sum += diff * diff;
        }
        return sum;
    }

    public static void main(String[] args) throws Exception {
        System.setIn(new BufferedInputStream(new FileInputStream("C-small-attempt0.in")));
        new C().run();
    }
}

class ZeroTo {

    public static Iterable<Integer> get(int end) {
        return IntSequenceIterable.create(0, 1, end);
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

interface EqualityTester<T> {

    boolean areEqual(T o1, T o2);
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

class StrictEqualityTester {

    @SuppressWarnings("unchecked")
    public static <T> boolean areEqual(T me, Object you, EqualityTester<T> tester) {
        if (me == you) return true;
        if (you == null) return false;
        if (you.getClass() != me.getClass()) return false;
        return tester.areEqual(me, (T) you);
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

// Combined by CodeCombine CLI (https://github.com/abbajoa/codecombine)
