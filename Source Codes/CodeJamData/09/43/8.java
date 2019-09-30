import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class C {
	int n,k;
	
	boolean[][] a;
	
	boolean[] used;
	int[] par;
	    
	public boolean go(int v) {
		if (used[v]) return false;
		used[v] = true;
		
		for (int i = 0; i < n; i++) {
			if ((a[v][i]) && (par[i] == -1 || go(par[i]))) {
				par[i] = v;
				return true;
			}
		}
		
		return false;
	}
	
	public void run() throws FileNotFoundException {
		Scanner input = new Scanner(new File("input.txt"));
		PrintWriter output = new PrintWriter(new File("output.txt"));
			
		int t = input.nextInt();
		
		for (int tt = 0; tt < t; tt++) {
			n = input.nextInt();
			k = input.nextInt();
			
			int[][] prices = new int[n][k];
			a = new boolean[n][n];
			
			for (int i = 0; i < n; i++)
				for (int j = 0; j < k; j++) prices[i][j] = input.nextInt();
			
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++) {
					boolean ok = true;
					for (int z = 0; z < k; z++)
						if (prices[i][z] >= prices[j][z]) {
							ok = false;
							break;
						}
					
					a[i][j] = ok;
				}
			
			used = new boolean[n];
			par = new int[n];
			for (int i = 0; i < n; i++) par[i] = -1;
			
			for (int i = 0; i < n; i++) {
				used = new boolean[n];
				go(i);
			}
			
			int ans = n;
			for (int i = 0; i < n; i++)
				if (par[i] != -1) ans--;
			
			output.println("Case #"+(tt+1)+": "+ans);
			
		}
		
		
		input.close(); output.close();	
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		(new C()).run();
	}
}