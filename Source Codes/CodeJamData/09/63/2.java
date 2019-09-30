import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Locale;

// 1.6
public class C
{
    static final int THREADS = 1;
    static final String NAME = "c-small-attempt1";
    StringBuilder out;
    int R, C;
    int[][] grid;

    public void readData() throws Exception
    {
        R = Integer.parseInt(readWord());
        C = Integer.parseInt(readWord());
        grid = new int[R][C];
        for (int i = 0; i < R; i++)
        {
            String s = readWord();
            for (int j = 0; j < C; j++)
            {
                if (s.charAt(j) == '.')
                {
                    grid[i][j] = -1;
                } else
                {
                    grid[i][j] = s.charAt(j) - 'a';
                }
            }
        }
    }

    int[] pow26;
    final static int MOD = 10007;

    public void solve()
    {
        pow26 = new int[C + 1];
        pow26[0] = 1;
        for (int i = 1; i <= C; i++)
        {
            pow26[i] = 26 * pow26[i - 1];
        }
        int[] sost = new int[pow26[C]];
        int[] decode = new int[C];
        loop1: for (int i = 0; i < pow26[C]; i++)
        {
            int ii = i;
            for (int j = 0; j < C; j++)
            {
                decode[j] = ii % 26;
                ii /= 26;
                if (j > 0 && decode[j] < decode[j - 1])
                {
                    continue loop1;
                }
                if (grid[0][j] >= 0 && decode[j] != grid[0][j])
                {
                    continue loop1;
                }
            }
            sost[i] = 1;
        }
        int[] next = new int[pow26[C]];
        for (int gstep = 1; gstep < R; gstep++)
        {
            for (int step = 0; step < C; step++)
            {
                loop2: for (int i = 0; i < pow26[C]; i++)
                {
                    next[i] = 0;
                    int ii = i;
                    for (int j = 0; j < C; j++)
                    {
                        decode[j] = ii % 26;
                        ii /= 26;
                    }
                    for (int j = 0; j < C; j++)
                    {
                        int r = j <= step ? gstep : gstep - 1;
                        if (grid[r][j] >= 0 && grid[r][j] != decode[j])
                        {
                            continue loop2;
                        }
                    }
                    for (int j = 1; j <= step; j++)
                    {
                        if (decode[j] < decode[j - 1])
                        {
                            continue loop2;
                        }
                    }
                    for (int j = step + 2; j < C; j++)
                    {
                        if (decode[j] < decode[j - 1])
                        {
                            continue loop2;
                        }
                    }
                    for (int k = 0; k <= decode[step]; k++)
                    {
                        next[i] += sost[i - k * pow26[step]];
                        next[i] = next[i] % MOD;
                    }
                }
                System.arraycopy(next, 0, sost, 0, next.length);
            }
        }
        int ans = 0;
        for (int i = 0; i < sost.length; i++)
        {
            ans = (ans + sost[i]) % MOD;
        }
        out.append(ans + "\n");
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
                    final C inst = new C();
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
