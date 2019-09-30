import java.util.Scanner;

class Main{
	static final long MOD = 1000000007;

	static int H, W, K;
	static long[][] dp = new long[110][10];
	static int ans = 0;
	static long n = 0;





	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);			//?????
		int H = sc.nextInt();
		int W = sc.nextInt();
		int K = sc.nextInt();
		long MOD = 1000000007;

		int[][] dp = new int[H+1][W];				//dp[i][j] = i???j?????????
		dp[0][0] = 1;		
		for(int h = 1;h <= H;h++){
			for(int w = 0;w < W;w++){
				for(int i = 0;i < (1 << W-1);i++){		//?????? h??????????????
					int mask = 3;
					boolean flag = true;
					while(true){		//??????????????
						
						if((mask & i) == mask){
							flag = false;
						}

						if(mask == 3<<W-1){				//?????????????
							break;
						}
						mask =mask << 1;					//??1???
					}

					if(flag){				//????????????

						if(w > 0 && (i & (1 << w-1)) > 0){			//??????w?w-1?????????
							dp[h][w] += dp[h-1][w-1];
						}else if(w < W-1 && (i & (1 << w)) > 0){	//??????w?w+1?????????
							dp[h][w] += dp[h-1][w+1];
						}else{										//?????????????
							dp[h][w] += dp[h-1][w];

						}
						dp[h][w] %= MOD;


					}

				}
			}
		}
		System.out.println(dp[H][K-1]);

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