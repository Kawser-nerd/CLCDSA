import static java.lang.Math.max;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.text.DecimalFormat;
import java.util.Arrays;
import java.util.Locale;

// 1.6
public class A
{
    static final int THREADS = 1;
    static final String NAME = "a-small-attempt0";
    StringBuilder out;
    int D;
    int K;
    int[] S;

    int[] primes;
    boolean[] primeFlags;
    final static int[] deg10 = new int[] { 1, 10, 100, 1000, 10000, 100000, 1000000 };

    public void init()
    {
        if (primes != null)
        {
            return;
        }
        primeFlags = new boolean[1000000];
        Arrays.fill(primeFlags, true);
        primeFlags[0] = false;
        primeFlags[1] = false;
        for (int i = 2; i * i < primeFlags.length; i++)
        {
            if (!primeFlags[i])
            {
                continue;
            }
            for (int j = i * i; j < primeFlags.length; j += i)
            {
                primeFlags[j] = false;
            }
        }
        int count = 0;
        for (int i = 2; i < primeFlags.length; i++)
        {
            if (primeFlags[i])
            {
                count++;
            }
        }
        primes = new int[count];
        count = 0;
        for (int i = 2; i < primeFlags.length; i++)
        {
            if (primeFlags[i])
            {
                primes[count] = i;
                count++;
            }
        }
    }

    public void readData() throws Exception
    {
        D = Integer.parseInt(readWord());
        K = Integer.parseInt(readWord());
        S = new int[K];
        for (int i = 0; i < K; i++)
        {
            S[i] = Integer.parseInt(readWord());
        }
    }

    public int rev(int x, int p)
    {
        x %= p;
        if (x < 0)
        {
            x += p;
        }
        if (x == 1)
        {
            return 1;
        }
        int xx = x % p;
        int r = rev(p, xx);
        if (r != 0)
        {
            r = xx - r;
        }
        return (int)((r * (long)p + 1) / x);
    }

    int next;

    public void solve()
    {
        init();
        next = -1;
        if (K == 1)
        {
            return;
        }
        if (S[0] == S[1])
        {
            next = S[0];
            return;
        }
        if (K == 2)
        {
            return;
        }
        int maxP = deg10[D];
        int minP = 2;
        for (int i = 0; i < K; i++)
        {
            minP = max(minP, S[i]);
        }
        main: for (int pi = 0; pi < primes.length && primes[pi] < maxP; pi++)
        {
            if (primes[pi] <= minP)
            {
                continue;
            }
            int p = primes[pi];
            int A = (int)((rev(S[1] - S[0], p) * (long)(S[2] - S[1])) % p);
            if (A<0)
            {
                A+=p;
            }
            for (int j=3;j<K;j++)
            {
                int pnext = (int)(((S[j - 1] - S[j - 2]) * (long)A) + S[j - 1]) % p;
                if (pnext<0)
                {
                    pnext+=p;
                }
                if (pnext!=S[j])
                {
                    continue main;
                }
            }
            int pnext = (int)(((S[K - 1] - S[K - 2]) * (long)A + S[K - 1]) % p);
            if (pnext < 0)
            {
                pnext += p;
            }
            if (next == -1 || next == pnext)
            {
                next = pnext;
            } else
            {
                next = -1;
                break;
            }
        }
    }

    public void writeAns()
    {
        if (next < 0)
        {
            out.append("I don't know.\n");
            return;
        }
        out.append(next + "\n");
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
                Locale.setDefault(Locale.US);
                stdin = new BufferedReader(new FileReader(NAME + ".in"));
                stdout = new BufferedWriter(new FileWriter(NAME + ".out"));
                tests = Integer.parseInt(readLine().trim());
                answers = new String[tests];
                test = 0;
                Thread[] threads = new Thread[THREADS];
                final DecimalFormat timeFormat = new DecimalFormat("######0.000");
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
                                long time = System.nanoTime();
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
                                try
                                {
                                    inst.solve();
                                    inst.writeAns();
                                } catch (Throwable e)
                                {
                                    e.printStackTrace();
                                }
                                synchronized (answers)
                                {
                                    answers[ltest] = inst.out.toString();
                                }
                                time = System.nanoTime() - time;
                                System.err.println(ltest + " " + timeFormat.format(time * 1e-9));
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
            } catch (Throwable e)
            {
                e.printStackTrace();
            }
        }
    }

    public static void main(String[] args)
    {
        Common.startThreads();
    }
}
