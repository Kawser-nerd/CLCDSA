import java.awt.Point;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.text.DecimalFormat;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Locale;

// 1.6
public class B
{
    static final int THREADS = 1;
    static final String NAME = "b-large";
    static final int POINTS = 20;
    StringBuilder out;
    int N;
    Point[] points;
    double d;

    public void readData() throws Exception
    {
        N = Integer.parseInt(readWord());
        points = new Point[N];
        for (int i = 0; i < N; i++)
        {
            int x = Integer.parseInt(readWord());
            int y = Integer.parseInt(readWord());
            points[i] = new Point(x, y);
        }
    }

    final static double C = Math.sqrt(2);
    final static double C1 = Math.sqrt(1 + C * C);

    public void sort()
    {
        Comparator<Point> c = new Comparator<Point>() {
            @Override
            public int compare(Point o1, Point o2)
                        {
                double v1 = o1.x + C * o1.y;
                double v2 = o2.x + C * o2.y;
                if (v1 < v2)
                            {
                    return -1;
                }
                if (v1 > v2)
                            {
                    return 1;
                }
                return 0;
            }
        };
        Arrays.sort(points, c);
    }

    double[][] tmp = new double[100][100];
    Point[] tmpList;
    Comparator<Point> c1 = new Comparator<Point>() {
        @Override
        public int compare(Point o1, Point o2)
                {
            double v1 = o1.x * C - o1.y;
            double v2 = o2.x * C - o2.y;
            if (v1 < v2)
                    {
                return -1;
            }
            if (v1 > v2)
                    {
                return 1;
            }
            return 0;
        }
    };

    public void calc(int left, int right)
    {
        if (right - left < 20)
        {
            int len = right - left;
            for (int i = 0; i < len; i++)
            {
                Point p = points[left + i];
                for (int j = i + 1; j < len; j++)
                {
                    tmp[i][j] = p.distance(points[left + j]);
                    tmp[j][i] = tmp[i][j];
                }
            }
            for (int i = 0; i < len; i++)
            {
                for (int j = i + 1; j < len; j++)
                {
                    for (int k = j + 1; k < len; k++)
                    {
                        d = Math.min(tmp[i][j] + tmp[i][k] + tmp[j][k], d);
                    }
                }
            }
            return;
        }
        int middle = (left + right) / 2;
        calc(left, middle);
        calc(middle, right);
        int size = 0;
        double diff = C1 * d / 2;
        double avr = points[middle].x + points[middle].y * C;
        for (int i = left; i < right; i++)
        {
            double v = points[i].x + points[i].y * C;
            if (Math.abs(v - avr) < diff)
            {
                tmpList[size] = points[i];
                size++;
            }
        }
        Arrays.sort(tmpList, 0, size, c1);
        double[] tmpDist = new double[POINTS];
        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size && j < i + POINTS; j++)
            {
                tmpDist[j - i] = tmpList[i].distance(tmpList[j]);
            }
            for (int j = i + 1; j < size && j < i + POINTS; j++)
            {
                double ans = tmpDist[j - i];
                if (ans > d)
                {
                    continue;
                }
                for (int k = j + 1; k < size && k < i + POINTS; k++)
                {
                    d = Math.min(d, ans + tmpDist[k - i]
                        + tmpList[j].distance(tmpList[k]));
                }
            }
        }
    }
    public void solve()
    {
        sort();
        d = 1e+100;
        tmpList = new Point[N];
        calc(0, N);
        DecimalFormat df = new DecimalFormat("############0.00000000000");
        out.append(df.format(d) + "\n");
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
                    final B inst = new B();
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
