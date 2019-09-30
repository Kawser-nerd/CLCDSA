import java.util.*;
import java.math.*;
import java.io.*;

public class Main implements Runnable {

    public static void main(String[] args) {
        new Thread(new Main()).start();
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
    
    long cnk(long n, long k) {
    	long ans = 1;
    	for (int i = 0; i < k; i++) {
    		ans *= (n - i);
    	}
    	for (int i = 1; i <= k; i++) {
    		ans /= i;
    	}
    	return ans;
    }
    
    
    int[] par;
    int[] r;
    
    int get(int i) {
    	if (par[i] != i) {
    		par[i] = get(par[i]);
    	}
    	return par[i];
    }
    
    void union(int i, int j) {
    	i = get(i);
    	j = get(j);
    	if (i == j) return;
    	if (r[i] == r[j]) r[i]++;
    	if (r[i] > r[j]) {
    		par[j] = i;
    	}
    	if (r[i] < r[j]) {
    		par[i] = j;
    	}
    }
    
    
    void solve() throws IOException {
        int N = nextInt();
        
        boolean[] ip = new boolean[1000010];
        Arrays.fill(ip, true);
        ip[1] = false;
        for (int i = 2; i < ip.length; i++) {
        	if (ip[i]) {
        		int j = 2 * i;
        		while (j < ip.length) {
        			ip[j] = false;
        			j += i;
        		}
        	}
        }
        
        
        for (int tn = 1; tn <= N; tn++) {
            long a = nextLong();
            long b = nextLong();
            long p = nextLong();
            int n = (int)(b - a + 1L);
            long ans = 0;
            if (p >= n) {
            	ans = n;
            } else {
            	par = new int[n];
            	for (int i = 0; i < n; i++) {
            		par[i] = i;
            	}
            	r = new int[n];
            	for (long i = p; i < n; i++) {
            		if (!ip[(int)i]) continue;
            		long j = ((a + i - 1) / i) * i;
            		j += i;
            		while (j <= b) {
            			int z = (int)(j - a - i);
            			int x = (int)(j - a);
            			union(z, x);
            			j += i;
            		}
            	}
            	
            	boolean[] u = new boolean[n];
            	
            	for (int i = 0; i < n; i++) {
            		if (!u[get(i)]) {
            			u[get(i)] = true;
            			ans++;
            		}
            	}
            }
            out.println("Case #" + tn + ": " + ans);
        }
    }
    
}
