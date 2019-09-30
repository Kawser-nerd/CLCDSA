import java.util.Scanner;

/**
 * http://abc004.contest.atcoder.jp/tasks/abc004_4
 */
public class Main {

	private static int dp[][];
	private static final int SIZE = 2000;
	private static int R;
	private static int G;
	private static int B;
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		R = sc.nextInt();
		G = sc.nextInt();
		B = sc.nextInt();
		sc.close();
		
		dp = new int[SIZE][R+G+B+1];
		for(int i=0; i<SIZE; i++){
			for(int j=0; j<R+G+B+1; j++){
				dp[i][j] = -1;
			}
		}
		
		System.out.println(dfs(0,R+G+B));
		
	}
	
	private static int dfs(int pos, int num){

		if(num==0){
			return 0;
		}
		
		if(dp[pos][num]>=0){
			return dp[pos][num];
		}
		
		int move = 0;
		if(num>G+B){
			move = Math.abs(SIZE/2-100-pos);
		}else if(num>B){
			move = Math.abs(SIZE/2-pos);
		}else if(num>0){
			move = Math.abs(SIZE/2+100-pos);
		}
		
		if(pos>=SIZE-num){
			dp[pos][num] = dfs(pos+1,num-1) + move;
		}else{
			dp[pos][num] = Math.min(dfs(pos+1,num),dfs(pos+1,num-1)+move);
		}
		return dp[pos][num];
	}

}