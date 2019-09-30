import java.io.*;
import java.util.*;
public class B {
	static boolean[][] valid;
	static int maxFall;
	static int best;
	public static void main(String[] args) throws IOException	{
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("B.txt")));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int z = Integer.parseInt(br.readLine());
		for(int q = 1; q <= z; q++)	{
			best = Integer.MAX_VALUE;
			StringTokenizer st = new StringTokenizer(br.readLine());
			int r = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			maxFall = Integer.parseInt(st.nextToken());
			valid = new boolean[r][c];
			for(int i = 0; i < r; i++)	{
				String s = br.readLine();
				for(int j = 0; j < c; j++)
					valid[i][j] = s.charAt(j) == '.';
			}
			start(0,0,-1,-1,0);
			if(best == Integer.MAX_VALUE)
				pw.println("Case #" + q + ": No");
			else
				pw.println("Case #" + q + ": Yes " + best);
		}
		pw.close();
	}
	public static boolean isValid(int x, int y)	{
		return x >= 0 && y >= 0 && x < valid.length && y < valid[x].length;
	}
	public static void start(int x, int y, int lastX, int lastY, int num)	{
		if(num >= best)
			return;
		if(x+1==valid.length)	{
			best = num;
			return;
		}
		if(isValid(x,y+1) && valid[x][y+1])	{
			int min = x+1;
			for(; min < valid.length; min++)	{
				if(!valid[min][y+1])
					break;
			}
			int dist = min-x-1;
			if(dist <= maxFall && (min-1 != lastX || y+1 != lastY))	{
				start(min-1,y+1,x,y,num);
			}
		}
		if(isValid(x,y-1) && valid[x][y-1])	{
			int min = x+1;
			for(; min < valid.length; min++)	{
				if(!valid[min][y-1])
					break;
			}
			int dist = min-x-1;
			if(dist <= maxFall && (min-1 != lastX || y-1 != lastY))	{
				start(min-1,y-1,x,y,num);
			}
		}
		if(isValid(x+1,y-1) && valid[x][y-1] && !valid[x+1][y-1])	{
			valid[x+1][y-1] = true;
			start(x,y,-1,-1,num+1);
			valid[x+1][y-1] = false;
		}
		if(isValid(x+1,y+1) && valid[x][y+1] && !valid[x+1][y+1])	{
			valid[x+1][y+1] = true;
			start(x,y,-1,-1,num+1);
			valid[x+1][y+1] = false;
		}
	}
}
