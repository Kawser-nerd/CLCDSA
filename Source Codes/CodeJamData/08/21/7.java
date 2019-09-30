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
    
    void solve() throws IOException {
        int N = nextInt();
        for (int tn = 1; tn <= N; tn++) {
            long n = nextInt();
            long A = nextLong();
            long B = nextLong();
            long C = nextLong();
            long D = nextLong();
            long x0 = nextLong();
            long y0 = nextLong();
            long M = nextLong();
            
            int[][] c = new int[3][3];
            for (int i = 0; i < n; i++) {
            	c[(int)(x0 % 3)][(int)(y0 % 3)]++;
            	x0 = (A * x0 + B) % M;
            	y0 = (C * y0 + D) % M;
            }
            
            long ans = 0;
            
            for (int i = 0; i < 9; i++) {
            	for (int j = i; j < 9; j++) {
            		for (int k = j; k < 9; k++) {
            			if ((i / 3 + j / 3 + k / 3) % 3 == 0 && (((i % 3) + (j % 3) + (k % 3)) % 3 == 0)) {
            				int[][] w = new int[3][3];
            				w[i / 3][i % 3]++;
            				w[j / 3][j % 3]++;
            				w[k / 3][k % 3]++;
            				long tans = 1;
            				for (int s = 0; s < 3; s++) {
            					for (int h = 0; h < 3; h++) {
            						tans *= cnk(c[s][h], w[s][h]);
            					}
            				}
            				ans += tans;
            			}
            		}
            	}
            }
            
            out.println("Case #" + tn + ": " + ans);
        }
    }
    
}
