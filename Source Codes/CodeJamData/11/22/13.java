import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;


public class GCJB {
	class Word {
		String s;
		int ind;
	}
	public static void write(String filename, String content) throws IOException
	{
		BufferedWriter out = new BufferedWriter( new FileWriter(filename));
		out.write( content );
		out.close();
	}


	int c;
	long d ;
	long [] p;
	int [] v;
	int sumV = 0;
	public void solve() throws IOException
	{
		Scanner cin = new Scanner( new File("input/B-large.in"));;
		int T = cin.nextInt();
		String ans = "";
		for(int cas=1;cas<=T;cas++)
		{
			c = cin.nextInt();
			d = cin.nextInt();
			p = new long[c];
			v = new int[c];
			sumV = 0;
			for(int i=0;i<c;i++)
			{
				p[i] = cin.nextLong();
				v[i] = cin.nextInt();
				sumV += v[i];
			}
			double res = -1;
			long l = 0;
			long r = d*sumV;
			System.out.println(r);
			while(l<=r)
			{
				long mid = (l+r)/2;
				if( ok(mid ) )
				{
					res = mid;
					r = mid - 1;
				}
				else
					l = mid + 1;
			}
			if( res>0 && ok(res-0.5) )
				res -=0.5;
			ans += "Case #" + cas + ": " + res + "\n";
		}
		System.out.println(ans);
		GCJB.write("output/outputB.txt",ans);
	}
	private boolean ok(double mid) {
		double p0 = p[0] - mid;
		for(int j=1;j<v[0];j++)
		{
			double pj = p0+ d;
			if( Math.abs( pj-p[0] ) >mid )
				return false;
			p0 = pj;
			
		}
		for(int i=1;i<c;i++)
		{
			double pj = p0+d;
			double pl = p[i] - mid;
			if( pl>pj )
				pj = pl;
		//	System.out.println(mid + " " + i + " " + pj );
			if( Math.abs(pj-p[i])>mid )
				return false;
			for(int j=1;j<v[i];j++)
			{
				pj += d;
				if( Math.abs(pj - p[i]) > mid )
					return false;
			}
			p0 = pj;
		}
		return true;
	}
	public static void main(String[] arg) throws IOException{
		GCJB B = new GCJB();
		B.solve();
		System.out.println("Finish.");
	}
}
