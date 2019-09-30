import java.util.Scanner;

class Main{



	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);			//?????
		int n = sc.nextInt();
		int m = sc.nextInt();
		int q = sc.nextInt();
		int[] L = new int[m];
		int[] R = new int[m];
		
		int[][] map = new int[n+1][n+1];
		for(int i= 0;i < m;i++){
			L[i] = sc.nextInt();
			R[i] = sc.nextInt();
			map[L[i]][R[i]]++;
		
		}
		int[][] sum =new int[n+1][n+1];
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				sum[i][j] = sum[i][j-1]+map[i][j];
			}
		}
		
		
		
		
		
		int[] P = new int[q];
		int[] Q = new int[q];
		for(int i= 0;i < q;i++){
			P[i] = sc.nextInt();
			Q[i] = sc.nextInt();
			long ans = 0;
			for(int j = P[i];j <= Q[i];j++){
				ans += sum[j][Q[i]] - sum[j][P[i]-1];
			}
			System.out.println(ans);
		}

		

		
	
	}


}

class Pair implements Comparable{
	int from;		//p
	int end;		//y
	int num;
	int bango;
	@Override
	public int compareTo(Object other) {
		Pair otherpair = (Pair)other;

		return from - otherpair.from;
	}
}