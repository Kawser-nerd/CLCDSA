import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

class Main{
	static final long MOD = 1000000007;

	static int H, W, K;
	static long[][] dp = new long[110][10];



	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);			//?????
		H = sc.nextInt();
		W = sc.nextInt();
		K = sc.nextInt() - 1;
		dp[0][0] = 1;
		for(int h=1; h<=H; ++h) {
			for(int w=0; w<W; ++w) {
				for(int b=0; b<(1<<(W-1)); ++b) {   //?????????h???????????
					int x = 3;
					boolean flg = false;
					while(x < 1<<20) {				
						if((x&b) == x) flg = true;
						x <<= 1;
					}
					if(flg) {
						continue;
					}else{

						if(w>0 && (b&(1<<(w-1)))>0) {			//?
							dp[h][w] += dp[h-1][w-1];
						}
						else if(w < W-1 && (b&(1<<w))>0) {		//?
							dp[h][w] += dp[h-1][w+1];
						}
						else {
							dp[h][w] += dp[h-1][w];
						}
						dp[h][w] %= MOD;
					}
				}
			}
		}
		System.out.println(dp[H][K]);

	}





}







class Pair implements Comparable{
	int from;		//p
	int end;		//y
	int num;
	int bango;
	@Override
	public int compareTo(Object other) {
		Pair otherpair = (Pair)other;

		return end - otherpair.end;
	}
}