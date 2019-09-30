import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class C {

	public static void main(String[] args) throws IOException {

		String welcome = "welcome to code jam";
		int w = welcome.length();

		BufferedReader buffer = new BufferedReader(new InputStreamReader(
				System.in));
		String entrada = buffer.readLine();
		int n = Integer.parseInt(entrada);

		for (int k = 1; k <= n; k++) {
			entrada = buffer.readLine();
			int t = entrada.length();

			int dp[][] = new int[t + 1][w + 1];
			for (int i = 0; i <= t; i++) {
				dp[i][0] = 1;
			}
			for (int j = 0; j <= w; j++) {
				dp[0][j] = 0;
			}
			for (int i = 1; i <= t; i++) {
				for (int j = 1; j <= w; j++) {
					dp[i][j] = dp[i - 1][j]
							+ ((entrada.charAt(i - 1) == welcome.charAt(j - 1)) ? (dp[i][j - 1])
									: (0));
					dp[i][j] %= 10000;
				}
			}

			System.out.println("Case #" + k + ": "
					+ new Integer(dp[t][w] + 10000).toString().substring(1, 5));

		}

	}

}
