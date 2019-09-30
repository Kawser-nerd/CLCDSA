import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	static Integer[][][][] memo;
	static boolean[][] AA;
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new File("B.in"));
		PrintWriter out = new PrintWriter(new File("B.out"));
		int T = sc.nextInt();
		for(int t=1;t<=T;t++){
			memo = new Integer[2][2][721][1440];
			int A = sc.nextInt();
			int B = sc.nextInt();
			AA = new boolean[2][1440];
			for(int a=0;a<A;a++){
				int S = sc.nextInt();
				int E = sc.nextInt();
				for(int b=S;b<E;b++){
					AA[0][b]=true;
				}
			}
			for(int a=0;a<B;a++){
				int S = sc.nextInt();
				int E = sc.nextInt();
				for(int b=S;b<E;b++){
					AA[1][b]=true;
				}
			}

			int N = Math.min(DP(0,0,0,0), DP(0,0,1,1));
			
			System.out.printf("Case #%d: %d%n", t, N);
			out.printf("Case #%d: %d%n", t, N);
		}
		out.close();
	}
	private static int DP(int i, int a, int p, int ss) {
		if(i==1440) return ss==p?0:1;
		if(AA[p][i]){
			return 987654321;
		}
		if(memo[ss][p][a][i]!=null){
			return memo[ss][p][a][i];
		}
		
		int ans = 987654321;
		if(a!=720){
			ans = Math.min(ans, DP(i+1,a+1,0,ss) + (p==0?0:1));
		}
		if((i-a)!=720){
			ans = Math.min(ans, DP(i+1,a,1,ss) + (p==1?0:1));
		}
		
		return memo[ss][p][a][i]=ans;
	}
}
