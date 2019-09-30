import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Oppa implements Runnable {
	public static void main(String[] args) throws IOException {
		new Thread(new Oppa()).start();
	}

	public void run() {
		try {
			run1();
		} catch (IOException e) {

		}
	}

	private void run1() throws IOException {
		Scanner sc = new Scanner(new FileReader("bonus.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("bonus.out"));
		int l = sc.nextInt();
		int d = sc.nextInt();
		int n = sc.nextInt();
		sc.nextLine();
		String[] s = new String[d];
		for(int i = 0; i < d; i++) {
			s[i] = sc.nextLine();
		}
		boolean[][] can = new boolean[l][256];
		for(int tn = 0; tn < n; tn++) {
			int res = 0;
			String a = sc.nextLine();
			int t = 0;
			for(int i = 0; i < l; i++) {
				if(Character.isLetter(a.charAt(t))) {
					can[i][a.charAt(t)] = true;
					t++;
				} else {
					t++;
					while(Character.isLetter(a.charAt(t))) {
						can[i][a.charAt(t)] = true;
						t++;
					}
					t++;
				}
			}
			for(int i = 0; i < d; i++) {
				int j = 0;
				while(j < l && can[j][s[i].charAt(j)]) j++;
				if(j == l) {
					res++;
				}
			}
			t = 0;
			for(int i = 0; i < l; i++) {
				if(Character.isLetter(a.charAt(t))) {
					can[i][a.charAt(t)] = false;
					t++;
				} else {
					t++;
					while(Character.isLetter(a.charAt(t))) {
						can[i][a.charAt(t)] = false;
						t++;
					}
					t++;
				}
			}
			pw.printf("Case #%d: %d\n", tn+1, res);
		}
		pw.close();
	}
}
