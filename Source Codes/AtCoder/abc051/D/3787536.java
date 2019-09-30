import java.util.Scanner;

class Main{




	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);			//?????
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[] a = new int[m];
		int[] b = new int[m];
		int[] c = new int[m];

		for(int i = 0;i < m;i++){
			a[i] = sc.nextInt();
			b[i] = sc.nextInt();
			c[i] = sc.nextInt();

		}
		
		
		
		int[][] map = new int[n+1][n+1];
		int inf = 1000000;

		

		for(int i = 1;i < n+1;i++){
			for(int j = 1;j < n+1;j++){
				map[i][j] = inf;
			}
		}

		for(int i = 0;i < m;i++){
			map[a[i]][b[i]] = c[i];
			map[b[i]][a[i]] = c[i];
		}
		for(int k = 1;k <= n;k++ ){
			for(int i = 1;i <= n;i++){
				for(int j = 1;j <= n;j++){
					map[i][j] = Math.min(map[i][j], map[i][k]+map[k][j]);
				}
			}
		}
//		for(int i = 0;i < m;i++){
//			System.out.println("a[i] "+a[i] +" b[i] "+b[i] +" " +map[a[i]][b[i]]);
//		}
		
		
		
		int ans = 0;
		for(int i = 0;i < m;i++){
			if(map[a[i]][b[i]] != c[i]){
				ans++;
			}
		}
		System.out.println(ans);
		
		



	}
}

class Pair implements Comparable{
	int from;
	int end;
	@Override
	public int compareTo(Object other) {
		Pair otherpair = (Pair)other;

		return end - otherpair.end;
	}
}