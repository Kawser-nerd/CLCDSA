import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int c = sc.nextInt();
		int[][] D=new int[c][c];
		int[][] C=new int[n][n];
		for(int i = 0; i<c; i++){
			for(int j = 0; j<c; j++){
				D[i][j]=sc.nextInt();
			}
		}
		for(int i = 0; i<n; i++){
			for(int j = 0; j<n; j++){
				C[i][j]=sc.nextInt();
			}
		}
		int[][] q=new int[3][c];
		for(int i = 0; i<n; i++){
			for(int j=0; j<n; j++){
				for(int k=0; k<c; k++){
					q[(i+j)%3][k]+=D[C[i][j]-1][k];
				}
			}
		}
		int ans=Integer.MAX_VALUE;
		for(int i = 0; i<c; i++){
			for(int j = 0; j<c; j++){
				for(int k = 0; k<c; k++){
					if(i!=j && i!=k && j!=k){
						ans=Math.min(ans,q[0][i]+q[1][j]+q[2][k]);
					}
				}
			}
		}
		System.out.println(ans);
	}
}