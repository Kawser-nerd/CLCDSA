import java.util.Scanner;

public class B {

	static int CASE;
	static Scanner in = new Scanner(System.in);
	
	public static void main(String[] args) {
		int T = in.nextInt();
		for (CASE=1; CASE<=T; ++CASE) {
			new B().go();
		}
	}
	
	int D = in.nextInt();
	int I = in.nextInt();
	int M = in.nextInt();
	int N = in.nextInt();
	int[] a = new int[N];
	
	boolean ok(int a, int b) {
		return Math.abs(a-b) <= M;
	}
	
	void go() {
		for (int i=0; i<N; ++i) {
			a[i] = in.nextInt();
		}
		int[] old = new int[256];
		for (int v : a) {
			int[] ny = new int[256];
			// Delete it:
			for (int i=0; i<256; ++i) {
				ny[i] = old[i] + D;
			}
			// Keep it:
			for (int i=0; i<256; ++i) {
				if (ok(i, v)) {
					ny[v] = Math.min(ny[v], old[i]);
				}
			}
			// Change it to 'i':
			for (int i=0; i<256; ++i) {
				for (int j=0; j<256; ++j) {
					if (ok(i, j)) {
						int diff = Math.abs(i-v);
						int nyv = old[j] + diff;
						ny[i] = Math.min(ny[i], nyv);
					}
				}
			}
			
			boolean changed = true;
			while (changed) {
				changed = false;
				
				// Insert 'i':
				for (int i=0; i<256; ++i) {
					for (int j=0; j<256; ++j) {
						if (ok(i,j)) {
							int nyv = ny[j] + I;
							if (nyv < ny[i]) {
								changed = true;
								ny[i] = nyv;
							}
						}
					}
				}
			}
			
			old = ny;
		}
		int ans = Integer.MAX_VALUE;
		for (int p : old) ans = Math.min(ans, p);
		System.out.println("Case #" + CASE + ": " + ans);
	}
	
}
