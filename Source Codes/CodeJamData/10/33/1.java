import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class C {
	static boolean[][] grid, used;
	static int m,n;
	public static void main(String[] args) throws IOException	{
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("C.txt")));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int z = Integer.parseInt(br.readLine());
		for(int q = 1; q <= z; q++)	{
			StringTokenizer st = new StringTokenizer(br.readLine());
			m = Integer.parseInt(st.nextToken());
			n = Integer.parseInt(st.nextToken());
			grid = new boolean[m][n];
			used = new boolean[m][n];
			for(int i = 0; i < m; i++)	{
				String s = br.readLine();
				for(int j = 0; j < (n>>2); j++)	{
					int k = Integer.parseInt(Character.toString(s.charAt(j)), 16);
					grid[i][4*j] = (k&8) == 0;
					grid[i][4*j+1] = (k&4) == 0;
					grid[i][4*j+2] = (k&2) == 0;
					grid[i][4*j+3] = (k&1) == 0;
				}
			}
			ArrayList<Pair> list = new ArrayList<Pair>();
			while(true)	{
				int best = 0;
				int num = 0;
				for(int i = 0; i < m; i++)	{
					for(int j = 0; j < n; j++)	{
						for(int s = best+1; true; s++)	{
							if(fail(i,j,s))	{
								break;
							}
							System.out.println("Side length " + s + " passes at " + i + " " + j);
							best = s;
						}
					}
				}
				if(best == 0)	{
					break;
				}
				for(int i = 0; i < m; i++)	{
					for(int j = 0; j < n; j++)	{
						if(!fail(i,j,best))	{
							for(int xAdd = 0; xAdd < best; xAdd++)	{
								for(int yAdd = 0; yAdd < best; yAdd++)	{
									used[i+xAdd][j+yAdd] = true;
								}
							}
							num++;
						}
					}
				}
				System.out.println("Squares of side " + best + " of number " + num + " computed");
				list.add(new Pair(best, num));
			}
			pw.println("Case #" + q + ": " + list.size());
			for(Pair p: list)	{
				pw.println(p.s + " " + p.n);
			}
			System.out.println("Case #" + q + " DONE!");
		}
		pw.close();
	}
	public static boolean fail(int x, int y, int s)	{
		if(x+s > m || y+s > n)
			return true;
		boolean expected = grid[x][y];
		for(int xAdd = 0; xAdd < s; xAdd+=2)	{
			for(int yAdd = 0; yAdd < s; yAdd+=2)	{
				if(expected != grid[x+xAdd][y+yAdd])
					return true;
				if(used[x+xAdd][y+yAdd])
					return true;
			}
		}
		for(int xAdd = 1; xAdd < s; xAdd+=2)	{
			for(int yAdd = 1; yAdd < s; yAdd+=2)	{
				if(expected != grid[x+xAdd][y+yAdd])
					return true;
				if(used[x+xAdd][y+yAdd])
					return true;
			}
		}
		for(int xAdd = 0; xAdd < s; xAdd+=2)	{
			for(int yAdd = 1; yAdd < s; yAdd+=2)	{
				if(expected == grid[x+xAdd][y+yAdd])
					return true;
				if(used[x+xAdd][y+yAdd])
					return true;
			}
		}
		for(int xAdd = 1; xAdd < s; xAdd+=2)	{
			for(int yAdd = 0; yAdd < s; yAdd+=2)	{
				if(expected == grid[x+xAdd][y+yAdd])
					return true;
				if(used[x+xAdd][y+yAdd])
					return true;
			}
		}
		return false;
	}
	static class Pair {
		public int s,n;
		public Pair(int a, int b)	{
			s=a;
			n=b;
		}
	}
}
