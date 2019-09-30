import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.*;

public class D {

    public static final int MODULO = 1000000007;

    int strings, servers;
    String[] s;
    int[] assgn;
    int[] prev;
    int[][] common;
    int maxVal;
    int count;

    private void solve() throws Exception {
        strings = nextInt();
        servers = nextInt();
        /*strings = 1000;
        servers = 100;
        Random rand = new Random();*/
        s = new String[strings];
        for (int i = 0; i < strings; ++i) {
            s[i] = nextToken();
            /*StringBuilder sb = new StringBuilder();
            for (int j = 0; j < 100; ++j) {
                sb.append((char) ('A' + rand.nextInt(2)));
            }
            s[i] = sb.toString();*/
        }
        Arrays.sort(s);
        common = new int[strings][strings];
        for (int i = 0; i < strings; ++i) {
            for (int j = 0; j < strings; ++j) {
                int cur = 0;
                while (cur < s[i].length() && cur < s[j].length() && s[i].charAt(cur) == s[j].charAt(cur)) {
                    ++cur;
                }
                common[i][j] = cur;
            }
        }
        maxVal = 0;
        count = 0;
        prev = new int[servers];
        /*assgn = new int[strings];
        rec(0);*/
        int[] tmp = new int[strings];
        int ind = 0;
        for (int i = 0; i < strings; ++i) {
            tmp[i] = ind;
            ind = (ind + 1) % servers;
        }
        maxVal = calc(tmp);
        for (int i = 0; i < strings; ++i) {
            s[i] += "+";
        }
        count = (int) (calcCount(0, strings - 1, 0, servers) % MODULO);
        out.println(maxVal + " " + count);
    }

    private long calcCount(int from, int to, int letter, int servers) {
        int strings = to - from + 1;
        if (strings <= servers) {
            return fact[servers] * invFact[servers - strings] % MODULO;
        }
        ArrayList<Integer> groupStart = new ArrayList<>(), groupEnd = new ArrayList<>();
        int start = from;
        /*if (s[start].length() <= letter) {
            groupStart.add(start);
            groupEnd.add(start);
            ++start;
        }*/
        for (int i = start + 1; i <= to; ++i) {
            /*if (s[i].length() <= letter) {
                groupStart.add(start);
                groupEnd.add(i - 1);
                groupStart.add(i);
                groupEnd.add(i);
                start = i + 1;
                i += 1;
                continue;
            }*/
            if (s[i].charAt(letter) != s[i - 1].charAt(letter)) {
                groupStart.add(start);
                groupEnd.add(i - 1);
                start = i;
            }
        }
        groupStart.add(start);
        groupEnd.add(to);
        int maxLen = 0;
        for (int i = 0; i < groupStart.size(); ++i) {
            maxLen = Math.max(maxLen, groupEnd.get(i) - groupStart.get(i) + 1);
        }
        if (maxLen >= servers) {
            long ans = 1;
            for (int i = 0; i < groupStart.size(); ++i) {
                ans = ans * calcCount(groupStart.get(i), groupEnd.get(i), letter + 1, servers) % MODULO;
            }
            return ans;
        }
        int add = 1;
        long ans = 0;
        for (int len = servers; len >= maxLen; --len) {
            long curAns = 1;
            for (int i = 0; i < groupStart.size(); ++i) {
                curAns = curAns * calcCount(groupStart.get(i), groupEnd.get(i), letter + 1, len) % MODULO;
            }
            ans += (add * curAns * c[servers][len]) % MODULO;
            ans = ((ans % MODULO) + MODULO) % MODULO;
            add = -add;
        }
        return ans;
    }

    int calc(int[] assgn) {
        Arrays.fill(prev, -1);
        int cur = 0;
        for (int i = 0; i < strings; ++i) {
            cur += s[i].length() + 1;
            if (prev[assgn[i]] >= 0) {
                cur -= common[prev[assgn[i]]][i] + 1;
            }
            prev[assgn[i]] = i;
        }
        return cur;
    }

    private void rec(int at) {
        if (at == strings) {
            int cur = calc(assgn);
            if (cur > maxVal) {
                maxVal = cur;
                count = 0;
            }
            if (cur == maxVal) {
                ++count;
            }
            return;
        }
        for (int i = 0; i < servers; ++i) {
            assgn[at] = i;
            rec(at + 1);
        }
    }

    public void run() {
        try {
            preCalc();
            int tc = nextInt();
            for (int it = 1; it <= tc; ++it) {
                System.err.println(it);
                out.print("Case #" + it + ": ");
                solve();
            }
        } catch (Exception e) {
            NOO(e);
        } finally {
            out.close();
        }
    }

    long[] fact, invFact;
    long[][] c;

    private void preCalc() {
        BigInteger MOD = BigInteger.valueOf(MODULO);
        fact = new long[2000];
        invFact = new long[2000];
        fact[0] = invFact[0] = 1;
        for (int i = 1; i < fact.length; ++i) {
            fact[i] = fact[i - 1] * i % MODULO;
            invFact[i] = BigInteger.valueOf(fact[i]).modInverse(MOD).longValue();
        }
        c = new long[2000][2000];
        for (int i = 0; i < c.length; ++i) {
            c[i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MODULO;
            }
        }
    }

    PrintWriter out;
    BufferedReader in;
    StringTokenizer St;

    void NOO(Exception e) {
        e.printStackTrace();
        System.exit(42);
    }

    int nextInt() {
        return Integer.parseInt(nextToken());
    }

    long nextLong() {
        return Long.parseLong(nextToken());
    }

    double nextDouble() {
        return Double.parseDouble(nextToken());
    }

    String nextToken() {
        while (!St.hasMoreTokens()) {
            try {
                String line = in.readLine();
                if (line == null)
                    return null;
                St = new StringTokenizer(line);
            } catch (Exception e) {
                NOO(e);
            }
        }
        return St.nextToken();
    }

    private D(String name) {
        try {
            in = new BufferedReader(new FileReader("input.txt"));
            St = new StringTokenizer("");
            out = new PrintWriter(new FileWriter("output.txt"));
        } catch (Exception e) {
            NOO(e);
        }
    }

    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        new D("a").run();
    }
}
