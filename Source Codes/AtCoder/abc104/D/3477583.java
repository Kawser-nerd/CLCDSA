import java.util.Scanner;

class Main{


	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);			//?????

		String S = sc.next();
		long mod = 1000000007L;
		String ABC = "ABC";
		long[][] dp = new long[S.length()][4];


		if(S.charAt(0) == '?'){					//???
			dp[0][0] = 3;
		}else{
			dp[0][0] = 1;
		}

		if(S.charAt(0) == 'A' || S.charAt(0) == '?'){
			dp[0][1] = 1;
		}


		for(int i = 1;i < S.length();i++){
			for(int j = 0;j < 4;j++){

				if(j == 0){
					if(S.charAt(i) == 'A' ||S.charAt(i) == 'B'||S.charAt(i) == 'C'){
						dp[i][0] = dp[i-1][0];
					}else{
						dp[i][0] = dp[i-1][0]*3L;
					}
					
					dp[i][j] %=mod;


				}else{

					long x = (S.charAt(i) == '?' ? 3L : 1L);				//??????????
					long y =( (S.charAt(i) == ABC.charAt(j-1)|| S.charAt(i) == '?') ? 1L :0L);

					dp[i][j] = (dp[i-1][j] * x) + (dp[i-1][j-1]*y); 
				dp[i][j] %=mod;
				}
			}


		}

		System.out.println(dp[S.length()-1][3] );
	}

}