import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[][] friend = new int[n][n];
		for(int i = 0; i < m; i++){
			int a = sc.nextInt()-1;
			int b = sc.nextInt()-1;
			friend[a][b]=1;
			friend[b][a]=1;
		}
		for(int i = 0; i < n; i++){
			int[] c = new int[n];
			for(int j = 0; j < n; j++){
				if(i==j){
					continue;
				}
				if(friend[i][j]==1){
					for(int k = 0; k < n; k++){
						if(k==j || k==i){
							continue;
						}
						if(friend[j][k]==1){
							c[k]=1;
						}
					}
				}
			}
			int ans=0;
			for(int w = 0; w<n; w++){
				if(friend[i][w]==1){
					continue;
				}
				if(c[w]==1){
					ans++;
				}
			}
			System.out.println(ans);
		}
	}
}