import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    int n;
    int[] as;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        n = sc.nextInt();
        as = new int[n];
        for (int i = 0; i < n; i++) {
            as[i] = sc.nextInt();
        }
        solve();
    }

    void solve() {
        ArrayList<Integer> xList = new ArrayList<>();
        ArrayList<Integer> yList = new ArrayList<>();
        int maxAbs = 0;
        int maxAbsIndex = -1;
        for (int i = 0; i < n; i++) {
            if (Math.abs(as[i]) > Math.abs(maxAbs)) {
                maxAbs = as[i];
                maxAbsIndex = i;
            }
        }
        if (maxAbs == 0) {
            System.out.println(0);
            return;
        }
        for (int i = 0; i < n; i++) {
            xList.add(maxAbsIndex + 1);
            yList.add(i + 1);
        }
        if (maxAbs < 0) {
            for (int i = n - 1; i > 0; i--) {
                xList.add(i + 1);
                yList.add(i);
            }
        } else {
            for (int i = 0; i < n - 1; i++) {
                xList.add(i + 1);
                yList.add(i + 2);
            }
        }
        System.out.println(xList.size());
        for (int i = 0; i < xList.size(); i++) {
            System.out.println(xList.get(i) + " " + yList.get(i));
        }
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next() {
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

        String nextLine() {
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