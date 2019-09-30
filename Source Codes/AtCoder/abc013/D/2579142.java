import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    int n, m, d;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        n = sc.nextInt();
        m = sc.nextInt();
        d = sc.nextInt();
        int[] amida = new int[n];
        for (int i = 0; i < n; i++) {
            amida[i] = i;
        }
        for (int i = 0; i < m; i++) {
            int a = sc.nextInt();
            int temp = amida[a - 1];
            amida[a - 1] = amida[a];
            amida[a] = temp;
        }
        int[] cycle = new int[n];
        int[] res = new int[n];
        boolean[] visited = new boolean[n];
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int index = 0;
                int k = i;
                while (!visited[k]) {
                    cycle[index++] = k;
                    visited[k] = true;
                    k = amida[k];
                }
                for (int j = 0; j < index; j++) {
                    res[cycle[j]] = cycle[(j + d) % index];
                }
            }
        }
        for (int i = 0; i < n; i++) {
            cycle[i] = res[i];
        }
        for (int i = 0; i < n; i++) {
            res[cycle[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            System.out.println(res[i] + 1);
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