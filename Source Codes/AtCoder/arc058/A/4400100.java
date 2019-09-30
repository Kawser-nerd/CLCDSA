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

    public static boolean ok(int a, String s) {
        String temp = "" + a;
        for(int i=0;i<s.length();i++) {
            if(temp.indexOf(s.charAt(i)) != -1) {
                return false;
            }
        }
        return true;
    }

	public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        PrintWriter pw = new PrintWriter(System.out);

        int n = sc.nextInt();
        int k = sc.nextInt();
        String s = "";

        for(int i=0;i<k;i++) {
            s += sc.next();
        }

        while(!ok(n, s)) {
            n++;
        }

        pw.println(n);
        pw.close();
	}

}