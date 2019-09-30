//input file must be in.txt in this directory
//output file will be out.txt

import java.io.*;
import java.util.*;
public class D
{
	public static Scanner in;
	public static PrintStream out;
	
	public static void main(String [] args) throws Throwable
	{
		in = new Scanner(new File("in.txt"));
		int cases = in.nextInt();
		in.nextLine();
		out = new PrintStream(new File("out.txt"));
		for (int i = 1; i <= cases; i++)
		{
			out.print("Case #" + i + ": ");
			printResult();
			out.println();
		}
	}
	public static int gcd(int a, int b)
	{
		if (b == 0)
			return a;
		return gcd(b, a % b);
	}
	public static boolean canSeeImage(int dx, int dy, int lx, int ly, int d, boolean [][] house)
	{
		//System.out.println("Trying (" + dx + "," + dy + "):");
		int cx = lx;
		int cy = ly;
		int sx, sy;
		if (dx > 0)
			sx = 1;
		else
			sx = -1;
		if (dy > 0)
			sy = 1;
		else
			sy = -1;
		dx = Math.abs(dx);
		dy = Math.abs(dy);
		int i = 0;
		int totx = 0;
		int toty = 0;
		boolean t;
		boolean mx,my;
		boolean nx = false,ny = false;
		while (totx*totx + toty*toty <= d*d)
		{
			if (dx == 0)
			{
				my = true;
				mx = false;
				t = true;
			}
			else
			{
				if (dy == 0)
				{
					mx = true;
					my = false;
					t = true;
				}
				else
				{
					mx = i % dy == 0;
					my = i % dx == 0;
					t = mx && my && !nx && !ny;
					if (mx)
					{
						mx = nx;
						nx = !nx;
					}
					if (my)
					{
						my = ny;
						ny = !ny;
					}
					
				}
			}
			
			if (t && totx+toty > 0 && cx == lx && cy == ly)
				return true;
			
			//if (mx || my)
			//	printHouse(lx,ly,cx,cy,house);
			
			if (mx)
				totx++;
			if (my)
				toty++;
			
			if (mx && my)
			{
				if (house[cx + sx][cy + sy])
				{
					if (house[cx][cy + sy])
					{
						if (house[cx + sx][cy])
						{
							sx = -sx;
							sy = -sy;
						}
						else
						{
							sy = -sy;
							cx += sx;
						}
					}
					else
					{
						if (house[cx + sx][cy])
						{
							sx = -sx;
							cy += sy;
						}
						else
						{
							return false;
						}
					}
				}
				else
				{
					cx += sx;
					cy += sy;
				}
				
			}
			else
			{
				if (mx)
				{
					if (house[cx + sx][cy])
					{
						sx = -sx;
					}
					else
					{
						cx += sx;
					}
				}
				if (my)
				{
					if (house[cx][cy + sy])
					{
						sy = -sy;
					}
					else
					{
						cy += sy;
					}
				}
			}
			i++;
		}
		
		return false;
	}
	public static void printHouse(int lx, int ly, int cx, int cy, boolean [][] house)
	{
		for (int y = 0; y < house[0].length; y++)
		{
			for (int x = 0; x < house.length; x++)
			{
				if (x == cx && y == cy)
				{
					System.out.print('*');
				}
				else if (x == lx && y == ly)
				{
					System.out.print('X');
				}
				else if (house[x][y])
				{
					System.out.print('#');
				}
				else
				{
					System.out.print(' ');
				}
			}
			System.out.println();
		}
	}
	public static int[][] getPossibilities(int d)
	{
		ArrayList<Integer> lx = new ArrayList<Integer>();
		ArrayList<Integer> ly = new ArrayList<Integer>();
		
		int h, v;
		for (int x = -d; x <= d; x++)
		{
			for (int y = -d; y <= d; y++)
			{
				h = Math.abs(x);
				v = Math.abs(y);
				if (gcd(h,v) == 1 && h*h + v*v <= d*d)
				{
					lx.add(x);
					ly.add(y);
				}
			}
		}
		
		int [][] possibilities = new int [lx.size()][2];
		
		for (int i = 0; i < possibilities.length; i++)
		{
			possibilities[i][0] = lx.get(i);
			possibilities[i][1] = ly.get(i);
		}
		return possibilities;
	}
	public static void printResult()
	{
		int h,w,d,lx = 0,ly = 0;
		h = in.nextInt();
		w = in.nextInt();
		d = in.nextInt();
		in.nextLine();
		String s;
		boolean [][] house = new boolean[w][h];
		for (int y = 0; y < h; y++)
		{
			s = in.nextLine();
			for (int x = 0; x < w; x++)
			{
				house[x][y] = s.charAt(x) == '#';
				if (s.charAt(x) == 'X')
				{
					lx = x;
					ly = y;
				}
			}
		}
		int [][] poss = getPossibilities(d);
		int images = 0;
		for (int i = 0; i < poss.length; i++)
		{
			if (canSeeImage(poss[i][0], poss[i][1], lx, ly, d, house))
			{
				images++;
				//System.out.println("True");
			}
			//else
				//System.out.println("False");
		}
		out.print(images);
	}
}
