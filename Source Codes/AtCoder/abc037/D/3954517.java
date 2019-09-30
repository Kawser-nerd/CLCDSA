import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
	static final int INIT = -1;
	static final int M = 1000000000 + 7;
	static int H, W;
	static int[][] a, route, memo;
	static int[] di =
		{ -1, 0, 1, 0 };
	static int[] dj =
		{ 0, 1, 0, -1 };

	static int rec(int i, int j)
	{//[i][j]????????
		if (!(1 <= i && i <= H && 1 <= j && j <= W))
		{
			return 0;
		}
		if (memo[i][j] != INIT)
		{
			return memo[i][j];
		}
		for (int k = 0; k < di.length; k++)
		{
			int adi = i + di[k], adj = j + dj[k];
			if (a[adi][adj] < a[i][j])
			{
				route[i][j] = (route[i][j] + rec(adi, adj)) % M;
			}
		}
		return memo[i][j] = route[i][j];
	}

	public static void main(String[] args) throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] input = br.readLine().split(" ");
		H = Integer.valueOf(input[0]);
		W = Integer.valueOf(input[1]);
		a = new int[H + 2][W + 2];
		memo = new int[H + 2][W + 2];
		route = new int[H + 2][W + 2];
		for (int i = 1; i <= H; i++)
		{
			input = br.readLine().split(" ");
			for (int j = 1; j <= W; j++)
			{
				a[i][j] = Integer.valueOf(input[j - 1]);
				memo[i][j] = INIT;
				route[i][j] = 1;
			}
		}
		br.close();
		int ans = 0;
		for (int i = 1; i <= H; i++)
		{
			for (int j = 1; j <= W; j++)
			{
				ans = (ans + rec(i, j)) % M;
			}
		}
		System.out.println(ans);
	}

	static void print(int[][] arr)
	{
		for (int i = 1; i <= H; i++)
		{
			for (int j = 1; j <= W; j++)
			{
				System.out.printf("%2d ", arr[i][j]);
			}
			System.out.println();
		}
	}
}