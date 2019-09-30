import java.util.Scanner;

class Main{

	static int ans = Integer.MAX_VALUE;
	static	boolean[] flag ;
	static	int[][] dp ;
	static	int count = 0;
	static 	int[] r ;

	public static void main(String[] args) {



		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		int M = scanner.nextInt();
		int R = scanner.nextInt();

		r = new int[R];
		for(int i= 0;i <  R;i++){
			r[i] = scanner.nextInt();

		}

		flag = new boolean[R];

		int[] A = new int [M+1];
		int[] B = new int [M+1];
		int[] C = new int [M+1];

		dp =  new int[201][201];
		
		for(int i = 1; i < N+1;i++){
			for(int j = 1;j < N+1;j++){
				if(i != j){
					dp[i][j] = Integer.MAX_VALUE/2;
				}
			}
		}

		for(int i =1 ;i < M+1;i++){
			int a = scanner.nextInt();
			int b = scanner.nextInt();
			int c = scanner.nextInt();

			dp[a][b] = c;
			dp[b][a] = c;

		}


		for(int k = 1;k < N+1;k++){
			for(int i = 1;i < N+1;i++){
				for(int j = 1;j < N+1;j++){
					dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k][j]);
				}
			}
		}

	

		dps(r,0,0,0);

		System.out.println(ans);

	}

	static void dps(int[] r,int p,int sum ,int count){


		if(count == r.length){
			ans = Math.min(sum, ans);
			return ;
		}

		for(int i = 0;i < r.length;i++){


			if(!flag[i]){
				flag[i] = true;
				if(p == 0){
					dps(r, r[i], 0, count+1);	
				}else{
					dps(r, r[i], sum+dp[p][r[i]], count+1);	
				}
				flag[i] = false;

			}
		}

	}
}

class Pair implements Comparable{
	int from;
	int middle;
	int end;
	@Override
	public int compareTo(Object other) {
		Pair otherpair = (Pair)other;

		return end - otherpair.end;
	}
}