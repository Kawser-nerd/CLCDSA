import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long[][] dist = new long [n][n];
		for (int i=0;i<n;i++) {
			for (int j=0;j<n;j++) {
				dist[i][j]=sc.nextLong();
			}
		}

		System.out.println(calc(dist));
	}

	static long calc(long[][] dist) {
		int n = dist[0].length;
		boolean [][] omit = new boolean[n][n];


		for(int i=0;i<n;i++) {
			for (int j=i+1;j<n;j++) {
				for(int k=j+1;k<n;k++) {
					if (dist[i][j] + dist[i][k] < dist[j][k]) {
						return -1;
					} else if (dist[i][j] + dist[i][k] == dist[j][k]) {
						omit[j][k]=true;
					}

					if (dist[i][j] + dist[j][k] < dist[i][k]) {
						return -1;
					} else if (dist[i][j] + dist[j][k] == dist[i][k]) {
						omit[i][k]=true;
					}

					if (dist[i][k] + dist[j][k] < dist[i][j]) {
						return -1;
					} else if (dist[i][k] + dist[j][k] == dist[i][j]) {
						omit[i][j]=true;
					}
				}
			}
		}

		long total = 0;
		for(int i=0;i<n;i++) {
			for (int j=i+1;j<n;j++) {
				if(!omit[i][j]) {
					total += dist[i][j];
				}
			}
		}
		return total;
	}

}