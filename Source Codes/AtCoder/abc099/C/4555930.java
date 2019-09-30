import java.util.ArrayList;
import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		final int INF = Integer.MAX_VALUE;
		Scanner scn = new Scanner(System.in);
		int N = scn.nextInt();
		ArrayList<Integer> coins = new ArrayList<Integer>();
		coins.add(1);
		for(int i = 1; ;i++) {
			int buf = (int)Math.pow(6, i);
			if(buf > N)break;
			coins.add(buf);
		}
		for(int i = 1; ;i++) {
			int buf = (int)Math.pow(9, i);
			if(buf > N)break;
			coins.add(buf);
		}
		int[] DP = new int[N+1];
		DP[0] = 0;
		for(int i = 1;i <= N;i++) {
			DP[i] = INF;
		}

		int length = coins.size();
		for(int i = 1;i <=N;i++) {
			for(int j = 0;j < length;j++) {
				int coin = coins.get(j);
				if(i >= coin) {
					DP[i] = Math.min(DP[i], DP[i-coin]+1);
				}
			}
		}
		System.out.println(DP[N]);
	}

}