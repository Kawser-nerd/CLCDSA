import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.text.DecimalFormat;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Locale;
import java.util.Set;

// 1.6
public class D
{
    static final int THREADS = 2;
    static final String NAME = "d-large";
    StringBuilder out;
    int n;
    long F;
    long[] Xs;
    long opt;

    public void readData() throws Exception
    {
        n = Integer.parseInt(readWord());
        Xs = new long[n];
        for (int i = 0; i < n; i++)
        {
            Xs[i] = Long.parseLong(readWord());
        }
        F = Long.parseLong(readWord());
    }

    public void rec1(int data[], int v1, int v2, long sum)
    {
        if (v2 >= data.length)
        {
            return;
        }
        for (int v1next = v1; v1next < data.length - 1; v1next++)
        {
            if (data[v1next] == 0)
            {
                data[v1next] = 1;
                for (int v2next = Math.max(v2, v1next + 1); v2next < data.length - 1; v2next++)
                {
                    if (data[v2next] == 0)
                    {
                        data[v2next] = 1;
                        long newSum = sum + Xs[v2next] - Xs[v1next];
                        if (v1next + v2next <= n)
                        {
                            add(v1next, v2next, newSum);
                            rec1(data, v1next + 1, v2next + 1, newSum);
                        }
                        data[v2next] = 0;
                    }
                }
                data[v1next] = 0;
            }
        }
    }

    public long recFull(int data[], int v1, int v2, long sum)
    {
        if (v2 >= data.length)
        {
            return -1;
        }
        long res = -1;
        for (int v1next = v1; v1next < data.length - 1; v1next++)
        {
            if (data[v1next] == 0)
            {
                data[v1next] = 1;
                for (int v2next = Math.max(v2, v1next + 1); v2next < data.length - 1; v2next++)
                {
                    if (data[v2next] == 0)
                    {
                        data[v2next] = 1;
                        long newSum = sum + Xs[v2next] - Xs[v1next];
                        if (newSum==1412800)
                        {
                            System.out.print("");
                        }
                        if (newSum <= F)
                        {
                            res = Math.max(newSum, res);
                        }
                        res = Math.max(res, recFull(data, v1next + 1,
                                v2next + 1, newSum));
                        data[v2next] = 0;
                    }
                }
                data[v1next] = 0;
            }
        }
        return res;
    }

    public void rec2(int data[], int v1, int v2, long sum)
    {
        if (v1 <= 0)
        {
            return;
        }
        for (int v1next = 1; v1next <= v1; v1next++)
        {
            if (data[v1next] == 0)
            {
                data[v1next] = 1;
                for (int v2next = v1next + 1; v2next <= v2; v2next++)
                {
                    if (data[v2next] == 0)
                    {
                        data[v2next] = 1;
                        long newSum = sum + Xs[v2next] - Xs[v1next];
                        if (v1next + v2next > n)
                        {
                            add(v1next, v2next, newSum);
                            rec2(data, v1next - 1, v2next - 1, newSum);
                        }
                        data[v2next] = 0;
                    }
                }
                data[v1next] = 0;
            }
        }
    }

    public void add(int x, int y, long value)
    {
        int l = lens[x][y];
        if (l < sums[x][y].length)
        {
            sums[x][y][l] = value;
            lens[x][y] = l + 1;
            return;
        }
        long[] d1 = new long[2 * l + 1];
        System.arraycopy(sums[x][y], 0, d1, 0, l);
        sums[x][y] = d1;
        sums[x][y][l] = value;
        lens[x][y] = l + 1;
    }

    long[][][] sums;
    int[][] lens;

    public void solve()
    {
        Arrays.sort(Xs);
        F /= 2;
        long min = Xs[0];
        for (int i = 0; i < Xs.length; i++)
        {
            Xs[i] -= min;
        }
        if (F < Xs[n - 1])
        {
            opt = -1;
            return;
        }
        opt = Xs[n - 1];
        sums = new long[n][n][0];
        lens = new int[n][n];
        add(0, 0, Xs[n - 1]);
        add(n - 1, n - 1, 0);
        rec1(new int[n], 1, 2, Xs[n - 1]);
        rec2(new int[n], n - 3, n - 2, 0);
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                if (i + j <= n && lens[i][j] > 0)
                {
                    long[] v1 = sums[i][j];
                    int len1 = lens[i][j];
                    for (int i1 = i + 1; i1 < n; i1++)
                    {
                        for (int j1 = j + 1; j1 < n; j1++)
                        {
                            if (i1 + j1 > n && lens[i1][j1] > 0)
                            {
                                updateOpt(v1, len1, sums[i1][j1], lens[i1][j1]);
                            }
                        }
                    }
                }
            }
        }
        //long value = Math.max(recFull(new int[n], 1, 2, Xs[n - 1]),Xs[n-1]);
        //rec2(new int[n],n-2,n-1,0);
        //if (value != opt)
        //{
        //    System.out.println("bug");
        //}
        opt *= 2;
    }

    public void updateOpt(long[] v1, int len1, long[] v2, int len2)
    {
        Arrays.sort(v1, 0, len1);
        Arrays.sort(v2, 0, len2);
        int j = len2 - 1;
        for (int i = 0; i < len1; i++)
        {
            while (j >= 0 && v1[i] + v2[j] > F)
            {
                j--;
            }
            if (j < 0)
            {
                return;
            }
            opt = Math.max(opt, v1[i] + v2[j]);
        }
    }

    public void writeAns()
    {
        if (opt < 0)
        {
            out.append("NO SOLUTION\n");
        } else
        {
            out.append(opt + "\n");
        }
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
            b.append((char) c);
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
                final DecimalFormat timeFormat = new DecimalFormat(
                        "######0.000");
                for (int i = 0; i < threads.length; i++)
                {
                    final D inst = new D();
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
                                System.err.println(ltest + " "
                                        + timeFormat.format(time * 1e-9));
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
