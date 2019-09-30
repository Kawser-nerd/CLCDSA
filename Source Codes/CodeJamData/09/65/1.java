import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Locale;

// 1.6
public class E
{
    static final int THREADS = 1;
    static final String NAME = "e-small-attempt1";
    static final int INF = 1000000;
    StringBuilder out;
    int N;
    int[] colors;

    public void readData() throws Exception
    {
        N = Integer.parseInt(readWord());
        colors = new int[2 * N];
        HashMap<String, Integer> map = new HashMap<String, Integer>();
        int next = 0;
        for (int i = 0; i < 2 * N; i++)
        {
            String s = readWord();
            if (!map.containsKey(s))
            {
                map.put(s, next);
                next++;
            }
            colors[i] = map.get(s);
        }
    }

    int[] start;
    int[] finish;
    int[][] graph;
    int[] color;
    int[] compNum;
    List<List<Integer>> comps;

    public boolean rec(int v, List<Integer> list)
    {
        for (int i = 0; i < N; i++)
        {
            if (graph[i][v] == 1)
            {
                if (color[i] == color[v])
                {
                    return true;
                }
                if (color[i] == -1)
                {
                    color[i] = 1 - color[v];
                    list.add(i);
                    if (rec(i, list))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    public boolean fillColor()
    {
        color = new int[N];
        compNum = new int[N];
        Arrays.fill(color, -1);
        comps = new ArrayList<List<Integer>>();
        for (int i = 0; i < N; i++)
        {
            if (color[i] < 0)
            {
                ArrayList<Integer> comp = new ArrayList<Integer>();
                color[i] = 0;
                comp.add(i);
                if (rec(i, comp))
                {
                    return true;
                }
                for (int j = 0; j < comp.size(); j++)
                {
                    compNum[comp.get(j)] = comps.size();
                }
                comps.add(comp);
            }
        }
        return false;
    }
    public boolean init()
    {
        start = new int[N];
        finish = new int[N];
        Arrays.fill(start, -1);
        for (int i = 0; i < colors.length; i++)
        {
            int c = colors[i];
            if (start[c] == -1)
            {
                start[c] = i;
            } else
            {
                finish[c] = i;
            }
        }
        graph = new int[N][N];
        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                if ((start[i] < start[j] && start[j] < finish[i] && finish[i] < finish[j])
                    ||
                    (start[j] < start[i] && start[i] < finish[j] && finish[j] < finish[i]))
                {
                    graph[i][j] = 1;
                    graph[j][i] = 1;
                }
            }
        }
        if (fillColor())
        {
            return true;
        }
        return false;
    }
    public int get(int[] opt, int value)
    {
        if (value < opt.length)
        {
            return opt[value];
        }
        return opt[opt.length - 1];
    }
    public int[] symm(int[] opt)
    {
        int max = 0;
        for (int i = 0; i < opt.length; i++)
        {
            if (opt[i] < INF)
            {
                max = Math.max(opt[i], max);
            }
        }
        int[] next;
        // todo: optimize
        next = new int[Math.max(opt.length, max + 1)];
        Arrays.fill(next,INF);
        System.arraycopy(opt, 0, next, 0, opt.length);
        for (int i = 0; i < opt.length; i++)
        {
            if (opt[i] < INF)
            {
                next[opt[i]] = Math.min(next[opt[i]], i);
            }
        }
        return next;
    }
    public int[] comp(int left, int right)
    {
        if (left == right)
        {
            return new int[] { 0 };
        }
        if (left>right)
        {
            throw new RuntimeException("bug");
        }
        int compn = compNum[colors[left]];
        List<Integer> comp = comps.get(compn);
        int compSize = comp.size();
        int[] up = new int[2 * compSize];
        int[] down = new int[2 * compSize];
        int[] values = new int[2 * compSize];
        for (int i = 0; i < compSize; i++)
        {
            values[2 * i] = start[comp.get(i)];
            values[2 * i + 1] = finish[comp.get(i)];
        }
        Arrays.sort(values);
        if (values[0]<left)
        {
            throw new RuntimeException("bug");
        }
        for (int i = 0; i < compSize; i++)
        {
            int s = start[comp.get(i)];
            int f = finish[comp.get(i)];
            int j = 0;
            while (values[j] < s)
            {
                j++;
            }
            while (values[j] < f)
            {
                if (color[comp.get(i)] == 0)
                {
                    up[j]++;
                } else
                {
                    down[j]++;
                }
                j++;
            }
        }
        int[][] opts = new int[2 * compSize][];
        for (int i = 0; i < 2 * compSize - 1; i++)
        {
            opts[i] = comp(values[i] + 1, values[i + 1]);
        }
        opts[2 * compSize - 1] = comp(values[2 * compSize - 1] + 1, right);
        int[] cur;
        int maxDown = 0;
        for (int i = 0; i < opts.length; i++)
        {
            maxDown = Math.max(maxDown, down[i] + opts[i].length - 1);
        }
        cur = new int[maxDown + 1];
        for (int i = 0; i <= maxDown; i++)
        {
            int ans = 0;
            for (int j = 0; j < 2 * compSize; j++)
            {
                if (i < down[j])
                {
                    ans = INF;
                } else
                {
                    ans = Math.max(ans, up[j] + get(opts[j], i - down[j]));
                }
            }
            cur[i] = Math.min(INF, ans);
        }
        cur = symm(cur);
        return cur;
    }
    public void solve()
    {
        if (init())
        {
            out.append("-1\n");
            return;
        }
        int[] opt = comp(0, 2 * N);
        int min = INF;
        for (int i = 0; i < opt.length; i++)
        {
            min = Math.min(min, i + opt[i]);
        }
        out.append(min + "\n");
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
                    final E inst = new E();
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
