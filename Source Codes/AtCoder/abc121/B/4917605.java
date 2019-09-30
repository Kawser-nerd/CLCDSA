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
		int c=sc.nextInt();
		int[] B=new int[M];
		int[][] A=new int[N][M];
		int[] sum=new int[N];
		int k=0;
		for (int i = 0; i < B.length; i++) {
			B[i]=sc.nextInt();
		}
		for (int i = 0; i < sum.length; i++) {
			sum[i]=0;
		}
		for (int i = 0; i <N; i++) {
			for (int j = 0; j < M; j++) {
				A[i][j]=sc.nextInt();
			}
		}
		for (int i = 0; i < sum.length; i++) {
			for (int j = 0; j < M; j++) {
				sum[i]+=A[i][j]*B[j];
			}
			sum[i]+=c;
		}
		PrintWriter out = new PrintWriter(System.out);
		for(int i=0;i<N;i++) {
		    if (sum[i]>0) {
				k++;
			}
		}
		System.out.println(k);
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