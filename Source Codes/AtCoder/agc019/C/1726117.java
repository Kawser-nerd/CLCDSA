import java.util.*;
import java.io.*;

public class Main {
    public static void main(String [] args) {	
    	Solver s = new Solver();
    }
    static class Solver { 
		ArrayList <Integer> arr;
		int [] dp = new int [1000010];
		
		int search(int b, int e, int val) {
			if(b == e) {
				return b;
			}
			int m = (b + e + 1) >> 1;
			if(dp[m] < val) return search(m, e, val);
			else return search(b, m-1, val);
		}
		
		Solver() {
		    Reader in = new Reader ();
		    Writer out = new Writer ();
			
			final double PI = Math.acos(-1.0);	
				
			int a = in.nextInt();
			int b = in.nextInt();
			int c = in.nextInt();
			int d = in.nextInt();
		
			int n = in.nextInt();
			int [] x = new int [n];
			int [] y = new int [n];
			for(int i = 0; i < n; i++) {
				x[i] = in.nextInt();
				y[i] = in.nextInt();
			}
			double ans = 100.00 * (Math.abs(a - c) + Math.abs(b - d));
			
			if(a > c) {
				int temp = b;
				b = d;
				d = temp;
				temp = a;
				a = c;
				c = temp;
			}
			ArrayList <Pair> rel = new ArrayList <> ();
			for(int i = 0; i < n; i++) {
				if(a <= x[i] && x[i] <= c) {
					if(Math.min(b, d) <= y[i] && y[i] <= Math.max(b, d)) {
						rel.add(new Pair(x[i], y[i]));
					}
				}
			}
			Collections.sort(rel, new Pair());
			arr = new ArrayList <> ();
			for(Pair i : rel) {
				int var;
				if(b < d) var = i.second - b;
				else var = d - i.second;
				arr.add(var);
			}
			for(int i = 0; i <= arr.size(); i++) dp[i] = Integer.MAX_VALUE;
			dp[0] = -1;
			
			int lcs = 0;
			for(int i = 0; i < arr.size(); i++) {
				int opt = search(0, i, arr.get(i)) + 1;
				dp[opt] = Math.min(dp[opt], arr.get(i));
				lcs = Math.max(lcs, opt);
			} 
			ans += 10.0 * lcs * ((PI / 2.0) - 2);
			if(lcs == Math.min(Math.abs(a - c), Math.abs(b - d)) + 1) {
				ans += 10.0 * (PI / 2.0);
			}
			System.out.printf("%.15f\n", ans);
		}
    }
    static class Reader {
        private StringTokenizer a;
        private BufferedReader b;
        Reader () {
            a = null;
            b = new BufferedReader (new InputStreamReader (System.in));
        }
        public String next () {
            while(a == null || !a.hasMoreTokens()) {
                try {
                    a = new StringTokenizer (b.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return a.nextToken();
        }
        public int nextInt() {
            return Integer.parseInt(this.next());
        }
        public long nextLong () {
            return Long.parseLong(this.next());
        }
        public double nextDouble () {
            return Double.parseDouble(this.next());
        }
        public String nextLine() {
            try {
                return b.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return "";
        }
    }
    static class Writer {
        private PrintWriter a;
        private StringBuffer b;
        Writer () {
            a = new PrintWriter (System.out);
            b = new StringBuffer ("");
        }
        public void write (Object s) {
            b.append(s);
        }
        public void writeln(Object s) {
            b.append(s).append('\n');
        }
        public void flush () {
            a.print(b);
            a.flush();
            a.close();
        }
    }
    static class Pair implements Comparator <Pair> {
        int first;
        int second;
        Pair  (int a, int b) {
            this.first = a;
            this.second = b;
        }
        Pair (Pair a) {
            this.first = a.first;
            this.second = a.second;
        } 
        Pair () {}
        public String toString () {
            return "[" + first + ", " + second + "]";
        }
        public int compare (Pair a, Pair b) {
            if(a.first == b.first) {
                return a.second - b.second;
            } else {
                return a.first - b.first;
            }
        }
    } 
}