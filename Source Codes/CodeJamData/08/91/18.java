import java.util.*;
import java.io.*;

public class Y {
	public static void SUM(int[] arr, int x0, int step, int y) {
		int ind = x0 + step*y;
		for (int i = 0; i<y; i++) {
			arr[ind-step] += arr[ind];
			ind -= step;
		}
	}
	public static void main(String[] s) throws Exception{
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(r.readLine());
		for(int i = 0; i<T; i++) {
			int N = Integer.parseInt(r.readLine());
			int[][] A = new int[3][N+1];
			for(int j = 0; j<N; j++) {
				String[] spl = r.readLine().split(" ");
				A[0][j] = Integer.parseInt(spl[0]);
				A[1][j] = Integer.parseInt(spl[1]);
				A[2][j] = Integer.parseInt(spl[2]);
			}
			int best = -1;
			for(int x = 0; x<=N; x++) {
				for(int y = 0; y<=N; y++) {
					int a = A[0][x]+1;
					int b = A[1][y]+1;
					int c = 10003-a-b;
					if (c>=1) {
						int cnt = 0;
						for (int z = 0; z<N; z++) {
							if (A[0][z]<=a && A[1][z]<=b &&A[2][z]<=c) cnt++;
						}
						if (cnt>best) best = cnt;
					}
					a = A[0][x]+1;
					c = A[2][y]+1;
					b = 10003-a-c;
					if (b>=1) {
						int cnt = 0;
						for (int z = 0; z<N; z++) {
							if (A[0][z]<=a && A[1][z]<=b &&A[2][z]<=c) cnt++;
						}
						if (cnt>best) best = cnt;
					}
					b = A[1][x]+1;
					c = A[2][y]+1;
					a = 10003-b-c;
					if (a>=0) {
						int cnt = 0;
						for (int z = 0; z<N; z++) {
							if (A[0][z]<=a && A[1][z]<=b &&A[2][z]<=c) cnt++;
						}
						if (cnt>best) best = cnt;
					}
				}
			}
			System.out.println("Case #"+(i+1)+": "+best);
		}
	}
}