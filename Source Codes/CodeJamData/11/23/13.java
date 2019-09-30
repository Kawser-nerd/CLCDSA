import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;


public class GCJC {
	public static void write(String filename, String content) throws IOException
	{
		BufferedWriter out = new BufferedWriter( new FileWriter(filename));
		out.write( content );
		out.close();
	}
	int N;
	int M;
	int u [];
	int v [];
	int col = 0;
	int c [];
	int dc [];
	int minRoom;
	ArrayList< ArrayList<Integer> > room;
	public void solve() throws IOException
	{
		Scanner cin = new Scanner( new File("input/C-small-attempt3.in"));;
		int T = cin.nextInt();
		String ans = "";
		
		for(int cas=1;cas<=T;cas++)
		{
			System.out.println(cas);
			N = cin.nextInt();
			M = cin.nextInt();
			u = new int[M];
			v = new int[M];
			c = new int[N];
			dc = new int[N];
			room = new ArrayList<ArrayList<Integer>>();
			for(int i=0;i<M;i++)
			{
				u[i] = cin.nextInt();
				u[i] --;
			}
			for(int i=0;i<M;i++)
			{
				v[i] = cin.nextInt();
				v[i] --;
			}
			
			ArrayList<Integer> poi = new ArrayList<Integer>();
			for(int i=0;i<N;i++)
				poi.add(i);
			minRoom = N;
			dfs1(0, poi);
			for(int i=0;i<room.size();i++)
			{
				ArrayList rm = room.get(i);
				for(int j=0;j<rm.size();j++)
					System.out.print(" " + rm.get(j) );
				System.out.println();
			}
			col = 0;
			dfs(0);
			System.out.println("dfs");
			
			ans += "Case #" + cas + ": " + col + "\n";

			ans += c[0];
			for(int i=1;i<N;i++)
				ans += " " + c[i];
			ans += "\n";
			
		}
		System.out.println(ans);
		GCJC.write("output/outputC.txt",ans);
	}
	private void dfs1(int wall, ArrayList<Integer> poi) {
		if(wall==M)
		{
			ArrayList<Integer> rv = new ArrayList<Integer>();
			for(int i=0;i<poi.size();i++)
				rv.add( poi.get(i) );
			if( rv.size()<minRoom )
				minRoom = rv.size();
			room.add(rv);
			return ;
		}
		if( u[wall] > v[wall] )
		{
			int t = u[wall];
			u[wall] = v[wall];
			v[wall] = t;
		}
		ArrayList<Integer> rv1 = new ArrayList<Integer>();
		ArrayList<Integer> rv2 = new ArrayList<Integer>();
		for(int i=0;i<poi.size();i++)
		{
			if( poi.get(i)<= u[wall] || poi.get(i) >= v[wall])
				rv1.add( poi.get(i) );
			if( poi.get(i)>= u[wall] && poi.get(i) <= v[wall] )
				rv2.add( poi.get(i) );
		}
		if(rv1.size()>=3)
			dfs1(wall+1,rv1);
		if( rv2.size()>=3 )
			dfs1(wall+1,rv2);
	}
	private void dfs(int len) {
		if( len==N )
		{
			int cN [] = new int[room.size()];
			for(int i=0;i<room.size();i++)
			{
				ArrayList<Integer> rm = room.get(i);
				HashSet<Integer> se = new HashSet<Integer>();
				for(int j=0;j<rm.size();j++)
					se.add( dc[ rm.get(j) ] );
				cN[i] = se.size();
			}
			boolean flag = true;
			for(int i=1;i<room.size();i++)
				if( cN[i-1]!=cN[i] )
					flag = false;
			if( flag==true && cN[0]> col )
			{
				col = cN[0];
				for(int i=0;i<N;i++)
					c[i] = dc[i];
			}
			return ;
		}
		for(int i=0;i<minRoom;i++)
		{
			dc[len] = i+1;
			dfs(len+1);
		}
		
	}
	public static void main(String[] arg) throws IOException{
		GCJC C = new GCJC();
		C.solve();
		System.out.println("Finisth");
	}
}
