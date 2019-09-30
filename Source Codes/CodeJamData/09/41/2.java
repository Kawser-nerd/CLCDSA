import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class BaiA {

	public static void main(String[] args) throws Exception {
		//Scanner sc = new Scanner(System.in);
		//PrintWriter pw = new PrintWriter(System.out);
		Scanner sc = new Scanner(new FileReader("A-large.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("out.txt"));
		int ntest = sc.nextInt();
		for (int test = 1; test <= ntest; ++test) {
			int n = sc.nextInt();
			char[][] a = new char[n][];
			int[] last = new int[n];
			sc.nextLine();
			for (int i = 0; i < n; ++i) {
				a[i] = sc.nextLine().toCharArray();
				last[i] = -1;
				for (int j = 0; j < n; ++j)
					if (a[i][j] == '1')
						last[i] = j;
			}
			int res = 0;
			for (int i = 0; i < n; ++i)
				if (last[i] > i) {
					for (int j = i + 1; j < n; ++j)
						if (last[j] <= i) {
							res += j - i;
							int t = last[j];
							for (int k = j - 1; k >= i; --k)
								last[k + 1] = last[k];
							last[i] = t;
							break;
						}
				}
			pw.println("Case #" + test + ": " + res);
		}
		pw.close();
		sc.close();
	}
}
