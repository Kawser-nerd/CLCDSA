import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;


public class BribeThePrisoners {
	private static int[][] memo;

	public static void main(String[] args){
		try {
			BufferedReader in = new BufferedReader(new FileReader("A-small.in"));
			BufferedWriter out = new BufferedWriter(new FileWriter("x.txt"));

			Scanner scan = new Scanner(in);

			int T = scan.nextInt();
			//scan.nextLine();
			for(int ii=0; ii<T; ii++)
			{
				
				int P = scan.nextInt();
				int Q = scan.nextInt();
				
				L = new int[Q+2];
				for(int i=0; i<Q; i++)
				{
					L[i] = scan.nextInt();
				}
				L[L.length-2] = 0;
				L[L.length - 1] = P+1;
				Arrays.sort(L);
				memo = new int[L.length+1][L.length+1];
				for(int i=0; i<memo.length; i++)
				{
					Arrays.fill(memo[i], -1);
				}
				int ret = get(0, L.length-1);
				out.write("Case #"+(ii+1)+": "+ret+"\n");
				//System.out.println(dp[0][L.length]);

			}



			in.close();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	static final int oo = 1000000000;
	static int[] L;
	private static int get(int from, int to) {
		
		if(to-from==1)
			return 0;
		
		if(memo[from][to]>-1)
			return memo[from][to];
		
		int ret = oo;
		for(int i=from+1; i<=to-1; i++)
		{
			ret = Math.min(ret, get(from, i) + get(i, to) + Math.max(L[to]-1 - (L[from]+1) , 0) );
		}
		return memo[from][to] = ret;
	}
}
