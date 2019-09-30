import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Arrays;

public class C {
	static boolean[][] a;
	static boolean[] v;
	static int[] match;
	static int stocks;
	
	public static boolean dfs (int x) {
		if (x == -1)
			return true;
		if (v[x])
			return false;
		v[x] = true;
		
		for (int i = 0; i < stocks; i++)
			if (a[x][i]) {
				int t = match[i];
				match[i] = x;
				if (dfs(t))
					return true;
				match[i] = t;
			}
		return false;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("C-large.in"));
		PrintStream ps = new PrintStream(new FileOutputStream("C-large.out"));
		
		int cases = Integer.parseInt(br.readLine());
		
		for (int itr = 1; itr <= cases; itr++) {
			String[] sp = br.readLine().split(" ");
			stocks = Integer.parseInt(sp[0]);
			int points = Integer.parseInt(sp[1]);
			
			int[][] prices = new int [stocks][points];
			for (int i = 0; i < stocks; i++) {
				sp = br.readLine().split(" ");
				for (int j = 0; j < points; j++)
					prices[i][j] = Integer.parseInt(sp[j]);
			}
			
			a = new boolean [stocks][stocks];
			for (int i = 0; i < stocks; i++)
				for (int j = 0; j < stocks; j++) {
					boolean below = true;
					for (int k = 0; k < points; k++)
						if (prices[i][k] <= prices[j][k]) {
							below = false;
							break;
						}
					if (below)
						a[i][j] = true;
				}
			
			match = new int [stocks];
			Arrays.fill(match, -1);
			
			v = new boolean [stocks];
			
			int out = stocks;
			for (int i = 0; i < stocks; i++) {
				if (dfs(i))
					out--;
				Arrays.fill(v, false);
			}
			ps.println("Case #" + itr + ": " + out);
		}
		
		br.close();
		ps.close();
	}

}
