import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    int n, k, q;
    int[] as;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        n = sc.nextInt();
        k = sc.nextInt();
        q = sc.nextInt();
        as = new int[n];
        for (int i = 0; i < n; i++) {
            as[i] = sc.nextInt();
        }
        solve();
    }

    void solve() {
        int[] bs = as.clone();
        Arrays.sort(bs);
        int prevMin = -1;
        int diff = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            int minNum = bs[i];
            if (prevMin == minNum) {
                prevMin = minNum;
                continue;
            }
            prevMin = minNum;
            int l = 0;
            List<Integer> candidates = new ArrayList<>();
            PriorityQueue<Integer> pQueue = new PriorityQueue<>();
            for (int j = 0; j <= n; j++) {
                if (j == n || as[j] < minNum) {
                    if (j - l >= k) {
                        PriorityQueue<Integer> tempQueue = new PriorityQueue<>();
                        for (int m = l; m < j; m++) {
                            tempQueue.offer(as[m]);
                        }
                        for (int m = 0; m < j - l - k + 1; m++) {
                            candidates.add(tempQueue.poll());
                        }
                    }
                    l = j + 1;
                }
            }
            if (candidates.size() < q) {
                continue;
            }
            Collections.sort(candidates);
            int tempDiff = candidates.get(q - 1) - candidates.get(0);
            if (tempDiff < diff) {
                diff = tempDiff;
            }
        }
        System.out.println(diff);
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