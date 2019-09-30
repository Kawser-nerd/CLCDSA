import java.util.Scanner;

public class Main {

	static int[][] xy;
	static int[] two;
	static int N;
	static long[] dp;

	public static void main(String[] args) {
		// TODO ???????????????
		Scanner scan = new Scanner(System.in);
		N=scan.nextInt();
		int M=scan.nextInt();

		two = new int[N];
		two[0] = 1;
		for(int i=1;i<N;i++){
			two[i]=two[i-1]*2;
		}

		//x>y
		xy = new int[N][N];
		for(int i=0;i<M;i++){
			int x = scan.nextInt()-1;
			int y = scan.nextInt()-1;
//			xy[x][y]=1;
			xy[y][x]=-1;
		}

		dp = new long[two[N-1]*2];
		dp[0]=1;

		System.out.println(res(two[N-1]*2-1));


	}

	static long res(int bit){
		if(dp[bit]>0)return dp[bit];

		for(int i=0;i<N;i++){
			if((two[i]&bit)>0){
				if(admit(bit-two[i],i)){
					dp[bit]+=res(bit-two[i]);
				}
			}
		}

		return dp[bit];

	}

	static boolean admit(int bit,int k){
		//????bit?????????????k????
		for(int i=0;i<N;i++){
			if((two[i]&bit)>0){
				if(xy[i][k]==-1){
					return false;
				}
			}
		}

		return true;
	}
}