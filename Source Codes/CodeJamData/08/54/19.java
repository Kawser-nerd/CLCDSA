import java.util.Scanner;

public class EndlessKnight
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int numCases = in.nextInt();
		for (int i = 0; i < numCases; i++)
			doCase(i + 1, in);
	}

	private static void doCase(int caseNum, Scanner in)
	{
		int H = in.nextInt();
		int W = in.nextInt();
		int R = in.nextInt();
		
		int[][] memoized = new int[W][H];
		for (int[] arr : memoized)
			for (int i = 0; i < arr.length; i++)
				arr[i] = -1;
		
		for (int i = 0; i < R; i++)
		{
			int rockY = in.nextInt();
			int rockX = in.nextInt();
			memoized[W - rockX][H - rockY] = 0;
		}
		
		int total = findMoves(W - 1, H - 1, memoized);
		
		System.out.println("Case #" + caseNum + ": " + total);
	}

	private static int findMoves(int i, int j, int[][] memoized)
	{
		if (i == 0 && j == 0)
			return 1;
		
		if (i < 1 || j < 1)
			return 0;
		
		if (memoized[i][j] != -1)
			return memoized[i][j];
		
		memoized[i][j] = (findMoves(i - 1, j - 2, memoized) + findMoves(i - 2, j - 1, memoized)) % 10007;
		return memoized[i][j];
	}
}
