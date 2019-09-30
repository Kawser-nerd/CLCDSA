package gcj;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class C {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */

	boolean [][] b = new boolean[105][105];
	boolean reduce()
	{
		boolean flag = false;
		boolean [][] a = new boolean[105][105];
		
		for(int i=1;i<=100;i++)
			for(int j=1;j<=100;j++)
			{
				if( b[i][j-1]==false && b[i-1][j]==false )
					a[i][j] = false;
				else if( b[i][j-1]==true && b[i-1][j]==true )
					a[i][j] = true;
				else
					a[i][j] = b[i][j];
				if( b[i][j] )
					flag = true;
			}
		for(int i=1;i<=100;i++)
			for(int j=1;j<=100;j++)
				b[i][j] = a[i][j];
		if( flag )
			return true;
		return false;
	}
	public void solve() throws FileNotFoundException
	{
		Scanner cin = new Scanner( new File("input.txt"));
		System.setOut( new PrintStream("Cs.txt") );
		int T;
		T = cin.nextInt();
		for(int cas=1;cas<=T;cas++)
		{
			int r = cin.nextInt();
			for(int i=0;i<105;i++)
				for(int j=0;j<105;j++)
					b[i][j] = false;
			for(int i=0;i<r;i++)
			{
				int x1 = cin.nextInt();
				int y1 = cin.nextInt();
				int x2 = cin.nextInt();
				int y2 = cin.nextInt();
				for(int x=x1;x<=x2;x++)
					for(int y=y1;y<=y2;y++)
						b[y][x] = true;
			}

			int t = 0;
			while( reduce() )
				t++;
			System.out.println("Case #"+cas+": " +  t );
		}
	}
	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		C c = new C();
		c.solve();
	}

}
