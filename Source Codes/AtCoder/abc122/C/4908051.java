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
		int Q=sc.nextInt();
		String S=sc.next();
		int[] l=new int[Q];
		int[] r=new int[Q];
		for (int i = 0; i < r.length; i++) {
			l[i]=sc.nextInt();
			r[i]=sc.nextInt();
		}
		int[] max=new int[N+1];
		for (int i = 0; i < max.length; i++) {
			max[i]=0;
		}
		for (int j = 1; j<N; j++) {
				if (S.startsWith("AC",j-1)) {
					max[j+1]=max[j]+1;
				}
				else {
					max[j+1]=max[j];
				}
			}
		
		PrintWriter out = new PrintWriter(System.out);
		for(int i=0;i<Q;i++) {
		    out.println(max[r[i]]-max[l[i]]);
		}
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