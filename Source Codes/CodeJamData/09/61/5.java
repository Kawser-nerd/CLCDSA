import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.math.BigInteger;
import java.util.Locale;

// 1.6
public class A
{
    static final int THREADS = 1;
    static final String NAME = "a-large";
    StringBuilder out;
    int N, T;
    int[][] dms;
    int maxD;

    public void readData() throws Exception
    {
        N = Integer.parseInt(readWord());
        T = Integer.parseInt(readWord());
        dms = new int[T][];
        maxD = 0;
        for (int i = 0; i < T; i++)
        {
            int size = Integer.parseInt(readWord());
            dms[i] = new int[size];
            dms[i][0] = 0;
            for (int j = 1; j < size; j++)
            {
                dms[i][j] = Integer.parseInt(readWord()) - 1;
                maxD = Math.max(maxD, dms[i][j]);
            }
        }
    }

    BigInteger sum;
    BigInteger[][] tmp;
    BigInteger[] ndegs;

    public BigInteger calc1(int[] ps, int i, int prev)
    {
        if (i == ps.length)
        {
            return BigInteger.valueOf(prev * prev);
        }
        if (tmp[i][prev] != null)
        {
            return tmp[i][prev];
        }
        BigInteger res = BigInteger.ZERO;
        res = res.add(BigInteger.valueOf(prev * prev).multiply(
            ndegs[ps.length - i]));
        int sum = 0;
        for (int j = i; j < ps.length; j++)
        {
            sum += ps[j];
        }
        res = res.add(BigInteger.valueOf(2 * prev * (long)sum).multiply(
            ndegs[ps.length - i - 1]));
        if (tmp[i][0] != null)
        {
            res = res.add(tmp[i][0]);
            tmp[i][prev] = res;
            return res;
        }
        // prev = 0;
        BigInteger t2 = calc1(ps, i + 1, 0);
        res = res.add(t2.multiply(BigInteger.valueOf(N - ps[i])));
        BigInteger t1 = calc1(ps, i + 1, 1);
        res = res.add(t1.multiply(BigInteger.valueOf(ps[i])));
        tmp[i][prev] = res;
        return res;
    }
    public BigInteger calc(int[] ps)
    {
        tmp = new BigInteger[ps.length][ps.length];
        return calc1(ps, 0, 0);
    }
    public void solve()
    {
        sum = BigInteger.ZERO;
        int[] ps = new int[T];
        ndegs = new BigInteger[T + 1];
        ndegs[0] = BigInteger.ONE;
        for (int i = 1; i <= T; i++)
        {
            ndegs[i] = ndegs[i - 1].multiply(BigInteger.valueOf(N));
        }
        for (int i = 0; i < maxD && i < N; i++)
        {
            for (int j = 0; j < T; j++)
            {
                while (ps[j] < dms[j].length && dms[j][ps[j]] <= i)
                {
                    ps[j]++;
                }
            }
            sum = sum.add(calc(ps));
        }
        if (N > maxD)
        {
            for (int j = 0; j < T; j++)
            {
                ps[j] = dms[j].length;
            }
            sum = sum.add(calc(ps).multiply(BigInteger.valueOf(N - maxD)));
        }
        BigInteger q = BigInteger.ONE;
        for (int i = 0; i < T; i++)
        {
            q = q.multiply(BigInteger.valueOf(N));
        }
        BigInteger gcd = sum.gcd(q);
        q = q.divide(gcd);
        sum = sum.divide(gcd);
        BigInteger[] ans = sum.divideAndRemainder(q);
        out.append(ans[0] + "+" + ans[1] + "/" + q + "\n");
    }
    static String readWord() throws Exception
    {
        StringBuilder b = new StringBuilder();
        int c;
        while (true)
        {
            c = Common.stdin.read();
            if (c < 0)
            {
                return "";
            }
            if (c > 32)
            {
                break;
            }
        }
        while (true)
        {
            b.append((char)c);
            c = Common.stdin.read();
            if (c <= 32)
            {
                break;
            }
        }
        return b.toString();
    }
    static String readLine() throws Exception
    {
        return Common.stdin.readLine();
    }

    static class Common
    {
        static BufferedReader stdin;
        static BufferedWriter stdout;
        static int tests;
        static int test;
        static String[] answers;

        public static void startThreads()
        {
            try
            {
                stdin = new BufferedReader(new FileReader(NAME + ".in"));
                stdout = new BufferedWriter(new FileWriter(NAME + ".out"));
                tests = Integer.parseInt(readLine().trim());
                answers = new String[tests];
                test = 0;
                Thread[] threads = new Thread[THREADS];
                for (int i = 0; i < threads.length; i++)
                {
                    final A inst = new A();
                    threads[i] = new Thread(new Runnable()
                        {
                        public void run()
                                                {
                            while (true)
                                                    {
                                inst.out = new StringBuilder();
                                int ltest = 0;
                                synchronized (stdin)
                                                        {
                                    ltest = test;
                                    test++;
                                    if (ltest >= tests)
                                                            {
                                        return;
                                    }
                                    try
                                    {
                                        inst.readData();
                                    } catch (Throwable e)
                                                            {
                                        e.printStackTrace();
                                    }
                                }
                                long t = System.currentTimeMillis();
                                try
                                {
                                    inst.solve();
                                } catch (Throwable e)
                                                        {
                                    e.printStackTrace();
                                }
                                synchronized (answers)
                                                        {
                                    System.err.println(ltest + " "
                                        + (System.currentTimeMillis() - t));
                                    answers[ltest] = inst.out.toString();
                                }
                            }
                        }
                    });
                    threads[i].start();
                }
                for (int i = 0; i < threads.length; i++)
                {
                    threads[i].join();
                }
                for (int test = 1; test <= tests; test++)
                {
                    stdout.write("Case #" + test + ": " + answers[test - 1]);
                }
                stdout.close();
                stdin.close();
            } catch (Exception e)
            {
                e.printStackTrace();
            }
        }
    }

    public static void main(String[] args)
    {
        try
        {
            Locale.setDefault(Locale.US);
            Common.startThreads();
        } catch (Throwable e)
        {
            e.printStackTrace();
        }
    }
}
