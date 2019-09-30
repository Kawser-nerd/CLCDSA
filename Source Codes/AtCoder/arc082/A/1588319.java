import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        InputReader in = new InputReader();
        PrintWriter out = new PrintWriter(System.out);
        int test_cases = 1;
        Solver s = new Solver();
        for (int i = 1; i <= test_cases; i++) {
            s.solve(i, in, out);
        }
        out.close();
    }
}

class Solver {
    void solve(int test_number, InputReader in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        int[] a = new int[n];
        int[] freq = new int[(int) (1e5 + 7)];
        for (int i = 0; i < a.length; i++) {
            a[i] = in.nextInt();
            freq[a[i]]++;
        }
        int max = 0;
        for (int i = 0; i < freq.length; i++) {
            int i1 = freq[i];
            if (i1 > 0) {
                max = Math.max(i1 + (i - 1 >= 0 ? freq[i - 1] : 0) + (i + 1 < freq.length ? freq[i + 1] : 0), max);
            }
        }
        out.println(max);
    }
}


class InputReader {
    BufferedReader br;
    StringTokenizer st;

    public InputReader()
    {
        br = new BufferedReader(new
                InputStreamReader(System.in));
    }

    String next()
    {
        while (st == null || !st.hasMoreElements())
        {
            try
            {
                st = new StringTokenizer(br.readLine());
            }
            catch (IOException  e)
            {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }

    int nextInt()
    {
        return Integer.parseInt(next());
    }

    long nextLong()
    {
        return Long.parseLong(next());
    }

    double nextDouble()
    {
        return Double.parseDouble(next());
    }

    String nextLine()
    {
        String str = "";
        try
        {
            str = br.readLine();
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
        return str;
    }
}