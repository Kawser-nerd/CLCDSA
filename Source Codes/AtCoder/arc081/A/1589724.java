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
        HashMap<Long, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            long x = in.nextLong();
            if (map.get(x) != null) {
                map.put(x, map.get(x) + 1);
            } else map.put(x, 1);
        }
        ArrayList<Long> v = new ArrayList<>();
        for (Map.Entry<Long, Integer> entry : map.entrySet()) {
            if (entry.getValue() >= 4) {
                v.add(entry.getKey());
                v.add(entry.getKey());
            }
            else if (entry.getValue() > 1) {
                v.add(entry.getKey());
            }
        }
        if (v.size() > 1) {
            Collections.sort(v);
            out.println(v.get(v.size() - 1) * v.get(v.size() - 2));
        }
        else out.println(0);
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