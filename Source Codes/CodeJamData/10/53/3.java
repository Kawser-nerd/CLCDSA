import static java.lang.Math.min;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Locale;

// 1.6
public class C
{
    static final int THREADS = 2;
    static final String NAME = "c-large";
    StringBuilder out;
    int C;
    long[] P;
    long[] V;
    long ans;

    /**
     * inclusive interval
     */
    class Interval implements Comparable<Interval>
    {
        long start;
        long finish;
        long count;
        long sum;
        boolean[] set;

        public Interval(long start, long finish, long sum, boolean[] set)
        {
            this.set = set;
            this.start = start;
            this.finish = finish;
            this.sum = sum;
            this.count = finish - start;
        }

        public void revalidate()
        {
            long sumCount = ((count - 1) * count) / 2;
            long sumStart = sum - sumCount;
            if (sumStart > 0)
            {
                start = (sumStart / count);
            } else
            {
                start = (sumStart / count);
                if (sumStart % count != 0)
                {
                    start--;
                }
            }
            finish = start + count;
        }

        public long getMoves()
        {
            long total = (count + 1) * count * (count - 1);
            long sumCount = ((count + 1) * count) / 2;
            long missing = (sumCount + start * count - sum);
            total -= 3 * missing * (missing - 1);
            for (int i = 0; i < set.length; i++)
            {
                if (set[i])
                {
                    long diff = P[i] - start;
                    total -= 3 * (diff) * (diff - 1) * V[i];
                }
            }
            if (total % 6 != 0)
            {
                throw new RuntimeException("bug");
            }
            return total / 6;
        }

        @Override
        public int compareTo(Interval o)
        {
            if (start < o.start)
            {
                return -1;
            }
            if (start > o.start)
            {
                return 1;
            }
            return 0;
        }
    }

    public void readData() throws Exception
    {
        C = Integer.parseInt(readWord());
        P = new long[C];
        V = new long[C];
        for (int i = 0; i < C; i++)
        {
            P[i] = Integer.parseInt(readWord());
            V[i] = Integer.parseInt(readWord());
        }
    }

    public void solve()
    {
        ans = 0;
        for (int i = 0; i < C; i++)
        {
            for (int j = i + 1; j < C; j++)
            {
                if (P[j] < P[i])
                {
                    long tmp = P[j];
                    P[j] = P[i];
                    P[i] = tmp;
                    tmp = V[j];
                    V[j] = V[i];
                    V[i] = tmp;
                }
            }
        }
        Interval[] all = new Interval[C];
        for (int i = 0; i < C; i++)
        {
            boolean[] set = new boolean[C];
            set[i] = true;
            long sum = P[i] * V[i];
            if (V[i] % 2 == 0)
            {
                all[i] = new Interval(P[i] - V[i] / 2, P[i] + V[i] / 2, sum, set);
            } else
            {
                all[i] = new Interval(P[i] - V[i] / 2, P[i] + V[i] / 2 + 1, sum, set);
            }
        }
        Arrays.sort(all);
        List<Interval> curInts = new ArrayList<Interval>();
        for (int i = 0; i < all.length; i++)
        {
            Interval last = all[i];
            while (curInts.size() > 0)
            {
                Interval prev = curInts.get(curInts.size() - 1);
                if (prev.finish < last.start)
                {
                    break;
                }
                curInts.remove(curInts.size() - 1);
                last.sum += prev.sum;
                last.count += prev.count;
                for (int j = 0; j < last.set.length; j++)
                {
                    last.set[j] |= prev.set[j];
                }
                last.revalidate();
            }
            curInts.add(last);
        }
        for (int i = 0; i < curInts.size(); i++)
        {
            ans += curInts.get(i).getMoves();
        }
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
                    final C inst = new C();
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
