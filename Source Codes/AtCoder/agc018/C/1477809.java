import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.util.Comparator;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int[] need = new int[]{in.nextInt(), in.nextInt(), in.nextInt()};
            int n = need[0] + need[1] + need[2];
            IntPair[] a = new IntPair[n];
            long ans = 0;
            long[] allValues = new long[2 * n];
            for (int i = 0; i < n; ++i) {
                int x = in.nextInt();
                int y = in.nextInt();
                int z = in.nextInt();
                a[i] = new IntPair(x - z, y - z);
                allValues[2 * i] = x - z;
                allValues[2 * i + 1] = y - z;
                ans += z;
            }
            Arrays.sort(a, Comparator.comparingLong(o -> o.first - (long) o.second));
            Arrays.sort(allValues);
            int k = ArraysUtils.makeUnique(allValues);
            allValues = Arrays.copyOf(allValues, k);
            SumOfK left = new SumOfK(allValues), right = new SumOfK(allValues);
            long sumLeft = 0, sumRight = 0;
            for (int i = 0; i < n; ++i) {
                right.add(a[i].first, 1);
                sumRight += a[i].first;
            }
            int cntLeft = 0, cntRight = n;
            long add = Long.MIN_VALUE;
            for (int i = 0; i <= n; ++i) {
                if (cntLeft >= need[1] && cntRight >= need[0]) {
                    add = Math.max(add, sumLeft + sumRight -
                            left.sumOfK(cntLeft - need[1]) - right.sumOfK(cntRight - need[0]));
                }
                if (i < n) {
                    left.add(a[i].second, 1);
                    cntLeft++;
                    sumLeft += a[i].second;
                    right.add(a[i].first, -1);
                    cntRight--;
                    sumRight -= a[i].first;
                }
            }
            ans += add;
            out.println(ans);
        }

        class FenwickTree {
            long[] tree;

            FenwickTree(int n) {
                tree = new long[n + 1];
            }

            void add(int pos, long value) {
                for (++pos; pos < tree.length; pos += pos & -pos) {
                    tree[pos] += value;
                }
            }

            long query(int pos) {
                long res = 0;
                for (++pos; pos > 0; pos -= pos & -pos) {
                    res += tree[pos];
                }
                return res;
            }

            int search(long k) {
                int step = 1;
                while (step < tree.length) {
                    step *= 2;
                }
                int res = 0;
                for (; step > 0; step /= 2) {
                    if (res + step < tree.length && tree[res + step] <= k) {
                        res += step;
                        k -= tree[res];
                    }
                }
                return res - 1;
            }

        }

        class SumOfK {
            FenwickTree sum;
            FenwickTree freq;
            long[] values;

            SumOfK(long[] values) {
                this.values = values.clone();
                sum = new FenwickTree(values.length);
                freq = new FenwickTree(values.length);
            }

            void add(long value, int add) {
                int pos = ArraysUtils.lowerBound(values, value);
                sum.add(pos, value * add);
                freq.add(pos, add);
            }

            long sumOfK(int k) {
                int pos = freq.search(k);
                int cnt = (int) freq.query(pos);
                long res = sum.query(pos);
                if (cnt < k) {
                    res += values[pos + 1] * (k - cnt);
                }
                return res;
            }

        }

    }

    static class ArraysUtils {
        public static int makeUnique(long[] a) {
            return makeUnique(a, 0, a.length);
        }

        public static int makeUnique(long[] a, int left, int right) {
            int k = left + 1;
            for (int i = left + 1; i < right; ++i) {
                if (a[i] != a[k - 1]) {
                    a[k++] = a[i];
                }
            }
            return k;
        }

        public static int lowerBound(long[] a, long value) {
            return lowerBound(a, 0, a.length, value);
        }

        public static int lowerBound(long[] a, int left, int right, long value) {
            int step = 1;
            while (step < right - left) {
                step *= 2;
            }
            int res = left - 1;
            for (; step > 0; step /= 2) {
                if (res + step < right && a[res + step] < value) {
                    res += step;
                }
            }
            return res + 1;
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1)
                throw new UnknownError();
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new UnknownError();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public String next() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuffer res = new StringBuffer();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));

            return res.toString();
        }

        private boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }

    static class IntPair implements Comparable<IntPair> {
        public int first;
        public int second;

        public IntPair() {
        }

        public IntPair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        public int compareTo(IntPair other) {
            if (first != other.first) return first < other.first ? -1 : 1;
            if (second != other.second) return second < other.second ? -1 : 1;
            return 0;
        }

        public boolean equals(Object other) {
            if (!(other instanceof IntPair)) return false;
            return compareTo((IntPair) other) == 0;
        }

        public int hashCode() {
            return first * 31 + second;
        }

    }
}