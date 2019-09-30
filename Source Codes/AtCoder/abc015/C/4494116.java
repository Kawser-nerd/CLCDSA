import java.util.Scanner;
public class Main {
	public static int N,K;
	public static String ans="Nothing";
	public static int a[][]=new int[5][5];
	public static void main(String[]args) {
		Scanner sc=new Scanner(System.in);
		N=sc.nextInt();
		K=sc.nextInt();
		for(int i=0;i<N;i++) {
			for(int j=0;j<K;j++)a[i][j]=sc.nextInt();
		}
		dfs(0,0);
		System.out.println(ans);
	}
	public static void dfs(int n,int value) {
		if(n==N) {
			if(value==0)ans="Found";
			return;
		}
		for(int i=0;i<K;i++)dfs(n+1,value^a[n][i]);
		 return;
	}
}