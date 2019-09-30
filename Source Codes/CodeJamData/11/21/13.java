import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;


public class GCJA {
	public static void write(String filename, String content) throws IOException
	{
		BufferedWriter out = new BufferedWriter( new FileWriter(filename));
		out.write( content );
		out.close();
	}
	
	public void solve() throws IOException
	{
		Scanner cin = new Scanner( new File("input/A-large.in"));;
		int T = cin.nextInt();
		String ans = "";
		for(int cas=1;cas<=T;cas++)
		{
			int N = cin.nextInt();
			String []sch = new String[N];
			for(int i=0;i<N;i++)
				sch[i] = cin.next();
			ans += "Case #" + cas + ":\n";
			double [] wp = new double[N];
			double [] owp = new double[N];
			double [] oowp = new double[N];
			for(int i=0;i<N;i++)
				wp[i] = owp[i] = oowp[i] = 0;
			for(int i=0;i<N;i++)
			{
				int w = 0;
				int l = 0;
				for(int j=0;j<N;j++)
				{
					if( sch[i].charAt(j)=='1')
						w++;
					else if( sch[i].charAt(j)=='0')
						l++;
				}
				wp[i] = w/(w+l+0.0);
				int op = 0;
				
				for(int j=0;j<N;j++)
				{
					if( sch[i].charAt(j)!='.' )
					{
						op++;
						int wj = 0;
						int lj = 0;
						for(int k=0;k<N;k++)
						{
							if( k==i )
								continue;
							if( sch[j].charAt(k)=='1' )
								wj++;
							if( sch[j].charAt(k)=='0' )
								lj++;
						}
						if( wj+lj==0 )
							op--;
						else
							owp[i] += wj/(wj+lj+0.0);
					}
				}
				owp[i] = owp[i]/op;
			}
			for(int i=0;i<N;i++)
			{
				int oop = 0;
				for(int j=0;j<N;j++)
					if( sch[i].charAt(j)!='.' )
					{
						oop++;
						oowp[i] += owp[j];
					}
				oowp[i] /= oop;	
			}
			for(int i=0;i<N;i++)
				ans += (0.25*wp[i] + 0.5*owp[i] + 0.25*oowp[i]) + "\n";
		}
		System.out.println(ans);
		GCJA.write("outputA.txt",ans);
	}
	private int gcd(int a, int b) {
		if( a==0 )
			return b;
		if( b%a==0 )
			return a;
		return gcd( b%a, a);
	}

	public static void main(String[] arg) throws IOException{
		GCJA A = new GCJA();
		A.solve();
	}
}
