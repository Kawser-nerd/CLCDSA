import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.Collection;
import java.util.Set;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.stream.Collectors;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.stream.Stream;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author prakharjain
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        agc028_c solver = new agc028_c();
        solver.solve(1, in, out);
        out.close();
    }

    static class agc028_c {
        long inf = (long) 1e15;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();

            int[][] a = new int[n][2];

            List<num> nums = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                a[i][0] = in.nextInt();
                a[i][1] = in.nextInt();

                nums.add(new num(a[i][0], i, 0));
                nums.add(new num(a[i][1], i, 1));
            }

            long sum = 0;
            nums.sort((n1, n2) -> (int) Math.signum(n1.num - n2.num));

            Set<Integer> ind = new HashSet<>();

            for (int i = 0; i < n; i++) {
                ind.add(nums.get(i).i);
                sum += nums.get(i).num;
            }

            if (ind.size() < n) {
                out.println(sum);
                return;
            }

            ind.clear();
            for (int i = 0; i < n; i++) {
                ind.add(nums.get(i).p);
            }

            if (ind.size() == 1) {
                out.println(sum);
                return;
            }

            List<Integer> aInd = new ArrayList<>();
            List<Integer> bInd = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                if (nums.get(i).p == 0) {
                    aInd.add(i);
                } else {
                    bInd.add(i);
                }
            }

            Set<Integer> aIndM = new HashSet<>();
            Set<Integer> bIndM = new HashSet<>();

            aIndM.addAll(min(aInd, nums));
            aIndM.addAll(minS(aInd, nums, a, 1));
            aIndM.addAll(max(aInd, nums));
            aIndM.addAll(maxS(aInd, nums, a, 1));

            bIndM.addAll(min(bInd, nums));
            bIndM.addAll(minS(bInd, nums, a, 0));
            bIndM.addAll(max(bInd, nums));
            bIndM.addAll(maxS(bInd, nums, a, 0));

            long ans = inf;
            for (Integer i : bIndM) {
                for (Integer j : bIndM) {
                    if (i == j && bInd.size() > 1)
                        continue;
                    for (Integer x : aIndM) {
                        for (Integer y : aIndM) {
                            if (x == y && aInd.size() > 1)
                                continue;

                            long csum = sum;

                            csum -= Math.max(nums.get(y).num, nums.get(i).num);
                            csum += Math.min(a[nums.get(j).i][0], a[nums.get(x).i][1]);

                            ans = Math.min(ans, csum);
                        }
                    }
                }
            }

            out.println(ans);
        }

        List<Integer> min(List<Integer> l, List<num> nums) {
            List<num> numList = new ArrayList<>();
            for (int i = 0; i < l.size(); i++) {
                int ind = l.get(i);
                numList.add(new num(nums.get(ind).num, ind, -1));
            }

            numList.sort((n1, n2) -> (int) Math.signum(n1.num - n2.num));

            numList = numList.subList(0, Math.min(10, numList.size()));

            return numList.stream().map(num -> num.i).collect(Collectors.toList());
        }

        List<Integer> minS(List<Integer> l, List<num> nums, int[][] a, int p) {
            List<num> numList = new ArrayList<>();
            for (int i = 0; i < l.size(); i++) {
                int ind = l.get(i);
                numList.add(new num(a[nums.get(ind).i][p], ind, -1));
            }

            numList.sort((n1, n2) -> (int) Math.signum(n1.num - n2.num));

            numList = numList.subList(0, Math.min(10, numList.size()));

            return numList.stream().map(num -> num.i).collect(Collectors.toList());
        }

        List<Integer> max(List<Integer> l, List<num> nums) {
            List<num> numList = new ArrayList<>();
            for (int i = 0; i < l.size(); i++) {
                int ind = l.get(i);
                numList.add(new num(nums.get(ind).num, ind, -1));
            }

            numList.sort((n1, n2) -> (int) Math.signum(n2.num - n1.num));

            numList = numList.subList(0, Math.min(10, numList.size()));

            return numList.stream().map(num -> num.i).collect(Collectors.toList());
        }

        List<Integer> maxS(List<Integer> l, List<num> nums, int[][] a, int p) {
            List<num> numList = new ArrayList<>();
            for (int i = 0; i < l.size(); i++) {
                int ind = l.get(i);
                numList.add(new num(a[nums.get(ind).i][p], ind, -1));
            }

            numList.sort((n1, n2) -> (int) Math.signum(n2.num - n1.num));

            numList = numList.subList(0, Math.min(10, numList.size()));

            return numList.stream().map(num -> num.i).collect(Collectors.toList());
        }

        class num {
            long num;
            int i;
            int p;

            public num(long num, int i, int p) {
                this.num = num;
                this.i = i;
                this.p = p;
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

        public void close() {
            writer.close();
        }

        public void println(long i) {
            writer.println(i);
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

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
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

        public int nextInt() {
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

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }
}