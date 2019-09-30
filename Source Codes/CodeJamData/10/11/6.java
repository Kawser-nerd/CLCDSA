import java.util.Scanner;

public class A {

	static int CASE;
	static Scanner in = new Scanner(System.in);
	
	public static void main(String[] args) {
		int T = in.nextInt();
		for (CASE=1; CASE<=T; ++CASE) {
			new A().go();
		}
	}
	
	int N, K;
	char[][] map;
	
	boolean has(char c) {
		return has(c, 0, 1) || has(c, 1, 0) || has(c, 1, 1) || has(c, -1, 1);
	}

	boolean has(char c, int dx, int dy) {
		for (int i=0; i<N; ++i) {
			for (int j=0; j<N; ++j) {
				boolean ok = true;
				for (int t=0; t<K; ++t) {
					int nyi = i + t*dx;
					int nyj = j + t*dy;
					if (nyi >= N || nyj >= N || nyi<0 || nyj<0 || map[nyi][nyj] != c) {
						ok = false;
						break;
					}
				}
				if (ok) return true;
			}
		}
		return false;
	}
	
	void go() {
		N = in.nextInt();
		K = in.nextInt();
		map = new char[N][N];
		for (int i=0; i<N; ++i) {
			map[i] = in.next().toCharArray();
		}
		for (int i=0; i<N; ++i) {
			for (int k=0; k<N; ++k) {
				for (int j=N-2; j>=0; --j) {
					if (map[i][j+1] == '.') {
						map[i][j+1] = map[i][j];
						map[i][j] = '.';
					}
				}
			}
//			System.out.println(new String(map[i]));
		}
		boolean blue = has('B');
		boolean red = has('R');
		String ans;
		if (blue && red) ans = "Both";
		else if (blue) ans = "Blue";
		else if (red) ans = "Red";
		else ans = "Neither";
		System.out.println("Case #" + CASE + ": " + ans);
	}
	
}
