import java.util.*;
import java.io.*;
class Main {

	
	
	public static void main(String[] args) throws IOException {
		Scanner sc=new Scanner(System.in);
		PrintWriter pw=new PrintWriter(System.out);
		int n=sc.nextInt(),k=sc.nextInt();
		int []a=new int [n];
		int idx=0;
		for(int i=0;i<n;i++)
		{
			a[i]=sc.nextInt();
			if(a[i]==1)
				idx=i;
		}
		int ans=n;
		int x=k-1;
		for(int i=Math.max(idx-k, 1)-1;i<Math.min(idx+k, n);i++)
		{
			int curr=1+(i+x-1)/x;
			int tmp=n-(i+k);
			curr+=(tmp+x-1)/x;
			ans=Math.min(ans, curr);
		}
		pw.println(ans);
		pw.close();
	}
	
	static class Scanner {
        StringTokenizer st;
        BufferedReader br;
 
        public Scanner(InputStream s) {
            br = new BufferedReader(new InputStreamReader(s));
        }
 
        public Scanner(FileReader s) {
            br = new BufferedReader(s);
        }
 
        public String next() throws IOException {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }
 
        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
 
        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }
 
        public String nextLine() throws IOException {
            return br.readLine();
        }
        public boolean ready() throws IOException {return br.ready();}
        public double nextDouble() throws IOException {return Double.parseDouble(next());}
       
    }

}