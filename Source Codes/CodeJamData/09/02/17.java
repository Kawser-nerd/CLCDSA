import java.util.*;
import java.awt.Point;
import java.io.*;

import static java.lang.Math.*;

public class B {
	static int n,m;
	static int[][] g;
	static char[][] lab;
	static char LAB;
	
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("testin"));
		FileWriter fw = new FileWriter("testoutB");
		int N = new Integer(in.readLine());
		for (int cases = 1; cases <= N; cases++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			n = new Integer(st.nextToken());
			m = new Integer(st.nextToken());
			g = new int[n][m];
			lab = new char[n][m];
			LAB = 'a';
			for (int i = 0; i < n; i++) {
				st = new StringTokenizer(in.readLine());
				int j = 0;
				while(st.hasMoreTokens())
				{
					g[i][j] = new Integer(st.nextToken());
					lab[i][j++] = '-';
				}
			}
			fw.write("Case #" + cases + ":\n");
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if(lab[i][j] == '-')
					{
						go(i, j);
						
					}
					fw.write(lab[i][j]);
					if(j < m-1)
						fw.write(" ");
				}
				fw.write("\n");
			}
		}
		fw.flush();
		fw.close();
	}
	static char go(int i, int j)
	{
		if(i == n || i < 0 || j == m || j < 0)
			return '-';
		if(lab[i][j] != '-')
			return lab[i][j];
		Point p = minAlt(i,j);
		if(p == null)
			return lab[i][j] = LAB++;
		return lab[i][j] = go(p.x, p.y);
	}
	
	static Point minAlt(int i, int j)
	{
		int rx = 100, ry = 100, min = g[i][j];
		if(i > 0 && g[i-1][j] < min)
		{
			min = g[i-1][j];
			rx = i-1;
			ry = j;
		}
		if(j > 0 && g[i][j-1] < min)
		{
			min = g[i][j-1];
			rx = i;
			ry = j-1;
		}
		if(j < m-1 && g[i][j+1] < min)
		{
			min = g[i][j+1];
			rx = i;
			ry = j+1;
		}
		if(i < n-1 && g[i+1][j] < min)
		{
			min = g[i+1][j];
			rx = i+1;
			ry = j;
		}
		if(rx == 100)
			return null;
		return new Point(rx, ry);
	}
}

