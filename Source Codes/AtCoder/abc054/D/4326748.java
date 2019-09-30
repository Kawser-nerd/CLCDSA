import java.util.Arrays;
import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		int Ma=sc.nextInt();
		int Mb=sc.nextInt();
		int[][][] dp=new int[41][401][401];
		int INF=1000000007;
		for(int i=0; i<=40; i++) {
			for(int j=0; j<=400; j++) {
				Arrays.fill(dp[i][j],INF);
			}
		}
		dp[0][0][0]=0;
		int[][] kusuri=new int[N][3];
		for(int i=0; i<N; i++) {
			kusuri[i][0]=sc.nextInt();
			kusuri[i][1]=sc.nextInt();
			kusuri[i][2]=sc.nextInt();
		}
		for(int i=0; i<N; i++) {
			for(int j=0; j<=400; j++) {
				for(int k=0; k<=400; k++) {
					if(dp[i][j][k]<INF) {
						dp[i+1][j][k]=Math.min(dp[i+1][j][k],dp[i][j][k]);
						dp[i+1][j+kusuri[i][0]][k+kusuri[i][1]]=Math.min(dp[i+1][j+kusuri[i][0]][k+kusuri[i][1]],dp[i][j][k]+kusuri[i][2]);
					}
				}
			}
		}
		int min=114514810;
		int counter=1;
		while(Ma*counter<=400 && Mb*counter<=400) {
			min=Math.min(dp[N][Ma*counter][Mb*counter],min);
			counter++;
		}
		if(min==114514810){
			System.out.println(-1);
		}
		else{
			System.out.println(min);
		}
	}
}