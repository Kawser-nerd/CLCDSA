import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;



public class Main {
	public static void main(String[] args){
		FastReader sc = new FastReader();
		// ?????
		int N=sc.nextInt();
		double[] x= new double[N];
		double sum=0;
		String [] u= new String[N];
		for (int i = 0; i < u.length; i++) {
			x[i]=sc.nextDouble();
			u[i]=sc.next();
		}
		for (int i = 0; i < u.length; i++) {
			if (u[i].equals("JPY")) {
				sum+=x[i];
			}
			else  {
				sum+=x[i]*380000.0;
			}
		}
		PrintWriter out = new PrintWriter(System.out);
		out.print(sum);
		out.flush();
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