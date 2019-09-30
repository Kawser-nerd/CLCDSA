import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;


public class A {

	public static void main(String[] args) throws IOException {
		new A().run();
	}

	
	BufferedReader br;
	PrintWriter pw;
	
	int k, size;
	char[][] c;
	
	private void run() throws IOException {
		br = new BufferedReader(new FileReader("a.in"));
		pw = new PrintWriter("a.out");
		
		int tests = Integer.parseInt(br.readLine());
		for (int test = 1; test <= tests; test++) {
			k = Integer.parseInt(br.readLine());
			size = 2 * k - 1;
			c = new char[size][size];
			for (int i = 0; i < size; i++) {
				String s = br.readLine();
				for (int j = 0; j < size; j++) {
					if (j < s.length()) {
						c[i][j] = s.charAt(j);
					} else {
						c[i][j] = ' ';
					}
				}
			}
			
			boolean[] x = new boolean[size];
			for (int i = 0; i < size; i++) {
				x[i] = checkSym(i);
			}
			
			char[][] c2 = new char[size][size]; 
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					c2[i][j] = c[j][i];
				}
			}
			c = c2;
			
			boolean[] y = new boolean[size];
			for (int i = 0; i < size; i++) {
				y[i] = checkSym(i);
			}
			
			int result = Integer.MAX_VALUE;
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					if (x[i] && y[j]) {
						int dist = 0;
						for (int a = 0; a < size; a++) {
							for (int b = 0; b < size; b++) {
								if (c[a][b] != ' ') {
									int d = Math.abs(a - i) + Math.abs(b - j);
									dist = Math.max(dist, d);
								}
							}
						}
						
						if (dist < result) {
							result = dist;
						}
					}
				}
			}
			
			result++;
			result = result * result - k * k;
			
			pw.println("Case #" + test + ": " + result);
		}
		
		br.close();
		pw.close();
	}

	private boolean checkSym(int v) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (c[i][j] != ' ') {
					int ni = 2 * v - i;
					if (ni >= 0 && ni < size && c[ni][j] != c[i][j] && c[ni][j] != ' ') {
						return false;
					}
				}
			}
		}
		return true;
	}

}
