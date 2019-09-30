import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.text.DecimalFormat;
import java.util.Locale;

// 1.6
public class B
{
    static final int THREADS = 2;
    static final String NAME = "b-large";
    StringBuilder out;

    int p;
    int[] ms;
    int[][] prices;

    public void readData() throws Exception
    {
        p = Integer.parseInt(readWord());
        ms = new int[1 << p];
        for (int i = 0; i < ms.length; i++)
        {
            ms[i] = Integer.parseInt(readWord());
        }
        prices = new int[p][];
        for (int i = 0; i < p; i++)
        {
            prices[i] = new int[1 << (p - i - 1)];
            for (int j = 0; j < prices[i].length; j++)
            {
                prices[i][j] = Integer.parseInt(readWord());
            }
        }
    }

    int[][][] dyn;
    int ans;
    public static int INF = 1000000000;

    public void solve()
    {
        dyn = new int[p + 1][][];
        for (int i = 0; i <= p; i++)
        {
            dyn[i] = new int[1 << (p - i)][p - i + 1];
        }
        for (int j = 0; j < 1 << p; j++)
        {
            int m = p - ms[j];
            for (int k = 0; k < m; k++)
            {
                dyn[0][j][k] = INF;
            }
            for (int k = m; k <= p; k++)
            {
                dyn[0][j][k] = 0;
            }
        }
        for (int i = 1; i <= p; i++)
        {
            for (int j = 0; j < dyn[i].length; j++)
            {
                for (int k = 0; k < dyn[i][j].length; k++)
                {
                    dyn[i][j][k] = Math.min(INF, dyn[i - 1][2 * j][k] + dyn[i - 1][2 * j + 1][k]);
                    dyn[i][j][k] = Math.min(dyn[i][j][k], dyn[i - 1][2 * j][k + 1]
                        + dyn[i - 1][2 * j + 1][k + 1] + prices[i - 1][j]);
                }
            }
        }
        ans = dyn[p][0][0];
    }
    public void writeAns()
    {
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
                    final B inst = new B();
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
