import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    int n;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        n = sc.nextInt();
        SortedMap<Integer, Integer> counts = new TreeMap<>(Collections.reverseOrder());
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            if (!counts.containsKey(a)) {
                counts.put(a, 1);
            } else {
                counts.put(a, counts.get(a) + 1);
            }
        }
        int first = 0;
        int second = 0;
        for (Map.Entry<Integer, Integer> entry : counts.entrySet()) {
            int value = entry.getValue();
            if (value >= 4) {
                if (first == 0) {
                    first = entry.getKey();
                }
                second = entry.getKey();
                break;
            } else if (value >= 2) {
                if (first == 0) {
                    first = entry.getKey();
                } else {
                    second = entry.getKey();
                    break;
                }
            }
        }
        System.out.println((long)first * second);
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