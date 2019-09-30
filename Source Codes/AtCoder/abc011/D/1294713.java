import java.util.*;

public class Main {
	public static void main(String[] args) {
		HeySayJump jump = new HeySayJump();
		jump.exec();
	}
}

class HeySayJump {
	
	int N;
	int D;
	int X;
	int Y;
	
	PascalTriangle triangle;
	
	HeySayJump() {
		Scanner cin = new Scanner(System.in);
		this.N = cin.nextInt();
		this.D = cin.nextInt();
		this.X = cin.nextInt();
		this.Y = cin.nextInt();
	}
	
	void exec() {
		
		if (X % D != 0 || Y % D != 0) {
			System.out.println(0.0);
			return;
		}
		
		triangle = new PascalTriangle(N);
		
		X /= D;
		Y /= D;
		
		X = Math.abs(X);
		Y = Math.abs(Y);

		double allCount = 0;
		for (int i = 0; i <= N; i++) {
			
			int H = i;      // Horizon
			int V = N - H;  // Vertical
			
			if ((H + X) % 2 != 0 || (V + Y) % 2 != 0)
				continue;
			 
			int R = (H + X) / 2; // Right
			int U = (V + Y) / 2; // Up
			
			double count = 1;
			count *= triangle.combine(N, H);
			count *= triangle.combine(H, R);
			count *= triangle.combine(V, U);
			
			allCount += count;
		}
		
		System.out.println(allCount);
	}
	
	class PascalTriangle {
		
		int N;
		double[][] dp;
		
		PascalTriangle(int N) {
			this.N = N;
			this.dp = new double[N + 1][N + 1];
			this.buildTriangle();
			
			/*
			// MARK: Print Pascal Triangle
			System.out.println("====triangle====");
			for (int i = 0; i <= N; i++) {
				for (int j = 0; j <= i; j++) {
					System.out.print(dp[i][j] + " ");
				}
				System.out.println();
			}
			System.out.println("========");
			*/
		}
		
		void buildTriangle() {
			for (int i = 0; i <= N; i++) {
				dp[i][0] = 1 / Math.pow(2, i);
				dp[i][i] = 1 / Math.pow(2, i);
			}
			
			for (int i = 2; i <= N; i++) {
				for (int j = 1; j < i; j++) {
					dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) / 2;
				}
			}
		}
		
		double combine(int n, int k) {
			return dp[n][k];
		}
	}
	
}