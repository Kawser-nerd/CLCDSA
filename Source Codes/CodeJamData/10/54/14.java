import java.util.*;

public class Main {
	public static void main(String[] args){
		new Main();
	}
	long mod = 1000000007;
	HashMap[][][] memo = new HashMap[102][11][102];
	
	void create(){
		for(int i = 0; i < 102; i++) for(int j = 0; j < 11; j++)
			for(int k = 0; k < 102; k++) memo[i][j][k] = new HashMap();
	}
	long calc(int num, int base, int[] mask, int last){
		if(num == 0) return 1;
		if(memo[num][base][last].containsKey(mask))
			return (Long)memo[num][base][last].get(mask);
		long res = 0;
		loop: for(int i = 1; i <= Math.min(last - 1, num); i++){
			String digs = Integer.toString(i, base);
			int[] next = mask.clone();
			for(int j = 0; j < digs.length(); j++){
				if((mask[j] & (1 << (int)(digs.charAt(digs.length() - j - 1) - '0'))) != 0)
					continue loop;
				else next[j] |= (1 << (int)(digs.charAt(digs.length() - j - 1) - '0'));
			}
			res = (res + calc(num - i, base, next, i)) % mod;
		}
		memo[num][base][last].put(mask, (Long)res);
		return res;
	}
	
	public Main(){
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		create();
		for(int tt = 1; tt <= t; tt++){
			int n = in.nextInt(), b = in.nextInt();
			int[] mask = new int[8];
			Arrays.fill(mask, 0);
			System.out.println("Case #" + tt + ": " + calc(n, b, mask, n + 1));
		}
	}
}
