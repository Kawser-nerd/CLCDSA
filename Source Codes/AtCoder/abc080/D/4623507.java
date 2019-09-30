import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n =sc.nextInt();
		int C =sc.nextInt();
		int[][] ar=new int[C][100001];
		for(int i = 0; i<n; i++){
			int s = sc.nextInt()-1;
			int t = sc.nextInt()-1;
			int c = sc.nextInt()-1;
			for(int j=s; j<=t; j++){
				ar[c][j]=1;
			}
		}
		int ans=0;
		for(int i = 1; i<100001; i++){
			int max=0;
			for(int j = 0; j<C; j++){
				max+=ar[j][i];
			}
			ans=Math.max(ans,max);
		}
		System.out.println(ans);
	}
}