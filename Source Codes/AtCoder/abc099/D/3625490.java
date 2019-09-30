import java.util.Scanner;
	

public class Main{
	
	
	public static void main(String args[])throws Exception{
		
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int C = sc.nextInt();
		int[][] D = new int[C+1][C+1];
		int[][] c = new int[N+1][N+1];
		int[][] table = new int[3][C+1];
		
		for(int i=1;i<=C;i++){
			for(int j=1;j<=C;j++){
				D[i][j] = sc.nextInt();
			}
		}
		
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				int col = sc.nextInt();
				table[(i+j)%3][col]++;
			}
		}
		
		int[][] costable = new int[3][C+1];
		for(int i=0;i<3;i++){
			for(int j=1;j<=C;j++)
				for(int k=1;k<=C;k++){
					costable[i][k] += D[j][k]*table[i][j];
			}
		}
		int min = 260000000;
		for(int i=1;i<=C;i++){
			for(int j=1;j<=C;j++){
				for(int k=1;k<=C;k++){
					if(i!=j&&j!=k&&k!=i){
						min = Math.min(min, costable[0][i]+costable[1][j]+costable[2][k]);
					}
				}
			}
		}
		System.out.println(min);
	}
	
}