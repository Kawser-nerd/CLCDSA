import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main{
    static int n, w;
    static long[] vs;
    static long[] ws;
    static long ans;
    public static void main(String args[]) {
        FastReader sc = new FastReader();
        n = sc.nextInt();
        w = sc.nextInt();
        vs = new long[n];
        ws = new long[n];
        for (int i = 0; i < n; i++) {
            vs[i] = sc.nextLong();
            ws[i] = sc.nextLong();
        }
        ans = 0;
        if (true) {
            List<Integer> xs = new ArrayList<>();
            for (int i = 0; i < n; i++) xs.add(i);
            xs.sort((i, j) -> (vs[i] * ws[j] > vs[j] * ws[i]) ? -1 : 1);
            long[] tempVs = vs.clone();
            long[] tempWs = ws.clone();
            for (int i = 0; i < n ; i++) {
                vs[i] = tempVs[xs.get(i)];
                ws[i] = tempWs[xs.get(i)];
            }
            branchAndBound(0, 0, 0);
            System.out.println(ans);
        }
    }

    static void branchAndBound(int i, long currentValue, long currentWeight) {
        if (w < currentWeight) return;
        if (i == n) {
            ans = Math.max(ans, currentValue);
            return;
        }
        long linearValue = currentValue;
        long linearWeight = currentWeight;
        int j;
        for (j = i; j < n && linearWeight + ws[j] <= w; j++) {
            linearWeight += ws[j];
            linearValue += vs[j];
        }
        if (linearWeight == w || j == n) {
            ans = Math.max(ans, linearValue);
            return;
        }
        double linearAns = linearValue + vs[j] * ((w - linearWeight) / (double)ws[j]);
        if (linearAns <= ans) return;
        branchAndBound(i + 1, currentValue + vs[i],
                currentWeight + ws[i]);
        branchAndBound(i + 1, currentValue, currentWeight);
    }

    static class FastReader
    {
        BufferedReader br;
        StringTokenizer st;

        public FastReader()
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
                catch (IOException e)
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
}