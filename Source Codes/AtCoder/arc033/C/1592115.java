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
                S = S.delete(Y);
            }
        }
    }

    private static void yesNo(boolean b) {
        System.out.println(b ? "yes" : "no");
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

        Treap<T> copyFrom(final Treap<T> other) {
            value = other.value;
            left = other.left;
            right = other.right;
            size = other.size;
            return this;
        }

        Treap<T> clear() {
            value = null;
            left = right = null;
            return this;
        }

        boolean isEmpty() {
            return value == null;
        }

        Treap<T> update() {
            size = isEmpty() ? 0 : left.size + right.size + 1;
            return this;
        }

        Treap<T> rotateRight() {
            final Treap<T> newRoot = left;
            left = left.right;
            newRoot.right = this;
            update();
            newRoot.update();
            return newRoot;
        }

        Treap<T> rotateLeft() {
            final Treap<T> newRoot = right;
            right = right.left;
            newRoot.left = this;
            update();
            newRoot.update();
            return newRoot;
        }

        Treap<T> insert(final T k) {
            if (isEmpty()) {
                value = k;
                left = new Treap<>();
                right = new Treap<>();
            } else if (value.compareTo(k) >= 0) {
                left = left.insert(k);
                if (left.priority > priority) {
                    update();
                    return rotateRight();
                }
            } else {
                right = right.insert(k);
                if (right.priority > priority) {
                    update();
                    return rotateLeft();
                }
            }
            update();
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

        Treap<T> delete(final T k) {
            if (isEmpty()) {
                throw new NoSuchElementException();
            }

            final int sign = value.compareTo(k);

            if (sign == 0) {
                if (!right.isEmpty() && !left.isEmpty()) {
                    if (left.priority <= right.priority) {
                        final Treap<T> temp = rotateRight();
                        temp.right = temp.right.delete(k);
                        temp.update();
                        return temp;
                    } else {
                        final Treap<T> temp = rotateLeft();
                        temp.left = temp.left.delete(k);
                        temp.update();
                        return temp;
                    }
                } else if (!left.isEmpty()) {
                    return left;
                } else if (!right.isEmpty()) {
                    return right;
                } else {
                    value = null;
                    update();
                }
            } else if (sign > 0) {
                left = left.delete(k);
            } else {
                right = right.delete(k);
            }
            this.update();
            return this;
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