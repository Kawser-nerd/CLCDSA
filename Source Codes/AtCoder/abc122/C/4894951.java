import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
 
public class Main {
 
	public static void main(String[] args) {
		FastReader scan = new FastReader();
		PrintWriter out = new PrintWriter(System.out);
		int n = scan.nextInt(), q = scan.nextInt();
		int[] p = new int[n+1];
		char prev = 'z';
		char[] a = scan.next().toCharArray();
		for(int i = 1; i <= n; i++) {
			if(a[i-1] == 'C' && prev == 'A') p[i]++;
			p[i] += p[i-1];
			prev = a[i-1];
		}
		for(int i = 0; i < q; i++) {
			int l = scan.nextInt() - 1, r = scan.nextInt();
			int get = p[r] - p[l];
			if(l > 0 && a[l] == 'C' && a[l-1] == 'A') get--;
			out.println(get);
		}
		out.close();
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
                catch (IOException  e) 
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