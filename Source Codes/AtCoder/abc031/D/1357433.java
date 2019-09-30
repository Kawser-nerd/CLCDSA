import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    private static boolean debug = false;
    private static boolean elapsed = false;

    private static PrintWriter _out = new PrintWriter(System.out);
    private static PrintWriter _err = new PrintWriter(System.err);

    private int K;

    private Map<Character, String> confirmedMap = new HashMap<>();
    private List<Pair<String>> vwList = new ArrayList<>();

    private void solve(Scanner sc) {
        K = sc.nextInt();
        int N = sc.nextInt();
        long[] v = new long[N];
        String[] w = new String[N];
        for (int i = 0; i < N; ++i) {
            v[i] = sc.nextInt();
            w[i] = sc.next();

            String s = String.valueOf(v[i]);
            if (s.length() == 1) {
                confirmedMap.put(s.charAt(0), w[i]);
            } else {
                vwList.add(new Pair<>(s, w[i]));
            }
        }
        Map<Character, Integer> chIdxMap = new HashMap<>();
        for (int i = 0; i < K; ++i) {
            chIdxMap.put(String.valueOf(i + 1).charAt(0), i);
        }
        int[] len = new int[K];
        Arrays.fill(len, 1);
        Map<Character, String> map = new TreeMap<>();
        for (int i = 0; i < (int)Math.pow(3, K); ++i) {
//_err.println("i=" + i + ", len=" + Arrays.toString(len));
            map = new TreeMap<>();
            map.putAll(confirmedMap);

            boolean flag = true;
            for (Pair<String> pair : vwList) {
                int index = 0;
                for (int j = 0; j < pair.a.length(); ++j) {
                    char ch = pair.a.charAt(j);
                    int idx = chIdxMap.get(ch);
                    if (index + len[idx] <= pair.b.length()) {
                        if (map.containsKey(ch)) {
                            String s = pair.b.substring(index, index + len[idx]);
                            index += len[idx];
                            if (!map.get(ch).equals(s)) {
//_err.println("i=" + i + ", map=" + map + ", s=" + s + ", len=" + Arrays.toString(len));
                                flag = false;
                                break;
                            }
                        } else {
                            map.put(ch, pair.b.substring(index, index + len[idx]));
                            index += len[idx];
                        }
                    } else {
//_err.println("i=" + i + ", index=" + index + ", ch=" + ch + ", idx=" + idx + ", pair=" + pair + ", len=" + Arrays.toString(len));
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    StringBuilder sb = new StringBuilder();
                    for (char ch : pair.a.toCharArray()) {
                        sb.append(map.get(ch));
                    }
                    if (!pair.b.equals(sb.toString())) {
//_err.println("i=" + i + ", pair=" + pair + ", sb=" + sb + ", map=" + map + ", len=" + Arrays.toString(len));
                        flag = false;
                        break;
                    }
                }
            }

            if (flag) {
//_err.println(ans);
//_err.println(map);
                for (String s : map.values()) {
                    _out.println(s);
                }
                break;
            }

            // ?????
            ++len[K - 1];
            if (len[K - 1] > 3) {
                int idx = K - 1;
                while (len[idx] > 3) {
                    if (idx - 1 < 0) {
                        break;
                    }
                    len[idx] = 1;
                    ++len[idx - 1];
                    --idx;
                }
            }
        }
    }
    private static BigInteger C(long n, long r) {
        BigInteger res = BigInteger.ONE;
        for (long i = n; i > n - r; --i) {
            res = res.multiply(BigInteger.valueOf(i));
        }
        for (long i = r; i > 1; --i) {
            res = res.divide(BigInteger.valueOf(i));
        }
        return res;
    }
    private static BigInteger P(long n, long r) {
        BigInteger res = BigInteger.ONE;
        for (long i = n; i > n - r; --i) {
            res = res.multiply(BigInteger.valueOf(i));
        }
        return res;
    }
    private static class Pair<T extends Comparable<T>> implements Comparable<Pair<T>> {
        T a;
        T b;
        public Pair(T a, T b) {
            this.a = a;
            this.b = b;
        }
        @Override
        public int compareTo(Pair<T> that) {
            if (this == that) {
                return 0;
            }
            if (this.a != null && that.a == null) {
                return 1;
            } else if (this.a == null && that.a != null) {
                return -1;
            }
            if (this.b != null && that.b == null) {
                return 1;
            } else if (this.b == null && that.b != null) {
                return -1;
            }
            int r = 0;
            if (this.a != null && that.a != null) {
                r = this.a.compareTo(that.a);
                if (r != 0) {
                    return r;
                }
            }
            if (this.b != null && that.b != null) {
                r = this.b.compareTo(that.b);
                if (r != 0) {
                    return r;
                }
            }
            return r;
        }
        @Override
        public boolean equals(Object o) {
            if (o instanceof Pair) {
                Pair that = (Pair)o;
                boolean res = (this.a == null && this.a == that.a || this.a != null && this.a.equals(that.a));
                res = res && (this.b == null && this.b == that.b || this.b != null && this.b.equals(that.b));
                return res;
            }
            return false;
        }
        @Override
        public int hashCode() {
            int hashCode = 17;
            hashCode = hashCode * 31 + (a != null ? a.hashCode() : 0);
            hashCode = hashCode * 31 + (b != null ? b.hashCode() : 0);
            return hashCode;
        }
        @Override
        public String toString() {
            return "[" + a + ", " + b + "]";
        }
    }
    /*
     * 10^10 > Integer.MAX_VALUE = 2147483647 > 10^9
     * 10^19 > Long.MAX_VALUE = 9223372036854775807L > 10^18
     */
    public static void main(String[] args) {
        long S = System.currentTimeMillis();

        Scanner sc = new Scanner(System.in);
        new Main().solve(sc);
        _out.flush();

        long G = System.currentTimeMillis();
        if (elapsed) {
            _err.println((G - S) + "ms");
        }
        _err.flush();
    }
}