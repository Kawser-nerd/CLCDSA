import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Arrays;

public class C {
	public static int total, pack;
	public static double[] mem;
	public static long[][] chooseMem = new long [50][50];
	static {
		for (int i = 0; i < 50; i++)
			Arrays.fill(chooseMem[i], -1);
	}
	
	public static long choose (int n, int k) {
		if (k > n)
			return 0;
		if (n == k || k == 0)
			return 1;
		if (chooseMem[n][k] != -1)
			return chooseMem[n][k];
		return chooseMem[n][k] = choose(n-1,k-1) + choose(n-1,k);
	}
	
	public static double dfs (int x) {
		if (x >= total)
			return 0;
		if (mem[x] != -1)
			return mem[x];
		
		double out = 0;
		for (int i = 1; i <= pack; i++)
			out += choose(total-x,i)*choose(x,pack-i)*dfs(x+i);
		out = out / choose(total,pack) + 1;
		out /= (1 - (double)choose(total-x,0)*choose(x,pack)/choose(total,pack));
		return mem[x] = out;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("C-large.in"));
		PrintStream ps = new PrintStream(new FileOutputStream("C-large.out"));
		
		int cases = Integer.parseInt(br.readLine());
		
		for (int itr = 1; itr <= cases; itr++) {
			String[] sp = br.readLine().split(" ");
			total = Integer.parseInt(sp[0]);
			pack = Integer.parseInt(sp[1]);
			
			mem = new double [total];
			Arrays.fill(mem, -1);
			
			ps.println("Case #" + itr + ": " + dfs(0));
			System.out.println("Case #" + itr + ": " + dfs(0));
		}
		
		br.close();
		ps.close();
	}

}
