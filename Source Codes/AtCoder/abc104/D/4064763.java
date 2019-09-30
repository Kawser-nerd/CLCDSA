import java.util.Scanner;

class Main{
	static int G;
	static int D;
	static int[] p;
	static int[] c;
	static boolean[] used;
	static long ans = 1000000000;


	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);			//?????
		String ss = sc.next();
		long[][] dp = new long[ss.length()+1][4];
		dp[0][0] = 1;
		long mod = 1000000007;
		for(int i = 0;i < ss.length();i++){
			if(ss.charAt(i) == 'A' ){
				dp[i+1][0] += dp[i][0] %mod;			//A??????
				dp[i+1][1] += dp[i][1] % mod;			//A??????
				dp[i+1][2] += dp[i][2] % mod;			//A??????
				dp[i+1][3] += dp[i][3] % mod;			//A??????
				dp[i+1][1] += dp[i][0] % mod;

			}else if(ss.charAt(i) == 'B'){
				dp[i+1][0] += dp[i][0] % mod;			//A??????
				dp[i+1][1] += dp[i][1] % mod;			//A??????
				dp[i+1][2] += dp[i][2] % mod;			//A??????
				dp[i+1][3] += dp[i][3] % mod;			//A??????
				dp[i+1][2] += dp[i][1] % mod;
			}else if(ss.charAt(i) == 'C'){
				dp[i+1][0] += dp[i][0] % mod;			//A??????
				dp[i+1][1] += dp[i][1] % mod;			//A??????
				dp[i+1][2] += dp[i][2] % mod;			//A??????
				dp[i+1][3] += dp[i][3] % mod;			//A??????
				dp[i+1][3] += dp[i][2] % mod;
			}
			if( ss.charAt(i) == '?'){
				dp[i+1][0] +=3*dp[i][0] % mod;			//A??????
				dp[i+1][1] +=3*dp[i][1] % mod;			//A??????
				dp[i+1][2] +=3*dp[i][2] % mod;			//A??????
				dp[i+1][3] +=3*dp[i][3] % mod;	
				
				
				dp[i+1][1] += dp[i][0] % mod;
				dp[i+1][2] += dp[i][1] % mod;
				dp[i+1][3] += dp[i][2] % mod;



			}
//			System.out.println(dp[i+1][0] + " "+dp[i+1][1] + " "+dp[i+1][2] +" "+dp[i+1][3] );
		}

		System.out.println(dp[ss.length()][3] % mod);


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

		return from - otherpair.from;
	}
}