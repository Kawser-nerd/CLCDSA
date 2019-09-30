import java.util.Scanner;


public class Kings
{

	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int numCases = in.nextInt();
		for (int i = 0; i < numCases; i++)
		{
			doCase(in, i + 1);
		}
	}

	private static void doCase(Scanner in, int caseNum)
	{
		int R = in.nextInt();
		int C = in.nextInt();
		boolean[][] board = new boolean[R][C];
		int x = 0, y = 0;
		for (int i = 0; i < R; i++)
		{
			String line = in.next();
			for (int j = 0; j < line.length(); j++)
			{
				switch (line.charAt(j))
				{
				case 'K':
					x = i;
					y = j;
					break;
				case '#':
					board[i][j] = true;
				}
			}
		}

		if (aliceWins(board, x, y, true))
			System.out.println("Case #" + caseNum + ": A");
		else
			System.out.println("Case #" + caseNum + ": B");
	}

	private static boolean aliceWins(boolean[][] board, int x, int y, boolean aliceMoves)
	{
		board[x][y] = true;
		try
		{
			for (int i = -1; i < 2; i++)
				for (int j = -1; j < 2; j++)
						if (legal(board, x + i, y + j) && aliceWins(board, x + i, y + j, !aliceMoves) == aliceMoves)
								return aliceMoves;
		}
		finally
		{
			board[x][y] = false;
		}
		return !aliceMoves;
	}

	private static boolean legal(boolean[][] board, int x, int y)
	{
		return x >= 0 && y >= 0 && x < board.length && y < board[0].length && !board[x][y];
	}
}
