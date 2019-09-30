import java.io.*;
import java.util.*;

public class Main {

	static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            try {
                br = new BufferedReader(new InputStreamReader(System.in));
                st = new StringTokenizer(br.readLine());
            } catch (Exception e){e.printStackTrace();}
        }

        public String next() {
            if (st.hasMoreTokens()) return st.nextToken();
            try {st = new StringTokenizer(br.readLine());}
            catch (Exception e) {e.printStackTrace();}
            return st.nextToken();
        }

        public int nextInt() {return Integer.parseInt(next());}

        public long nextLong() {return Long.parseLong(next());}

        public double nextDouble() {return Double.parseDouble(next());}

        public String nextLine() {
            String line = "";
            if(st.hasMoreTokens()) line = st.nextToken();
            else try {return br.readLine();}catch(IOException e){e.printStackTrace();}
            while(st.hasMoreTokens()) line += " "+st.nextToken();
            return line;
        }
    }

    static class DSU {
        int[] root;
        int[] rank;

        public DSU(int n) {
            root = new int[n];
            rank = new int[n];
            for(int i=0;i<n;i++) {
                root[i] = i;
            }
        }

        public int find(int x) {
            if(root[x] == x) {
                return x;
            }
            else {
                return find(root[x]);
            }
        }

        public void unite(int x, int y) {
            x = find(x);
            y = find(y);
            if(x == y) {
                return;
            }
            if(rank[x] < rank[y]) {
                root[x] = y;
            }
            else {
                root[y] = x;
                if(rank[x] == rank[y]) {
                    rank[x]++;
                }
            }
        }

        public boolean same(int x, int y) {
            return find(x) == find(y);
        }
    }

	public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        PrintWriter pw = new PrintWriter(System.out);

        int n = sc.nextInt(), k = sc.nextInt(), l = sc.nextInt();

        DSU dsu1 = new DSU(n);
        DSU dsu2 = new DSU(n);

        for(int i=0;i<k;i++) {
            int a = sc.nextInt() - 1;
            int b = sc.nextInt() - 1;
            dsu1.unite(a, b);
        }
        for(int i=0;i<l;i++) {
            int a = sc.nextInt() - 1;
            int b = sc.nextInt() - 1;
            dsu2.unite(a, b);
        }

        HashMap<Long, Integer> map = new HashMap<>();
        long[] arr = new long[n];

        for(int i=0;i<n;i++) {
            long a = dsu1.find(i);
            long b = dsu2.find(i);
            arr[i] = a * (long)n + b;

            if(map.containsKey(arr[i])) {
                map.put(arr[i], map.get(arr[i]) + 1);
            }
            else {
                map.put(arr[i], 1);
            }
        }

        StringBuilder sb = new StringBuilder();
        for(int i=0;i<n;i++) {
            sb.append(map.get(arr[i]) + " ");
        }

        pw.println(sb+"".trim());

        pw.close();
	}

}

// dream, dreamer, erase, eraser