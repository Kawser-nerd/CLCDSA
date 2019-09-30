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
		int M=sc.nextInt();
		long[][] A=new long[N][2];
		int k=0;
		int number=0;
		long sum=0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 2; j++) {
				A[i][j]=sc.nextInt();
			}
		}
		Arrays.sort(A, (a, b) -> Long.compare(a[0], b[0]));
		while(M>k) {
			k+=A[number][1];
			sum+=A[number][0]*A[number][1];
			number++;
		}
		if (k!=M) {
			sum-=A[number-1][0]*(k-M);
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