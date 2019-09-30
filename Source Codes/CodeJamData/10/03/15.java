import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * @author Igor Kirov
 */
public class C
{
    Scanner in;
    PrintWriter out;

    private int[] getNext(int[] a, int i, int k, int n)
    {
        int[] result = new int[2];
        int sum = 0;
        int start = i;
        while (sum + a[i] <= k)
        {
            sum += a[i];
            i = (i + 1) % n;
            if (i == start)
            {
                break;
            }
        }
        result[0] = i;
        result[1] = sum;
        return result;
    }

    private void run() throws Exception
    {
        in = new Scanner(new FileInputStream(new File("C.in")));
        out = new PrintWriter(new FileOutputStream(new File("C.out")));

        int t = in.nextInt();

        for (int i = 0; i < t; i++)
        {
            int r = in.nextInt();
            int k = in.nextInt();
            int n = in.nextInt();
            int[] a = new int[n + 2];
            int[] next = new int[n + 2];
            int[] count = new int[n + 2];
            boolean[] cycled = new boolean[n + 2];
            for (int j = 0; j < n; j++)
            {
                a[j] = in.nextInt();
            }

            for (int j = 0; j < n; j++)
            {
                int[] temp = getNext(a, j, k, n);
                next[j] = temp[0];
                count[j] = temp[1];
            }
            int cur = 0;
            long[] costs = new long[n + 2];
            int j = 1;
            boolean[] visited = new boolean[n];
            while (!visited[cur])
            {
                visited[cur] = true;
                costs[j] = costs[j - 1] + count[cur];
                cur = next[cur];
                j++;
            }

            int cycle = cur;
            while (!cycled[cycle])
            {
                cycled[cycle] = true;
                cycle = next[cur];
            }

            int starter = 0;
            int curcur = 0;
            while (!cycled[curcur])
            {
                curcur = next[curcur];
                starter++;
            }

            long result = 0;

            if (r >= starter)
            {
                result += costs[starter];
                result += (long) ((r - starter) / (j - 1 - starter)) * (long) (costs[j - 1] - costs[starter]) + (long) (costs[starter + (r - starter) % (j - starter - 1)] - costs[starter]);
            }
            else
            {
                result += costs[r];
            }

            out.println("Case #" + (i + 1) + ": " + result);
        }

        out.close();
    }

    public static void main(String[] args) throws Exception
    {
        new C().run();
    }
}