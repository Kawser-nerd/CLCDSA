import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;

import static java.lang.Math.*;

public class Main {
    BufferedReader rd;

    Main() throws IOException {
        rd = new BufferedReader(new InputStreamReader(System.in));
        compute();
    }

    private void compute() throws IOException {
        int k = intarr()[1];
        int[] a = intarr();
        int res = solve(k,a);
        out(res);
    }

    private int solve(int k, int[] a) {
        int n = a.length;
        int one = 0;
        for(int i=1;i<n;i++) {
            if(a[i] == 1) {
                one = i;
                break;
            }
        }

        TrySet trySet = new TrySet(max(0,one-k+1), one);
        if(k < 4) {
            trySet.fillToTheBrim();
        } else {
            for(int i=-3;i<=3;i++) {
                trySet.add(one + i);
                trySet.add(one - k + i);
            }

            int k1 = k-1;
            int z = one;
            int left = z/k1;
            if(z%k1 == 0) {
                left++;
            }
            int pre = z - left * k;
            for(int i=-3;i<=3;i++) {
                trySet.add(i - pre + one);
            }

            int r = n - (z + k);
            int right = r/k1;
            if(r%k1 == 0) {
                right++;
            }
            int post = r - right*k;
            for(int i=-3;i<=3;i++) {
                trySet.add(i - post + one);
            }
        }

        int mi = Integer.MAX_VALUE;
        for(Integer z: trySet.toTry) {
            mi = min(ops(z, k, n), mi);
        }
        return mi;
    }

    private int ops(int z, int k, int n) {
        int left = rem(z,k);
        int right = rem(n - z - k,k);
        return left + 1 + right;
    }

    private int rem(int size, int k) {
        if(size <= 0) {
            return 0;
        }
        int k1 = k-1;
        int v = size%k1;
        int p = size/k1;
        if(v != 0) {
            p++;
        }
        return p;
    }

    private class TrySet {
        private final int lower, upper;
        private final Set<Integer> toTry = new HashSet<>();

        public TrySet(int lower, int upper) {
            this.lower = lower;
            this.upper = upper;
        }

        public void add(int x) {
            if(x >= lower && x <= upper) {
                toTry.add(x);
            }
        }

        public void fillToTheBrim() {
            for(int i=lower;i<=upper;i++) {
                toTry.add(i);
            }
        }
    }

    private int[] intarr() throws IOException {
        return intarr(rd.readLine());
    }

    private int[] intarr(String s) {
        String[] q = split(s);
        int n = q.length;
        int[] a = new int[n];
        for(int i=0;i<n;i++) {
            a[i] = Integer.parseInt(q[i]);
        }
        return a;
    }

    private String[] split(String s) {
        if(s == null) {
            return new String[0];
        }
        int n = s.length();
        int start = -1;
        int end = 0;
        int sp = 0;
        boolean lastWhitespace = true;
        for(int i=0;i<n;i++) {
            char c = s.charAt(i);
            if(isWhitespace(c)) {
                lastWhitespace = true;
            } else {
                if(lastWhitespace) {
                    sp++;
                }
                if(start == -1) {
                    start = i;
                }
                end = i;
                lastWhitespace = false;
            }
        }
        if(start == -1) {
            return new String[0];
        }
        String[] res = new String[sp];
        int last = start;
        int x = 0;
        lastWhitespace = true;
        for(int i=start;i<=end;i++) {
            char c = s.charAt(i);
            boolean w = isWhitespace(c);
            if(w && !lastWhitespace) {
                res[x++] = s.substring(last,i);
            } else if(!w && lastWhitespace) {
                last = i;
            }
            lastWhitespace = w;
        }
        res[x] = s.substring(last,end+1);
        return res;
    }

    private boolean isWhitespace(char c) {
        return c==' ' || c=='\t';
    }

    private static void out(Object x) {
        System.out.println(x);
    }

    public static void main(String[] args) throws IOException {
        new Main();
    }
}