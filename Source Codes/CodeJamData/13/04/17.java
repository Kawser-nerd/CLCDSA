import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;


public class Treasure {
	
	public static int MAX = 205;
	
	public static int[] solve(int[] keys , int[] open , int[][] map){
		int N = open.length;
		boolean[] dp = new boolean[1 << N];
		for(int i = 0 ; i < (1 << N) ; i ++){
			dp[i] = true;
		}
		int[] results = new int[N];
		if(solve(dp , keys , open , map , 0 , 0 , N , results))
			return results;
		return null;
	}
	
	public static boolean solve(boolean[] dp , int[] keys , int[] open , int[][] map, int state, int loc , int N , int[] results){
		if(loc == N)
			return true;
		if(!dp[state])
			return false;
		
		for(int i = 0 ; i < N; i ++){
			if(keys[open[i]] > 0 && (state & ( 1 << i) )  == 0){
				keys[open[i]] --;
				int[] nextKeys = transform(keys , map[i]);
				results[loc] = i;
				int nextState = state | (1 << i);
				if(solve(dp , nextKeys , open , map , nextState , loc + 1 , N , results))
					return true;
				keys[open[i]] ++;
			}
		}
		dp[state] = false;
		return false;
	}
	
	private static int[] transform(int[] keys , int[] map){
		int[] newKeys = new int[MAX];
		for(int i = 0 ; i < MAX ; i ++){
			newKeys[i] += keys[i] + map[i];
		}
		return newKeys;
	}
	
	public static void main(String args[]) throws Exception{
		Scanner in = new Scanner(new FileInputStream("D-small-attempt0.in"));
		PrintWriter writer = new PrintWriter(
				new FileOutputStream("D-small-attempt0.out"));
		
		int T = in.nextInt();
		
		
		for (int i = 0; i < T; i++) {
			int K = in.nextInt();
			int N = in.nextInt();
			int[] keys = new int[MAX];
			int[] open = new int[N];
			int[][] map = new int[N][MAX];
			for(int j = 0 ; j < K ; j ++){
				keys[in.nextInt()] ++;
			}
			for(int j = 0 ; j < N ; j ++){
				open[j] = in.nextInt();
				int k = in.nextInt();
				for(int l = 0 ; l < k ; l ++){
					map[j][in.nextInt()] ++;
				}
			}
			writer.write("Case #" + (i + 1) + ": ");
			
			int[] results = solve(keys , open , map);
			if(results == null){
				writer.println("IMPOSSIBLE");
			}else{
				for(int j = 0 ; j < N ; j ++){
					if(j > 0)
						writer.write(" " + (results[j] + 1));
					else
						writer.write("" + (results[j] + 1));
				}
				writer.println();
			}
		}
		in.close();
		writer.close();
		
	}

}
