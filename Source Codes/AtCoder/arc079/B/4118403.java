/*
 *  solution very similar to editorial
 */
import java.io.*;
import java.util.*;

public class Main{


	public static void main(String[] args) throws IOException {
		Scanner sc=new Scanner();
		PrintWriter out=new PrintWriter(System.out);
		long k=sc.nextLong();
		int n=50;
		long x=k/n;
		long []a=new long [n];
		for(int i=0;i<n;i++)
			a[i]=i+x;
		int rem=(int) (k%n);
		for(int i=0;i<rem;i++) {
			a[i]+=n;
			for(int j=0;j<n;j++)
				if(j!=i)
					a[j]--;
			
		}
		out.println(n);
		for(long z:a)
			out.print(z+" ");

		out.close();
	}
	
	static class Scanner
	{
		BufferedReader br;
		StringTokenizer st;
		Scanner(){
			br=new BufferedReader(new InputStreamReader(System.in));
		}
		Scanner(String fileName) throws FileNotFoundException{
			br=new BufferedReader(new FileReader(fileName));
		}
		String next() throws IOException {
			while(st==null || !st.hasMoreTokens())
				st=new StringTokenizer(br.readLine());
			return st.nextToken();
		}
		String nextLine() throws IOException {
			return br.readLine();
		}
		int nextInt() throws IOException{
			return Integer.parseInt(next());
		}
		long nextLong()  throws NumberFormatException, IOException {
			return Long.parseLong(next());
		}
		double nextDouble() throws NumberFormatException, IOException {
			return Double.parseDouble(next());
		}
	}
	
}