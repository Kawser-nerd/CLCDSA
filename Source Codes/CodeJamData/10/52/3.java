import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.text.DecimalFormat;
import java.util.Arrays;
import java.util.Locale;

// 1.6
public class B
{
    static final int THREADS = 2;
    static final String NAME = "b-large";
    StringBuilder out;
    long L;
    int N;
    int[] Bs;

    long ans;

    public void readData() throws Exception
    {
        L = Long.parseLong(readWord());
        N = Integer.parseInt(readWord());
        Bs = new int[N];
        for (int i = 0; i < N; i++)
        {
            Bs[i] = Integer.parseInt(readWord());
        }
    }

    int BMax;
    int[] dist;
    final static int INF = 100000000;

    public void solve()
    {
        N = Bs.length;
        Arrays.sort(Bs);
        BMax = Bs[N - 1];
        ans = L / BMax;
        L = L % BMax;
        dist = new int[BMax];
        Arrays.fill(dist, INF);
        dist[0] = 0;
        int[] queue = new int[BMax];
        int[] nextQueue = new int[BMax];
        int nQueue = 1;
        int nNextQueue = 0;
        queue[0] = 0;
        while (nQueue > 0)
        {
            // reverse
            for (int i = 0; i < nQueue; i++)
            {
                int elem = queue[i];
                for (int j = 0; j < N - 1; j++)
                {
                    int move = elem + Bs[j] - BMax;
                    if (move >= 0 && dist[move] == INF)
                    {
                        dist[move] = dist[elem];
                        queue[nQueue] = move;
                        nQueue++;
                    }
                }
            }
            // forward
            nNextQueue = 0;
            for (int i = 0; i < nQueue; i++)
            {
                int elem = queue[i];
                for (int j = 0; j < N - 1; j++)
                {
                    int move = elem + Bs[j];
                    if (move < BMax && dist[move] == INF)
                    {
                        dist[move] = dist[elem] + 1;
                        nextQueue[nNextQueue] = move;
                        nNextQueue++;
                    }
                }
            }
            int[] tmp = queue;
            queue = nextQueue;
            nextQueue = tmp;
            nQueue = nNextQueue;
        }
        if (dist[(int)L] == INF)
        {
            ans = -1;
        } else
        {
            ans += dist[(int)L];
        }
    }

    public void writeAns()
    {
        if (ans < 0)
        {
            out.append("IMPOSSIBLE\n");
        } else
        {
            out.append(ans + "\n");
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
