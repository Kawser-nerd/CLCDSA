import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class SavingTheUniverse {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("A-large.in"));
		// BufferedReader br = new BufferedReader(new
		// InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter("A.out");

		int n = Integer.parseInt(br.readLine());
		for (int t = 0; t < n; t++) {
			int s = Integer.parseInt(br.readLine());
			String name[] = new String[s];
			for (int i = 0; i < s; i++)
				name[i] = br.readLine();
			int q = Integer.parseInt(br.readLine());
			int ans[][] = new int[q + 1][s];
			for (int i = 0; i < q; i++) {
				String qs = br.readLine();
				int min = ans[i][0];
				for (int j : ans[i])
					min = Math.min(min, j);
				for (int j = 0; j < s; j++)
					if (name[j].equals(qs))
						ans[i + 1][j] = 1000000;
					else
						ans[i + 1][j] = Math.min(ans[i][j], min + 1);
			}

			int a = ans[q][0];
			for (int i : ans[q])
				a = Math.min(a, i);
			pw.println("Case #" + (t + 1) + ": " + a);
		}

		pw.close();
	}

}
