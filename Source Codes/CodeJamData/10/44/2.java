import java.awt.geom.Point2D;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.text.DecimalFormat;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Locale;

// 1.6
public class D
{
    static final int THREADS = 2;
    static final String NAME = "d-large";
    StringBuilder out;

    int N;
    int M;
    Point2D.Double[] P;
    Point2D.Double[] Q;
    double[] ans;

    public void readData() throws Exception
    {
        N = Integer.parseInt(readWord());
        M = Integer.parseInt(readWord());
        P = new Point2D.Double[N];
        for (int i = 0; i < N; i++)
        {
            P[i] = new Point2D.Double();
            P[i].x = Integer.parseInt(readWord());
            P[i].y = Integer.parseInt(readWord());
        }
        Q = new Point2D.Double[M];
        for (int i = 0; i < M; i++)
        {
            Q[i] = new Point2D.Double();
            Q[i].x = Integer.parseInt(readWord());
            Q[i].y = Integer.parseInt(readWord());
        }
    }

    Point2D.Double[] centers;
    Point2D.Double[] centersTmp;
    Integer[] cache;
    Integer[] sortTmp;
    Integer[] sortTmp2;

    public static double pointAngle(Point2D.Double point)
    {
        return Math.atan2(point.y, point.x);
    }

    public boolean sortCenters()
    {
        final double[] angles = new double[N];
        for (int i = 0; i < N; i++)
        {
            angles[i] = pointAngle(centers[i]);
        }
        Comparator<Integer> cmp = new Comparator<Integer>()
        {

            @Override
            public int compare(Integer o1, Integer o2)
            {
                double d1 = angles[o1];
                double d2 = angles[o2];
                return Double.compare(d1, d2);
            }

        };
        System.arraycopy(cache, 0, sortTmp, 0, N);
        Arrays.sort(sortTmp, cmp);
        double min = angles[sortTmp[0]];
        double max = angles[sortTmp[N - 1]];
        boolean res = false;
        if (max - min > Math.PI - 1e-9)
        {
            for (int i = 0; i < N - 1; i++)
            {
                if (angles[sortTmp[i + 1]] - angles[sortTmp[i]] > Math.PI + 1e-9)
                {
                    System.arraycopy(sortTmp, 0, sortTmp2, 0, i + 1);
                    System.arraycopy(sortTmp, i + 1, sortTmp, 0, N - i - 1);
                    System.arraycopy(sortTmp2, 0, sortTmp, N - i - 1, i + 1);
                    res = true;
                    break;
                }
            }
        } else
        {
            res = true;
        }
        for (int i = 0; i < N; i++)
        {
            centersTmp[i] = centers[sortTmp[i]];
        }
        return res;
    }

    int[] inds;
    int ninds;

    public void intersect(Point2D.Double line1, Point2D.Double line2, Point2D.Double point)
    {
        double d = line1.x * line2.y - line1.y * line2.x;
        point.x = (line2.y - line1.y) / d;
        point.y = (line1.x - line2.x) / d;
    }

    public void findConvex()
    {
        ninds = 1;
        inds[0] = 0;
        Point2D.Double p = new Point2D.Double();
        for (int i = 1; i < N; i++)
        {
            Point2D.Double prev = centersTmp[inds[ninds - 1]];
            Point2D.Double next = centersTmp[i];
            double scalar = Math.abs(prev.x * next.y - prev.y * next.x);
            if (scalar < 0.5)
            {
                assert scalar < 1e-3;
                if (next.distance(0, 0) < prev.distance(0, 0))
                {
                    continue;
                }
                inds[ninds - 1] = i;
            } else
            {
                inds[ninds] = i;
                ninds++;
            }
            while (ninds >= 3)
            {
                intersect(centersTmp[inds[ninds - 3]], centersTmp[inds[ninds - 1]], p);
                Point2D.Double lineMiddle = centersTmp[inds[ninds - 2]];
                if (lineMiddle.x * p.x + lineMiddle.y * p.y >= 1 - 1e-9)
                {
                    inds[ninds - 2] = inds[ninds - 1];
                    ninds--;
                } else
                {
                    break;
                }
            }
        }
    }

    Point2D.Double[] areaAngles;

    public void calcPoints()
    {
        areaAngles[0] = new Point2D.Double();
        for (int i = 1; i < ninds; i++)
        {
            areaAngles[i] = new Point2D.Double();
            intersect(centersTmp[inds[i - 1]], centersTmp[inds[i]], areaAngles[i]);
            double d = areaAngles[i].distanceSq(areaAngles[0]);
            areaAngles[i].x = 2 * areaAngles[i].x / d;
            areaAngles[i].y = 2 * areaAngles[i].y / d;
        }
        areaAngles[ninds] = new Point2D.Double();
    }
    public double polygonArea()
    {
        double res = 0;
        for (int i = 0; i < ninds - 1; i++)
        {
            res += areaAngles[i].y * areaAngles[i + 1].x - areaAngles[i].x * areaAngles[i + 1].y;
        }
        return res / 2;
    }
    public double cycleArea()
    {
        if (ninds == 1)
        {
            return Math.PI * centers[sortTmp[inds[0]]].distanceSq(0, 0);
        }
        double res = 0;
        Point2D.Double tmp = new Point2D.Double();
        Point2D.Double tmp1 = new Point2D.Double();
        Point2D.Double origin = new Point2D.Double();
        for (int i = 0; i < ninds; i++)
        {
            int circle = sortTmp[inds[i]];
            tmp.x = areaAngles[i].x - centers[circle].x;
            tmp.y = areaAngles[i].y - centers[circle].y;
            assert Math.abs(tmp.distance(origin) - centers[circle].distance(origin)) < 1e-8;
            double start = pointAngle(tmp);
            tmp1.x = areaAngles[i + 1].x - centers[circle].x;
            tmp1.y = areaAngles[i + 1].y - centers[circle].y;
            assert Math.abs(tmp1.distance(origin) - centers[circle].distance(origin)) < 1e-8;
            double finish = pointAngle(tmp1);
            double diff = start - finish;
            if (diff < -1e-9)
            {
                diff += 2 * Math.PI;
            }
            if (diff > 2 * Math.PI - 1e-9)
            {
                diff -= 2 * Math.PI;
            }
            res += diff * centers[circle].distanceSq(origin) / 2;
            res -= (tmp.y * tmp1.x - tmp.x * tmp1.y) / 2;
        }
        return res;
    }
    public double calcArea()
    {
        if (!sortCenters())
        {
            return 0;
        }
        findConvex();
        calcPoints();
        double area = 0;
        area += polygonArea();
        area += cycleArea();
        return area;
    }

    public void solve()
    {
        ans = new double[M];
        cache = new Integer[N];
        sortTmp = new Integer[N];
        sortTmp2 = new Integer[N];
        centersTmp = new Point2D.Double[N];
        areaAngles = new Point2D.Double[N + 1];
        inds = new int[N];
        for (int i = 0; i < N; i++)
        {
            cache[i] = i;
        }
        centers = new Point2D.Double[N];
        for (int i = 0; i < N; i++)
        {
            centers[i] = new Point2D.Double();
        }
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                centers[j].x = P[j].x - Q[i].x;
                centers[j].y = P[j].y - Q[i].y;
            }
            double area = calcArea();
            ans[i] = area;
        }
    }

    DecimalFormat df = new DecimalFormat("###############0.00000000");

    public void writeAns()
    {
        for (int i = 0; i < ans.length; i++)
        {
            if (i > 0)
            {
                out.append(" ");
            }
            out.append(df.format(ans[i]));
        }
        out.append("\n");
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
