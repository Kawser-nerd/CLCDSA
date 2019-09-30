import java.util.Scanner;

public class NoCheating
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
		int[] broken = new int[H];
		for (int i = 0; i < H; i++)
		{
			String seats = in.next();
			for (int j = 0; j < W; j++)
				if (seats.charAt(j) == 'x')
					broken[i] |= 1 << j;
		}
		int[][] optimal = new int[H][1 << W];
		
		for (int i = 0; i < H; i++)
			for (int j = 0; j < (1 << W); j++)
				optimal[i][j] = -1;
		
		int max = 0;
		
		for (int i = 0; i < (1 << W); i++)
		{
			if (!isLegal(0, i, broken[H - 1]))
				continue;
			int newMax = calcOptimal(W, H, 0, i, optimal, broken);
			if (newMax > max)
				max = newMax;
		}
		
		System.out.println("Case #" + caseNum + ": " + max);
	}

	private static int calcOptimal(int W, int H, int h, int seats, int[][] optimal, int[] broken)
	{
		if (h == H - 1)
			return Integer.bitCount(seats);
		
		if (optimal[h][seats] != -1)
			return optimal[h][seats];
		
		int max = 0;

		for (int i = 0; i < (1 << W); i++)
		{
			if (isLegal(seats, i, broken[H - h - 2]))
			{
				int newMax = calcOptimal(W, H, h + 1, i, optimal, broken);
				if (newMax > max)
					max = newMax;
			}
		}
		
		return optimal[h][seats] = max + Integer.bitCount(seats);
	}

	private static boolean isLegal(int seats, int i, int broken)
	{
		return !((i & (i << 1)) != 0 || (i & (i >> 1)) != 0 ||
				(i & (seats << 1)) != 0 || (i & (seats >> 1)) != 0 ||
				(i & broken) != 0);
	}
}
