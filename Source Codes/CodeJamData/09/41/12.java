import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;

public class A implements Runnable {

	public static void main(String[] args) {
		new Thread(new A()).start();
	}

	public void run() {
		try {
			solve();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	private void solve() throws Exception {
		BufferedReader br = new BufferedReader(new FileReader("a.in"));
		PrintWriter pw = new PrintWriter("a.out");
		
		int tests = Integer.parseInt(br.readLine().trim());
		for (int test = 1; test <= tests; test++) {
			int n = Integer.parseInt(br.readLine().trim());
			String[] s = new String[n];
			for (int i = 0; i < n; i++) {
				s[i] = br.readLine().trim();
			}
			
			int result = 0;
			for (int row = 0; row < n; row++) {
				for (int i = row; i < n; i++) {
					boolean can = true;
					for (int k = row + 1; k < n; k++) {
						if (s[i].charAt(k) == '1') {
							can = false;
							break;
						}
					}
					if (can) {
						for (int k = i - 1; k >= row; k--) {
							String str = s[k + 1];
							s[k + 1] = s[k];
							s[k] = str;
							result++;
						}
						break;
					}
				}
			}
			
			pw.println("Case #" + test + ": " + result);
		}
		
		br.close();
		pw.close();
	}

}
