import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int q = sc.nextInt();
		int[][] a = new int[n+1][n+1];
		int[][] p = new int[q][2];
		for(int i = 0; i<m; i++){
			int c = sc.nextInt();
			int b = sc.nextInt();
			a[c][b]++;
		}
		for(int i = n-1; i>=1; i--){
			for(int j=i; j<=n; j++){
				a[i][j]+=a[i+1][j]+a[i][j-1]-a[i+1][j-1];
			}
		}
		for(int i = 0; i<q; i++){
			int h = sc.nextInt();
			int w = sc.nextInt();
			p[i][0]=h;
			p[i][1]=w;
		}
		for(int i = 0; i<q; i++){
			System.out.println(a[p[i][0]][p[i][1]]);
		}
	}
}