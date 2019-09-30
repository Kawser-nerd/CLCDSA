import java.io.*;
import java.util.*;


public class Main{


	
	public static void main(String[] args) throws IOException {
		Scanner sc=new Scanner();
		PrintWriter out=new PrintWriter(System.out);
		long K = sc.nextLong();
		int rest = (int)(K % 50);
		long num = K / 50;
		System.out.println(50);
		long[] ans = new long[50];
		for (int i = 0; i < rest; i++) {
			ans[i] = num + 50  + 50 - rest;
		}
		for (int i = rest; i < 50; i++) {
			ans[i] = num + 50 - 1 - rest;
		}
		for (int i = 0; i < 49; i++) {
			System.out.print(ans[i] + " ");
		}
		System.out.println(ans[49]);
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