import java.util.*;
import java.io.*;
import static java.lang.System.out;
import static java.lang.Math.*;

public class B {
	static Scanner in;

	static String nl() { return in.nextLine(); }
	static int ni() { return in.nextInt(); }
	static double nd() { return in.nextDouble(); }

	static int pi(String x) { return Integer.parseInt(x); }
	static double pd(String x) { return Double.parseDouble(x); }

	public static void main(String[] args) throws Exception
	{
		in = new Scanner(new File("B-large.in"));
		PrintWriter out = new PrintWriter(new FileWriter(new File("B-large.out")));
		int tot=pi(nl());
		System.out.println("Total: " + tot);
		for(int iii=0;iii<tot;iii++)
		{
			out.print("Case #" + (iii+1) + ": ");
			System.out.println("Case #" + (iii+1));
			String[] inputs = nl().split(" ");
			int r = pi(inputs[0]);
			int c = pi(inputs[1]);
			int[][] m = new int[r][c];
			char[][] maz = new char[r][c];
			int sr, sc, er, ec;
			sr = sc = er = ec = -1;
			for(int i=0;i<r;i++)
			{
				String inp = nl().trim();
				maz[i] = inp.toCharArray();
				if(inp.indexOf('O')!=-1)
				{
					sr = i; sc = inp.indexOf('O');
				}
				if(inp.indexOf('X')!=-1)
				{
					er = i; ec = inp.indexOf('X');
				}
			}
			m[sr][sc] = 1;
			for(int step = 1; step<=r*c;step++)
			{
				if(m[er][ec] != 0 && step >= m[er][ec])
					break;
				for(int i=0;i<r;i++)
				{
					for(int ii=0;ii<c;ii++)
					{
						if(m[i][ii] == step)//move by turn
						{
							//try cardinal moves
							//up
							if(i>0 && maz[i-1][ii]!='#' && (m[i-1][ii]==0 || m[i][ii]+1<m[i-1][ii]))
								m[i-1][ii] = m[i][ii]+1;
							//down
							if(i<r-1 && maz[i+1][ii]!='#' && (m[i+1][ii]==0 || m[i][ii]+1<m[i+1][ii]))
								m[i+1][ii] = m[i][ii]+1;
							//left
							if(ii>0 && maz[i][ii-1]!='#' && (m[i][ii-1]==0 || m[i][ii]+1<m[i][ii-1]))
								m[i][ii-1] = m[i][ii]+1;
							//right
							if(ii<c-1 && maz[i][ii+1]!='#' && (m[i][ii+1]==0 || m[i][ii]+1<m[i][ii+1]))
								m[i][ii+1] = m[i][ii]+1;
							//try portals
							int[][] walls = new int[4][2];
							for(int dira=0;dira<4;dira++)
							{
								walls[dira] = get(maz, i, ii, dira);
							}
							for(int dira=0;dira<4;dira++)
							{
								int dist = abs(walls[dira][0] - i) + abs(walls[dira][1] - ii) + 1;
								for(int dirb=0;dirb<4;dirb++)
								{
									if(dira==dirb) continue;
									
									//move through wall a to wall dirb
									if(m[walls[dirb][0]][walls[dirb][1]]==0 || m[i][ii]+dist<m[walls[dirb][0]][walls[dirb][1]])
									{
										m[walls[dirb][0]][walls[dirb][1]] = m[i][ii]+dist;
									}
								}
							}
						}
					}
				}
			}
			if(m[er][ec]==0)
			{
				out.println("THE CAKE IS A LIE");
			}
			else
				out.println(m[er][ec]-1);
			
		}
		out.close();
	}
	static int[] get(char[][] maze, int i, int ii, int dir)
	{
		int x = i;
		int y = ii;
		if(dir==0)
		{
			while(x>=0)
			{
				if(maze[x][y] == '#') break;
				x--;
			}
			return new int[]{x+1,y};
		}
		if(dir==1)
		{
			while(y<maze[0].length)
			{
				if(maze[x][y] == '#') break;
				y++;
			}
			return new int[]{x,y-1};
		}
		if(dir==2)
		{
			while(x<maze.length)
			{
				if(maze[x][y] == '#') break;
				x++;
			}
			return new int[]{x-1,y};
		}
		if(dir==3)
		{
			while(y>=0)
			{
				if(maze[x][y] == '#') break;
				y--;
			}
			return new int[]{x,y+1};
		}
		return null;
	}
}