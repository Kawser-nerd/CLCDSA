import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int q7 = sc.nextInt();
		int[][] q=new int[n+1][n+1];
		for(int i = 0; i < m; i++){
			int l = sc.nextInt();
			int r = sc.nextInt();
			q[l][r]++;
		}
		for(int i=n-1; i>=1; i--){
			for(int j=i; j<=n; j++){
				q[i][j]+=q[i+1][j]+q[i][j-1]-q[i+1][j-1];
			}
		}
		int[] p11=new int[q7];
		int[] p22=new int[q7];
		for(int i = 0; i<q7; i++){
			p11[i]=sc.nextInt();
			p22[i]=sc.nextInt();
		}
		for(int i=0; i<q7; i++){
			System.out.println(q[p11[i]][p22[i]]);
		}
	}
}