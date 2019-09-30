import java.util.Scanner;
import java.util.Arrays;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[][] ar=new int[n][n];
		for(int i = 0; i<n; i++){
			Arrays.fill(ar[i],Integer.MAX_VALUE/2);
		}
		int[] a=new int[m];
		int[] b=new int[m];
		int[] c = new int[m];
		for(int i = 0; i<m; i++){
			a[i]= sc.nextInt()-1;
			b[i]= sc.nextInt()-1;
			c[i]= sc.nextInt();
			ar[a[i]][b[i]]=c[i];
			ar[b[i]][a[i]]=c[i];
		}
		for(int i = 0; i<n; i++){
			for(int j = 0; j<n; j++){
				for(int k = 0; k<n; k++){
					if(i!=j && j!=k && i!=k){
						ar[j][k]=Math.min(ar[j][k],ar[j][i]+ar[i][k]);
					}
				}
			}
		}
		int ans=0;
		for(int i = 0; i<m; i++){
			if(ar[a[i]][b[i]]<c[i]){
				ans++;
			}
		}
		System.out.println(ans);
	}
}