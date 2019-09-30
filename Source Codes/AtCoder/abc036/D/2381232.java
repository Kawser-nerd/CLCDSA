import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static List<List<Integer>> correctedGraph;
    static long[] score, memoF, memoG;
    static int[] depth;
    static int depthCount;
    static long MOD = 1000000007;
    public static void main(String args[]) {
        FastReader sc = new FastReader();
        int n = sc.nextInt();
        List<List<Integer>> graph = new ArrayList<>();
        correctedGraph = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            graph.add(new LinkedList<>());
            correctedGraph.add(new LinkedList<>());
        }
        for (int i = 1 ; i < n; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            graph.get(a).add(b);
            graph.get(b).add(a);
        }
        score = new long[n + 1];
        memoF = new long[n + 1];
        memoG = new long[n + 1];

        depth = new int[n + 1];
        depth[1] = 1;
        depthCount = 1;
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(1);
        while(!queue.isEmpty()) {
            int next = queue.poll();
            List<Integer> node = graph.get(next);
            for (int j : node) {
                if (depth[j] == 0) {
                    depth[j] = depth[next] + 1;
                    if (depthCount < depth[j]) depthCount = depth[j];
                    queue.offer(j);
                    correctedGraph.get(next).add(j);
                }
            }
        }

        System.out.println(f(1));
    }

    static long f(int i) {
        if (memoF[i] > 0) return memoF[i];
        if (depth[i] == depthCount) {
            memoF[i] = 2;
            return 2;
        }
        long ans = 1;
        for (int adj : correctedGraph.get(i)) {
            ans *= g(adj);
            ans %= MOD;
        }
        ans += g(i);
        ans %= MOD;
        memoF[i] = ans;
        return ans;
    }

    static long g(int i) {
        if (memoG[i] > 0) return memoG[i];
        if (depth[i] == depthCount) {
            memoG[i] = 1;
            return 1;
        }
        long ans = 1;
        for (int adj : correctedGraph.get(i)) {
            ans *= f(adj);
            ans %= MOD;
        }
        memoG[i] = ans;
        return ans;
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