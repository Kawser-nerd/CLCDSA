import java.util.*;
import java.io.*;

public class B {


public static void main(String [] args) throws Exception
{
	//Scanner scan = new Scanner(new File("B-small-attempt0.in"));
	Scanner scan = new Scanner(new File("B-large.in"));
	
	//PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("outB1")));
	PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("outB2")));

	// solution
	int[] dx = new int[]{-1,0,0,1};
	int[] dy = new int[]{0,-1,1,0};
	
	int T = scan.nextInt();
	for (int t = 1; t <= T; t++)
	{
		int H = scan.nextInt();
		int W = scan.nextInt();
		int[][] map = new int[H][W];
		for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			map[i][j] = scan.nextInt();
		
		char[][] label = new char[H][W];
		
		char current = 'a';
		for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
		{
			if (label[i][j] == 0)
			{
				LinkedList<Integer> list = new LinkedList<Integer>();
				int x = i, y = j;
				int lastLow = map[x][y];
				list.add(x);
				list.add(y);
				char lab = 0;
				while (true)
				{					
					int low = map[x][y];
					int bestX = -1, bestY = -1;
					for (int d = 0; d < 4; d++)
					{
						int cx = x+dx[d], cy = y+dy[d];
						if (cx >= 0 && cx < H && cy >= 0 && cy < W && map[cx][cy] < low)
						{
							low = map[cx][cy];
							bestX = cx;
							bestY = cy;	
						}
					}
					if (bestX != -1)
					{
						if (label[bestX][bestY] == 0)
						{
							list.add(bestX);
							list.add(bestY);
							x = bestX;
							y = bestY;
						}
						else
						{
							lab = label[bestX][bestY];
							break;	
						}
					}
					else
					{
						lab = current++;						
						break;
					}
				}
				while (list.size() > 0)
				{
					x = list.remove();
					y = list.remove();
					label[x][y] = lab;
				}				
			}
		}
		
		out.println("Case #"+t+":");
		for (int i = 0; i < H; i++)
		{
			out.print(label[i][0]);
			for (int j = 1; j < W; j++)
				out.print(" "+label[i][j]);
			out.println();
		}		
	}
	
	out.close();
}
}
