import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main implements Runnable {

	public static void main(String[] args) throws IOException {
		new Thread(new Main()).start();
	}
	
	public void run() {
		try {
			run1();
		} catch (IOException e) {
			throw new RuntimeException();
		}
	}
	
	int[] get(char c) {
		if(c == 'o')
			return new int[]{'o'-'a', 26};
		if(c == 'i')
			return new int[]{'i'-'a', 27};
		if(c == 'e')
			return new int[]{'e'-'a', 28};
		if(c == 'a')
			return new int[]{'a'-'a', 29};
		if(c == 's')
			return new int[]{'s'-'a', 30};
		if(c == 't')
			return new int[]{'t'-'a', 31};
		if(c == 'b')
			return new int[]{'b'-'a', 32};
		if(c == 'g')
			return new int[]{'g'-'a', 33};
		return new int[]{c - 'a'};
	}
	
	public void run1() throws IOException {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int tN = sc.nextInt();
		sc.nextLine();
		for (int tn = 0; tn < tN; tn++) {
			int k = sc.nextInt();
			sc.nextLine();
			char[] s = sc.nextLine().toCharArray();
			int n = 26 + 8;
			boolean[][] can = new boolean[n][n];
			for(int i = 0; i < s.length - 1; i++) {
				int[] vals1 = get(s[i]);
				int[] vals2 = get(s[i + 1]);
				for(int u = 0; u < vals1.length; u++)
					for(int v = 0; v < vals2.length; v++) {
						can[vals1[u]][vals2[v]] = true;
					}
			}
			int sum = 0;
			int all = 0;
			for(int i = 0; i < n; i++) {
				int tmp = 0;
				for(int j = 0; j < n; j++) {
					if(can[i][j]) {
						tmp++;
						all++;
					}
					if(can[j][i])
						tmp--;
				}
				sum += Math.abs(tmp);
			}
			int res = all + sum / 2;
			if(sum == 0)
				res = all + 1;
			pw.println("Case #" + (tn + 1) + ": " + res);
		}
		pw.close();
	}
}
