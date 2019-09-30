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
    static final String NAME = "a-large";
    StringBuilder out;
    String s;
    char[] chars;
    int ans;
    int n;

    public void readData() throws Exception
    {
        s = readWord();
        chars = s.toCharArray();
        //chars=new char[7000];
        //Arrays.fill(chars,'A');
        //for (int i=0;i<7000;i+=3)
        //{
        //    chars[i]='B';
        //}
        //for (int i=1;i<7000;i+=3)
        //{
        //    chars[i]='C';
        //}
    }

    int[][] dyn;

    public int rec(int x, int y)
    {
        if (x >= y)
        {
            return 0;
        }
        if (dyn[x][y] >= 0)
        {
            return dyn[x][y];
        }
        if (chars[x]==chars[y])
        {
            dyn[x][y]=1+rec(x,y-1);
            return dyn[x][y];
        }
        if (y-x<=1)
        {
            return 0;
        }
        if (chars[x]==chars[y-1])
        {
            dyn[x][y]=1+rec(x,y-2);
            return dyn[x][y];
        }
        if (chars[x+1]==chars[y])
        {
            dyn[x][y]=1+rec(x+1,y-1);
            return dyn[x][y];
        }
        if (chars[x]==chars[x+1])
        {
            dyn[x][y]=1+rec(x+1,y);
            return dyn[x][y];
        }
        if (chars[y-1]==chars[y])
        {
            dyn[x][y]=1+rec(x,y-1);
            return dyn[x][y];
        }
        if (chars[x]==chars[x+2])
        {
            dyn[x][y]=1+rec(x+2,y);
            return dyn[x][y];
        }
        if (chars[y-2]==chars[y])
        {
            dyn[x][y]=1+rec(x,y-2);
            return dyn[x][y];
        }
        int res = rec(x + 1, y);
        char c = chars[x];
        for (int i = x + 1; i <= y; i++)
        {
            if (chars[i] == c)
            {
                res = Math.max(res, 1 + rec(x + 1, i - 1) + rec(i, y));
                if (i==x+1)
                {
                    break;
                }
            }
        }
        dyn[x][y] = res;
        return res;
    }
    
    public int update()
    {
        int res=0;
        int cur=1;
        for (int i=1;i<n;i++)
        {
            if (chars[i]==chars[cur-1])
            {
                res++;
                continue;
            }
            if (cur>1 && chars[i]==chars[cur-2])
            {
                res++;
                cur--;
                continue;
            }
            chars[cur]=chars[i];
            cur++;
        }
        n=cur;
        return res;
    }

    public void solve()
    {
        n = chars.length;
        int res=3*n;
        res-=2*update();
        res-=2*((n-1)/3);
        //dyn = new int[n][n];
        //for (int i = 0; i < n; i++)
        //{
        //    Arrays.fill(dyn[i], -1);
        //}
        //ans = 3 * n - 2 * rec(0, n - 1);
        ans=res;
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
