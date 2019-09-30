import java.util.*;
import java.math.*;
import java.io.*;

public class Main2 implements Runnable {

    public static void main(String[] args) {
        new Thread(new Main2()).start();
    }

    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;
    boolean eof;
    
    
    public void run() {
        try {
            Locale.setDefault(Locale.US);
            br = new  BufferedReader(new FileReader("input.txt"));
            out = new PrintWriter("output.txt");
            solve();
            out.close();
        } catch (Throwable e) {
            e.printStackTrace();
            System.exit(-1);
        }
    }
    
    String nextToken() {
        while (st == null || !st.hasMoreElements()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (Exception e) {
                eof = true;
                return "0";
            }
        }
        return st.nextToken();
    }
    
    int nextInt() {
        return Integer.parseInt(nextToken());
    }
    
    long nextLong() {
    	return Long.parseLong(nextToken());
    }
    
  
    
    void solve() throws IOException {
        int N = nextInt();
        for (int tn = 1; tn <= N; tn++) {
        	int k = nextInt();
        	int[] a = new int[k];
        	
        	Tree T = new Tree(k);
        	        	
        	int p = 0;
        	int s = k;
        	for (int i = 0; i < k; i++) {
        		p = (p + i) % s;
        		int tp = T.get(p);
        		a[tp] = i;
        		T.set(tp, 0);
        		s--;
        	}
        	
        	out.print("Case #" + tn + ": ");
        	int n = nextInt();
        	for (int i = 0; i < n; i++) {
        		out.print((a[nextInt() - 1] + 1) + " ");
        	}
        	out.println();
        }
    }
    
    class Tree {
    	int[] x;
    	int m;
    	
    	public Tree(int n) {
    		m = 1;
    		while (m < n) m *= 2;
    		x = new int[2 * m];
    		for (int i = m; i < m + n; i++) {
    			x[i] = 1;
    		}
    		for (int i = m - 1; i >= 1; i--) {
    			x[i] = x[2 * i] + x[2 * i + 1];
    		}
    	}
    	
    	int get(int k) {
    		int i = 1;
    		while (i < m) {
    			if (x[2 * i] <= k) {
    				k -= x[2 * i];
    				i = 2 * i + 1;
    			} else {
    				i = 2 * i;
    			}
    		}
    		return i - m;
    	}
    	
    	void set(int i, int v) {
    		i += m;
    		x[i] = v;
    		i /= 2;
    		while (i >= 1) {
    			x[i] = x[2 * i] + x[2 * i + 1];
    			i /= 2;
    		}
    	}
    	
    }
    
}
