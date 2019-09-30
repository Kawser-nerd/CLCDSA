import java.io.File;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class B {
	
	public static void main(String[] args) throws Exception {
		Scanner in;
		PrintStream out;
		if (new File("b-large.in").exists()) {
			in = new Scanner(new File("b-large.in"));
			out = new PrintStream(new File("b-large.out"));
		} else if (new File("b-small.in").exists()) {
			in = new Scanner(new File("b-small.in"));
			out = new PrintStream(new File("b-small.out"));
		} else {
			in = new Scanner(new File("b-test.in"));
			out = System.out;
		}
		
		int T = in.nextInt();
		for (int caseNum = 1; caseNum <= T; caseNum++) {
			int N = in.nextInt();
			int P = in.nextInt();
			int[] R = new int[N];
			for (int i = 0; i < N; i++) {
				R[i] = in.nextInt();
			}
			int[][] Q = new int[N][P];
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < P; j++) {
					Q[i][j] = in.nextInt();
				}
			}
			int solution = solve(N, P, R, Q);
			
			out.printf("Case #%d: %d%n", caseNum, solution);
		}
		
		
		in.close();
		out.close();
	}
	
	private static int solve(int N, int P, int[] R, int[][] Q) {
		int res = 0;
		int[] indices = new int[N];
		for (int i = 0; i < N; i++) {
			Arrays.sort(Q[i]);
		}
		while (true) {
			int[] vals = new int[N];
			for (int i = 0; i < N; i++) {
				if (indices[i] == P) {
					return res;
				}
				vals[i] = Q[i][indices[i]];
			}
			int minServings = 0;
			int maxServings = Integer.MAX_VALUE;
			int maxI = -1;
			for (int i = 0; i < N; i++) {
				int min = (int)Math.ceil(vals[i] * 10.0 / 11.0 / R[i]);
				int max = (int)Math.floor(vals[i] * 10.0 / 9.0 / R[i]);
				minServings = Math.max(minServings, min);
				if (max < maxServings) {
					maxServings = max;
					maxI = i;
				}
			}
			if (minServings <= maxServings) {
				res++;
				for (int i = 0; i < N; i++) {
					indices[i]++;
				}
			} else {
				indices[maxI]++;
			}
		}
	}
	
	private static int solveBrute(int N, int P, int[] R, int[][] Q) {
		if (N == 1) {
			int val = R[0];
			int res = 0;
			for (int i : Q[0]) {
				double servings = i * 1.0 / val;
				double diff = Math.abs((servings - Math.round(servings)) / Math.round(servings));
				if (diff <= 0.1000000001) {
					res++;
				}
			}
			return res;
		} else {
			int max = 0;
			int v1 = R[0];
			int v2 = R[1];
			for (int[] perm : permutations(P)) {
				int count = 0;
				for (int i = 0; i < P; i++) {
					int j = perm[i];
					
					int iMin = (int)Math.ceil(Q[0][i] * 10.0 / 11.0 / v1);
					int iMax = (int)Math.floor(Q[0][i] * 10.0 / 9.0 / v1);
					if (iMin > iMax) continue;
					
					int jMin = (int)Math.ceil(Q[1][j] * 10.0 / 11.0 / v2);
					int jMax = (int)Math.floor(Q[1][j] * 10.0 / 9.0 / v2);
					if (jMin > jMax) continue;
					
					if (iMin <= jMax && jMin <= iMax) {
						count++;
					}
				}
				max = Math.max(max, count);
			}
			return max;
		}
	}
	
	private static void buildPerm(List<int[]> res, int[] arr, boolean[] used, int i) {
		int N = arr.length;
		if (N == i) {
			res.add(arr.clone());
			return;
		}
		for (int j = 0; j < N; j++) {
			if (used[j]) continue;
			used[j] = true;
			arr[i] = j;
			buildPerm(res, arr, used, i + 1);
			used[j] = false;
		}
	}
	
	private static List<int[]> permutations(int N) {
		ArrayList<int[]> res = new ArrayList<int[]>();
		buildPerm(res, new int[N], new boolean[N], 0);
		return res;
	}
}
