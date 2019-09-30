import java.util.ArrayList;
import java.util.Scanner;




class Main{


	static	ArrayList<Integer> one ;
	static	ArrayList<Integer> two ;
	static	ArrayList<Integer> three ;
	static	ArrayList<Integer> four ;
	static long pow = 1000000007;

	static int n;
	static int m;
	static int ans  = 0;
	static int[][] g;
	static boolean[] used;



	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);			//?????
		int	n =sc.nextInt();
		int	ma =sc.nextInt();
		int mb = sc.nextInt();
		int[] a = new int[40];
		int[] b = new int[40];
		int[] c = new int[40];

		for(int i = 0;i < n;i++){
			a[i] = sc.nextInt();
			b[i] = sc.nextInt();
			c[i] = sc.nextInt();
		}

		int dp[][][] = new int[41][401][401];
		int inf = 10000000;

		for(int i = 0;i <= n;i++){						//dp???
			for(int ca = 0;ca <= 400;ca++){
				for(int cb = 0;cb <= 400;cb++){
					dp[i][ca][cb] = inf;
				}
			}
		}

		dp[0][0][0] = 0;

		for(int i  =0;i < n;i++){
			for(int ca = 0;ca <= 400;ca++){
				for(int cb = 0;cb <= 400;cb++){
					if(dp[i][ca][cb] == inf){
						continue;
					}
					dp[i+1][ca][cb] = Math.min(dp[i+1][ca][cb], dp[i][ca][cb]);
					dp[i+1][ca+a[i]][cb+b[i]] = Math.min(dp[i+1][ca+a[i]][cb+b[i]], dp[i][ca][cb]+c[i]);
				}
			}
		}
		int ans = inf;
		for(int ca = 1;ca <= 400;ca++){
			for(int cb = 1;cb <= 400;cb++){
				if(ca*mb == cb*ma){
					ans = Math.min(ans, dp[n][ca][cb]);
				}
			}
		}
		
		if(ans == inf){
			ans = -1;
		}
		
		System.out.println(ans);





	}

}



class Pair implements Comparable{
	Character from;
	int end;
	@Override
	public int compareTo(Object other) {
		Pair otherpair = (Pair)other;

		return end - otherpair.end;
	}
}