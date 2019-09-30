package round2;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class D
{
	private static final DecimalFormat format = new DecimalFormat("0.######");

	static class Cave
	{
		final int label;
		final Position position;
		Set<Position> reachable = new HashSet<Position>();
		boolean lucky = true;

		public Cave(int label, Position position)
		{
			this.label = label;
			this.position = position;
		}
	}

	static class Position
	{
		final int row;
		final int column;

		public Position(int row, int column)
		{
			super();
			this.row = row;
			this.column = column;
		}

		@Override
		public int hashCode()
		{
			final int prime = 31;
			int result = 1;
			result = prime * result + column;
			result = prime * result + row;
			return result;
		}

		@Override
		public boolean equals(Object obj)
		{
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Position other = (Position) obj;
			if (column != other.column)
				return false;
			if (row != other.row)
				return false;
			return true;
		}

		public Position unmove(int dr, int dc)
		{
			return new Position(row - dr, column - dc);
		}

		public Position move(int dr, int dc)
		{
			return new Position(row + dr, column + dc);
		}
	}

	public static void main(String[] args) throws Exception
	{
		final String round = "2";
		final String file = "D-small-attempt2";
		BufferedReader br = new BufferedReader(new FileReader("round" + round + "/" + file + ".in"));
		PrintWriter writer = new PrintWriter(new FileWriter("round" + round + "/" + file + ".out." + System.currentTimeMillis()));

		final int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++)
		{
			String[] line = br.readLine().split("\\s");
			final int R = Integer.parseInt(line[0]);
			final int C = Integer.parseInt(line[1]);
			char[][] map = new char[R][];
			for (int r = 0; r < R; r++)
				map[r] = br.readLine().toCharArray();

			System.out.println("Case #" + t + ":");
			writer.println("Case #" + t + ":");

			List<Cave> caves = new ArrayList<Cave>();
			for (int r = 0; r < R; r++)
			{
				for (int c = 0; c < C; c++)
				{
					if (Character.isDigit(map[r][c]))
					{
						Cave cave = new Cave(map[r][c] - '0', new Position(r, c));
						caves.add(cave);
						discover(cave.position, map, cave);

						Set<Position> baddies = new HashSet<Position>();
						for (Position p : cave.reachable)
						{
							Position bad = p.unmove(-1, 0);
							if (canMove(bad, map) && !cave.reachable.contains(bad))
								baddies.add(bad);
						}

						cave.lucky = findUniversal(cave.position, cave.reachable, baddies, map, new HashSet<Set<Position>>(), new HashSet<Set<Position>>());
					}
				}
			}
			Collections.sort(caves, new Comparator<Cave>()
			{
				@Override
				public int compare(Cave arg0, Cave arg1)
				{
					return arg0.label - arg1.label;
				}
			});

			for (Cave cave : caves)
			{
				System.out.println(cave.label + ": " + cave.reachable.size() + " " + (cave.lucky ? "Lucky" : "Unlucky"));
				writer.println(cave.label + ": " + cave.reachable.size() + " " + (cave.lucky ? "Lucky" : "Unlucky"));
			}
		}
		writer.close();
	}

	private static Set<Position> move(Set<Position> start, int dr, int dc, char[][] map)
	{
		Set<Position> moved = new HashSet<Position>();
		for (Position p1 : start)
		{
			Position p2 = p1.move(dr, dc);
			if (canMove(p2, map))
				moved.add(p2);
			else
				moved.add(p1);
		}
		return moved;
	}

	private static boolean findUniversal(Position cave, Set<Position> start, Set<Position> baddies, char[][] map, Set<Set<Position>> previous, Set<Set<Position>> failures)
	{
		if (start.size() == 1 && start.contains(cave))
			return true;

		if (failures.contains(start))
			return false;

		if (previous.add(start))
		{
			Set<Position> moved;
			// Down
			moved = move(start, 1, 0, map);
			if (!moved.removeAll(baddies))
			{
				if (findUniversal(cave, moved, baddies, map, previous, failures))
					return true;
			}
			// left
			moved = move(start, 0, -1, map);
			if (!moved.removeAll(baddies))
			{
				if (findUniversal(cave, moved, baddies, map, previous, failures))
					return true;
			}
			// right
			moved = move(start, 0, 1, map);
			if (!moved.removeAll(baddies))
			{
				if (findUniversal(cave, moved, baddies, map, previous, failures))
					return true;
			}
			previous.remove(start);
		}
		failures.add(start);
		return false;
	}

	private static boolean canMove(Position p, char[][] map)
	{
		if (p.row < 0 || p.column < 0 || p.row >= map.length || p.column >= map[0].length)
			return false;
		return map[p.row][p.column] != '#';
	}

	private static void discover(Position p, char[][] map, Cave cave)
	{
		if (canMove(p, map) && !cave.reachable.contains(p))
		{
			cave.reachable.add(p);
			discover(p.unmove(1, 0), map, cave);
			discover(p.unmove(0, -1), map, cave);
			discover(p.unmove(0, 1), map, cave);
		}
	}
}
