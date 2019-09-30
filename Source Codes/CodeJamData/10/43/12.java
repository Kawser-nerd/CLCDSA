import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class C {

	public static void main(String[] args) throws IOException {
		new C().run();
	}

	
	BufferedReader br;
	PrintWriter pw;
	
	private void run() throws IOException {
		br = new BufferedReader(new FileReader("c.in"));
		pw = new PrintWriter("c.out");
		
		int tests = Integer.parseInt(br.readLine());
		for (int test = 1; test <= tests; test++) {
			int n = Integer.parseInt(br.readLine());
			int[] x1 = new int[n];
			int[] y1 = new int[n];
			int[] x2 = new int[n];
			int[] y2 = new int[n];
			
			int[] xx = new int[2 * n];
			int[] yy = new int[2 * n];
			int xc = 0;
			int yc = 0;
			
			for (int i = 0; i < n; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				x1[i] = Integer.parseInt(st.nextToken());
				xx[xc++] = x1[i];
				y1[i] = Integer.parseInt(st.nextToken());
				yy[yc++] = y1[i];
				x2[i] = Integer.parseInt(st.nextToken()) + 1;
				xx[xc++] = x2[i];
				y2[i] = Integer.parseInt(st.nextToken()) + 1;
				yy[yc++] = y2[i];
			}
			
			xx = unique(xx, xc);
			xc = xx.length;
			yy = unique(yy, yc);
			yc = yy.length;
			
			int[][] c = new int[xc][yc];
			for (int i = 0; i < n; i++) {
				x1[i] = Arrays.binarySearch(xx, x1[i]);
				y1[i] = Arrays.binarySearch(yy, y1[i]);
				x2[i] = Arrays.binarySearch(xx, x2[i]);
				y2[i] = Arrays.binarySearch(yy, y2[i]);
				for (int a = x1[i]; a < x2[i]; a++) {
					c[a][y1[i]]++;
					c[a][y2[i]]--;
				}
			}
			for (int i = 0; i < xc; i++) {
				int d = 0;
				for (int j = 0; j < yc; j++) {
					d += c[i][j];
					if (d > 0) {
						c[i][j] = 1;
					} else {
						c[i][j] = 0;
					}
				}
			}
			
			for (int i = 1; i < xc - 1; i++) {
				for (int j = 1; j < yc - 1; j++) {
					if (c[i - 1][j] == 1 && c[i][j - 1] == 1) {
						c[i][j] = 1;
					}
				}
			}
			
			int result = 0;
			for (int i = xc - 2; i >= 0; i--) {
				for (int j = yc - 2; j >= 0; j--) {
					if (c[i][j] == 1) {
						int d = xx[i + 1] - xx[i] + yy[j + 1] - yy[j] - 1;
						if (c[i + 1][j] > 0 && c[i + 1][j] + xx[i + 1] - xx[i] > d) {
							d = c[i + 1][j] + xx[i + 1] - xx[i];
						}
						if (c[i][j + 1] > 0 && c[i][j + 1] + yy[j + 1] - yy[j] > d) {
							d = c[i][j + 1] + yy[j + 1] - yy[j];
						}
						c[i][j] = d;
						if (c[i][j] > result) {
							result = c[i][j];
						}
					} else {
						c[i][j] = 0;
					}
				}
			}
			
			pw.println("Case #" + test + ": " + result);
		}
		
		br.close();
		pw.close();
	}

	private int[] unique(int[] x, int len) {
		Arrays.sort(x);
		int n = 1;
		for (int i = 1; i < len; i++) {
			if (x[i] != x[n - 1]) {
				x[n] = x[i];
				n++;
			}
		}
		int[] r = new int[n];
		System.arraycopy(x, 0, r, 0, n);
		return r;
	}

}
