import java.util.Scanner;

public class Pockets
{
	enum Direction
	{
		NORTH,
		EAST,
		SOUTH,
		WEST;
	}
	
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int numCases = in.nextInt();
		for (int i = 0; i < numCases; i++)
			doCase(i + 1, in);
	}

	private static void doCase(int caseNum, Scanner in)
	{
		int L = in.nextInt();
		StringBuilder path = new StringBuilder();
		for (int i = 0; i < L; i++)
		{
			String s = in.next();
			int rep = in.nextInt();
			for (int j = 0; j < rep; j++)
				path.append(s);
		}
		
		int x = 3002, y = 3002;
		Direction dir = Direction.NORTH;

		boolean[][] xWalls = new boolean[3001 + 3002][3001 + 3002];
		int[] numXWalls = new int[3001 + 3002];
		boolean[][] yWalls = new boolean[3001 + 3002][3001 + 3002];
		int[] numYWalls = new int[3001 + 3002];

		for (int i = 0; i < path.length(); i++)
		{
			char c = path.charAt(i);
			switch (c)
			{
			case 'F':
				switch (dir)
				{
				case NORTH:
					xWalls[x][y] = true;
					numXWalls[y]++;
					y++;
					break;
				case EAST:
					yWalls[x ][y] = true;
					numYWalls[x]++;
					x++;
					break;
				case SOUTH:
					y--;
					xWalls[x][y] = true;
					numXWalls[y]++;
					break;
				case WEST:
					x--;
					yWalls[x][y] = true;
					numYWalls[x]++;
					break;
				}
				break;
			case 'R':
				switch (dir)
				{
				case NORTH:
					dir = Direction.EAST;
					break;
				case EAST:
					dir = Direction.SOUTH;
					break;
				case SOUTH:
					dir = Direction.WEST;
					break;
				case WEST:
					dir = Direction.NORTH;
					break;
				}
				break;
			case 'L':
				switch (dir)
				{
				case NORTH:
					dir = Direction.WEST;
					break;
				case EAST:
					dir = Direction.NORTH;
					break;
				case SOUTH:
					dir = Direction.EAST;
					break;
				case WEST:
					dir = Direction.SOUTH;
					break;
				}
			}
		}
		
		if (x != 3002 || y != 3002)
			System.out.println("Problem!");
		
		boolean[][] points = new boolean[3001 + 3002][3001 + 3002];
		
		for (int i = 0; i < 3001 + 3002; i++)
		{
			int numCrosses = 0;
			for (int j = 0; j < 3001 + 3002; j++)
			{
				if (xWalls[j][i])
					numCrosses++;
				if (numCrosses == numXWalls[i])
					break;
				if (numCrosses != 0 && numCrosses % 2 == 0)
					points[j][i] = true;
			}
		}
		
		for (int i = 0; i < 3001 + 3002; i++)
		{
			int numCrosses = 0;
			for (int j = 0; j < 3001 + 3002; j++)
			{
				if (yWalls[i][j])
					numCrosses++;
				if (numCrosses == numYWalls[i])
					break;
				if (numCrosses != 0 && numCrosses % 2 == 0)
					points[i][j] = true;
			}
		}
		
		int pockets = 0;
		
		for (int i = 0; i < 3001 + 3002; i++)
			for (int j = 0; j < 3001 + 3002; j++)
				if (points[i][j])
				{
					//System.out.println((i - 3002) + " " + (j - 3002));
					pockets++;
				}
		
		System.out.println("Case #" + caseNum + ": " + pockets);
	}
}
