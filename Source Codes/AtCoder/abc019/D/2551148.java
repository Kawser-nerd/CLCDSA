import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    int n;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        n = sc.nextInt();
        int max = 0;
        int maxIndex = 1;
        for (int i = 2; i <= n; i++) {
            System.out.println("? 1 " + i);
            int temp = sc.nextInt();
            if (max < temp) {
                max = temp;
                maxIndex = i;
            }
        }
        int distance = 0;
        for (int i = 1; i <= n; i++) {
            if (i == maxIndex) {
                continue;
            }
            System.out.printf("? %d %d\n", maxIndex, i);
            int temp = sc.nextInt();
            if (distance < temp) {
                distance = temp;
            }
        }
        System.out.println("! " + distance);
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