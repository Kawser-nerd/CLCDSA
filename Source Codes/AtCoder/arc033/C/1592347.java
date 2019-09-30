import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;
import java.util.Random;

public class Main {
    public static void main(String[] args) {
        final FastScanner sc = new FastScanner();
        final long Q = sc.nextLong();
        Treap<Integer> S = new Treap<>();

        for (int i = 0; i < Q; i++) {
            final int T = (int) sc.nextLong();
            final int X = (int) sc.nextLong();

            if (T == 1) {
                S = S.insert(X);
            } else {
                final int Y = S.getAt(X - 1);
                System.out.println(Y);
                S = S.erase(Y);
            }
        }
    }

    private static void yesNo(boolean b) {
        System.out.println(b ? "yes" : "no");
    }

    static class Pair<S, T> {
        S first;
        T second;

        Pair(final S first, final T second) {
            this.first = first;
            this.second = second;
        }
    }

    static class Treap<T extends Comparable<T>> {
        static private Random random = new Random();

        private Treap<T> left;
        private Treap<T> right;
        private T value;

        final private double priority;
        private int size;

        Treap() {
            priority = random.nextDouble();
            size = 0;
        }

        static <T extends Comparable<T>> Treap<T> of(final T v) {
            final Treap<T> t = new Treap<>();
            t.size = 1;
            t.value = v;
            t.left = new Treap<>();
            t.right = new Treap<>();
            return t;
        }

        boolean isEmpty() {
            return value == null;
        }

        Treap<T> update() {
            size = isEmpty() ? 0 : left.size + right.size + 1;
            return this;
        }

        boolean find(final T k) {
            if (isEmpty()) {
                return false;
            } else {
                final int sign = value.compareTo(k);
                if (sign == 0) {
                    return true;
                } else if (sign > 0) {
                    return left.find(k);
                } else {
                    return right.find(k);
                }
            }
        }

        T getAt(final int i) {
            if (i >= size) {
                throw new IndexOutOfBoundsException();
            }

            if (i < left.size) {
                return left.getAt(i);
            } else if (i == left.size) {
                return value;
            } else {
                return right.getAt(i - left.size - 1);
            }
        }

        T min() {
            if (isEmpty()) {
                throw new NoSuchElementException();
            } else if (left.isEmpty()) {
                return value;
            } else {
                return left.min();
            }
        }

        T max() {
            if (isEmpty()) {
                throw new NoSuchElementException();
            } else if (right.isEmpty()) {
                return value;
            } else {
                return right.max();
            }
        }

        Treap<T> merge(final Treap<T> t2) {
            if (this.isEmpty()) {
                return t2;
            } else if (t2.isEmpty()) {
                return this;
            } else if (this.priority >= t2.priority) {
                right = right.merge(t2);
                return this.update();
            } else {
                t2.left = merge(t2.left);
                return t2.update();
            }
        }

        Pair<Treap<T>, Treap<T>> splitAt(final int i) { // [0, i), [i, n)
            if (isEmpty()) {
                return new Pair<>(new Treap<T>(), new Treap<T>());
            } else if (i <= left.size) {
                final Pair<Treap<T>, Treap<T>> pair = left.splitAt(i);
                left = pair.second;
                return new Pair<>(pair.first, this.update());
            } else {
                final Pair<Treap<T>, Treap<T>> pair = right.splitAt(i - left.size - 1);
                right = pair.first;
                return new Pair<>(this.update(), pair.second);
            }
        }

        Pair<Treap<T>, Treap<T>> splitWith(final T v) { // [-inf, v), [v, inf)
            if (isEmpty()) {
                return new Pair<>(new Treap<>(), new Treap<>());
            } else if (v.compareTo(value) <= 0) {
                final Pair<Treap<T>, Treap<T>> pair = left.splitWith(v);
                left = pair.second;
                return new Pair<>(pair.first, this.update());
            } else {
                final Pair<Treap<T>, Treap<T>> pair = right.splitWith(v);
                right = pair.first;
                return new Pair<>(this.update(), pair.second);
            }
        }

        Pair<Treap<T>, Treap<T>> splitWithEq(final T v) { // [-inf, v], (v, inf)
            if (isEmpty()) {
                return new Pair<>(new Treap<>(), new Treap<>());
            } else if (v.compareTo(value) < 0) {
                final Pair<Treap<T>, Treap<T>> pair = left.splitWithEq(v);
                left = pair.second;
                return new Pair<>(pair.first, this.update());
            } else {
                final Pair<Treap<T>, Treap<T>> pair = right.splitWithEq(v);
                right = pair.second;
                return new Pair<>(this.update(), pair.second);
            }
        }


        Treap<T> insert(final T v) {
            final Pair<Treap<T>, Treap<T>> pair = this.splitWith(v);
            return pair.first.merge(Treap.of(v)).merge(pair.second);
        }

        Treap<T> erase(final T v) {
            final Pair<Treap<T>, Treap<T>> pair1 = this.splitWith(v);
            final Pair<Treap<T>, Treap<T>> pair2 = pair1.second.splitWithEq(v);
            return pair1.first.merge(pair2.second);
        }

        public String toString() {
            if (isEmpty()) {
                return "()";
            }
            return String.format("((%d, %d) %s %s)", value, size, left.toString(), right.toString());
        }
    }

    @SuppressWarnings("ALL")
    static class FastScanner {
        private final InputStream in = System.in;
        private final byte[] buffer = new byte[1024];
        private int ptr = 0;
        private int buflen = 0;

        private boolean hasNextByte() {
            if (ptr < buflen) {
                return true;
            } else {
                ptr = 0;
                try {
                    buflen = in.read(buffer);
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (buflen <= 0) {
                    return false;
                }
            }
            return true;
        }

        private int readByte() {
            if (hasNextByte()) return buffer[ptr++];
            else return -1;
        }

        private boolean isPrintableChar(int c) {
            return 33 <= c && c <= 126;
        }

        private void skipUnprintable() {
            while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
        }

        public boolean hasNext() {
            skipUnprintable();
            return hasNextByte();
        }

        public String next() {
            if (!hasNext()) throw new NoSuchElementException();
            StringBuilder sb = new StringBuilder();
            int b = readByte();
            while (isPrintableChar(b)) {
                sb.appendCodePoint(b);
                b = readByte();
            }
            return sb.toString();
        }

        public long nextLong() {
            if (!hasNext()) throw new NoSuchElementException();
            long n = 0;
            boolean minus = false;
            int b = readByte();
            if (b == '-') {
                minus = true;
                b = readByte();
            }
            if (b < '0' || '9' < b) {
                throw new NumberFormatException();
            }
            while (true) {
                if ('0' <= b && b <= '9') {
                    n *= 10;
                    n += b - '0';
                } else if (b == -1 || !isPrintableChar(b)) {
                    return minus ? -n : n;
                } else {
                    throw new NumberFormatException();
                }
                b = readByte();
            }
        }
    }
}