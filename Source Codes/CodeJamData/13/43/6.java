import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class C {

	void solve() throws IOException {
		int t=nextInt();
		for(int testCase=0;testCase<t;testCase++){
			int n=nextInt();
			int[] a=new int[n];
			int[] b=new int[n];
			for(int i=0;i<n;i++)
				a[i]=nextInt();
			for(int i=0;i<n;i++)
				b[i]=nextInt();
			HashSet<Integer>[] g=new HashSet[n];
			for(int i=0;i<n;i++)
				g[i]=new HashSet<Integer>();
			for(int i=1;i<n;i++){
				if(a[i]==1){
					for(int j=0;j<i;j++)
						g[i].add(j);
				}
				else{
					for(int j=0;j<i;j++)
						if(a[i]<=a[j])
							g[i].add(j);
					for(int j=i-1;j>=0;j--)
						if(a[i]==a[j]+1){
							g[j].add(i);
							break;
						}
				}
			}
			for(int i=n-2;i>=0;i--){
				if(b[i]==1){
					for(int j=i+1;j<n;j++)
						g[i].add(j);
				}
				else{
					for(int j=i+1;j<n;j++)
						if(b[i]<=b[j])
							g[i].add(j);
					for(int j=i+1;j<n;j++){
						if(b[i]==b[j]+1){
							g[j].add(i);
							break;
						}
					}
				}
			}
			int[] result=new int[n];
			boolean[] used=new boolean[n];
			for(int k=0;k<n;k++){
				for(int i=n-1;i>=0;i--)
					if(g[i].size()==0&&!used[i]){
						used[i]=true;
						result[i]=n-k;
						for(int j=0;j<n;j++)
							g[j].remove(i);
						break;
					}
			}
			out.printf("Case #%d:",testCase+1);
			for(int i=0;i<n;i++){
				out.print(" "+result[i]);
			}
			out.println();
		}
	}

	public static void main(String[] args) throws IOException {
		new C().run();
	}

	void run() throws IOException {
//		reader = new BufferedReader(new InputStreamReader(System.in));
//
//		out = new PrintWriter(new OutputStreamWriter(System.out));

		reader = new BufferedReader(new FileReader("input.txt"));

		out = new PrintWriter(new FileWriter("output.txt"));
		tokenizer = null;
		solve();
		reader.close();
		out.flush();

	}

	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter out;

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}
}
