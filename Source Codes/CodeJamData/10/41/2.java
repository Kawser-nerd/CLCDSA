import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.text.DecimalFormat;
import java.util.Locale;

// 1.6
public class A
{
    static final int THREADS = 2;
    static final String NAME = "a-large";
    StringBuilder out;
    int k;
    int[][] data;
    int size;
    int ans;

    public void readData() throws Exception
    {
        k = Integer.parseInt(readWord());
        data = new int[2 * k - 1][2 * k - 1];
        for (int i = 0; i < data.length; i++)
        {
            for (int j = 0; j < data[i].length; j++)
            {
                if ((i + j + k) % 2 != 0)
                {
                    data[i][j] = -1;
                }
            }
        }
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                data[i][2 * j - i + k - 1] = Integer.parseInt(readWord());
            }
        }
        for (int i = k; i < 2 * k - 1; i++)
        {
            int ii = 2 * k - 2 - i;
            for (int j = 0; j <= ii; j++)
            {
                data[i][2 * j - ii + k - 1] = Integer.parseInt(readWord());
            }
        }
    }

    boolean[] flagV;
    boolean[] flagH;

    public boolean eq(int x, int y)
    {
        if (x < 0 || y < 0)
        {
            return true;
        }
        return x == y;
    }
    public void solve()
    {
        flagV = new boolean[2 * k - 1];
        flagH = new boolean[2 * k - 1];
        mainV: for (int yv = 0; yv < 2 * k - 1; yv++)
        {
            for (int y1 = 0; y1 < 2 * k - 1; y1++)
            {
                int y2 = 2 * yv - y1;
                if (y2 < 0 || y2 >= 2 * k - 1)
                {
                    continue;
                }
                for (int x1 = 0; x1 < 2 * k - 1; x1++)
                {
                    if (!eq(data[x1][y1], data[x1][y2]))
                    {
                        continue mainV;
                    }
                }
            }
            flagV[yv] = true;
        }
        mainH: for (int xv = 0; xv < 2 * k - 1; xv++)
        {
            for (int x1 = 0; x1 < 2 * k - 1; x1++)
            {
                int x2 = 2 * xv - x1;
                if (x2 < 0 || x2 >= 2 * k - 1)
                {
                    continue;
                }
                for (int y1 = 0; y1 < 2 * k - 1; y1++)
                {
                    if (!eq(data[x1][y1], data[x2][y1]))
                    {
                        continue mainH;
                    }
                }
            }
            flagH[xv] = true;
        }
        int size = 3 * k;
        for (int i = 0; i < 2 * k - 1; i++)
        {
            if (flagV[i])
            {
                for (int j = 0; j < 2 * k - 1; j++)
                {
                    if (flagH[j])
                    {
                        int cur = k + Math.abs(i - k + 1) + Math.abs(j - k + 1);
                        size = Math.min(size, cur);
                    }
                }
            }
        }
        assert size < 3 * k;
        ans = size * size - k * k;
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
