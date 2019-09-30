import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Scanner;

public class A implements Runnable {

    private static final int M = 1000000000;

    public void run() {
        Scanner in = new Scanner(System.in);
        for (int casei : ZeroTo.get(in.nextInt())) {
            System.out.print("Case #" + (casei + 1) + ": ");
            int n = in.nextInt();
            int m = in.nextInt();
            String[] outlet = new String[n];
            String[] devices = new String[n];
            for (int j : ZeroTo.get(n)) outlet[j] = in.next();
            for (int j : ZeroTo.get(n)) devices[j] = in.next();
            int min = M;
            for (String firstDevice : devices) {
                int toggleCount = 0;
                boolean[] toggle = new boolean[m];
                for (int j : ZeroTo.get(m)) if (firstDevice.charAt(j) != outlet[0].charAt(j)) {
                    toggle[j] = true;
                    toggleCount++;
                }
                MutableSet<String> newOutlets = GoodMutableSetFactory.getInstance().create();
                for (int i : ZeroTo.get(n)) {
                    char[] newOutlet = new char[m];
                    for (int j : ZeroTo.get(m)) {
                        char orignal = outlet[i].charAt(j);
                        if (toggle[j]) newOutlet[j] = (orignal == '1' ? '0' : '1'); else newOutlet[j] = orignal;
                    }
                    newOutlets.insert(new String(newOutlet));
                }
                boolean ok = true;
                for (String d : devices) if (!newOutlets.contains(d)) ok = false;
                if (ok) min = Math.min(min, toggleCount);
            }
            if (min != M) System.out.println(min); else System.out.println("NOT POSSIBLE");
        }
        in.close();
    }

    public static void main(String[] args) throws Exception {
        System.setIn(new BufferedInputStream(new FileInputStream("A-small-attempt0.in")));
        new A().run();
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

interface Collection<T> extends Iterable<T> {

    int size();

    boolean isEmpty();
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

// Combined by CodeCombine CLI (https://github.com/abbajoa/codecombine)
