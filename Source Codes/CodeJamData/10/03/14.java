import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class ThemePark {
	public static void main(String[] args)throws IOException {
		// Use BufferedReader rather than RandomAccessFile; it's much faster
	    BufferedReader f = new BufferedReader(new FileReader("C-large.in"));
	                                                  // input file name goes above
	    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("C-large.out")));
	    // Use StringTokenizer vs. readLine/split -- lots faster
	    StringTokenizer st = new StringTokenizer(f.readLine());
							  // Get line, break into tokens
	    int t = Integer.parseInt(st.nextToken());    // first integer
	    for (int i = 0; i < t; i++) {
			st=new StringTokenizer(f.readLine());
			int r=Integer.parseInt(st.nextToken());
			int k=Integer.parseInt(st.nextToken());
			int n=Integer.parseInt(st.nextToken());
			st=new StringTokenizer(f.readLine());
			int[]g=new int[n];
			int[]begin=new int[n];
			long[]money=new long[n];
			Arrays.fill(begin, -1);
			for (int j = 0; j < n; j++) {
				g[j]=Integer.parseInt(st.nextToken());
			}
			int cur=0;
			int end=-1;
			long res=0;
			for (int j = 0; j < r; j++) {
				if(begin[cur]!=-1){
					end=j;break;
				}
				int x=0;
				int next=cur;
				int l=0;
				while(x+g[next]<=k&&l<n)
				{
					x+=g[next];
					next++;
					next%=n;
					l++;
				}
				begin[cur]=j;
				money[cur]=res;
				res+=x;
				cur=next;
			}
			if(end!=-1)
			{
				int disr=end-begin[cur];
				long dism=res-money[cur];
				int ti=(r-begin[cur])/disr;
				end=ti*disr+begin[cur];
				res=ti*dism+money[cur];
				for (int j = end; j < r; j++) {
					int x=0;
					int next=cur;
					int l=0;
					while(x+g[next]<=k&&l<n)
					{
						x+=g[next];
						next++;
						next%=n;
						l++;
					}
					res+=x;
					cur=next;
				}
			}
			out.println("Case #"+(i+1)+": "+res);
		}                       
	    out.close();                                  // close the output file
	    System.exit(0);                               // don't omit this!
	}
}
