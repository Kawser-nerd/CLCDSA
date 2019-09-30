package round1B;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.text.DecimalFormat;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class B
{
	private static final DecimalFormat format = new DecimalFormat("0.0#####");

	public static void main(String[] args) throws Exception
	{
		final String round = "1B";
		String file = "B-large";
		
		BufferedReader br = new BufferedReader(new FileReader("round" + round + "/" + file + ".in"));
		PrintWriter writer = new PrintWriter(new FileWriter("round" + round + "/" + file + ".out." + System.currentTimeMillis()));

		final int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++)
		{
			String[] line;

			line = br.readLine().split("\\s");
			final int H = Integer.parseInt(line[0]);
			final int N = Integer.parseInt(line[1]);
			final int M = Integer.parseInt(line[2]);
			final Map map = new Map(N, M);
			for (int n = 0; n < N; n++)
			{
				line = br.readLine().split("\\s");
				for (int m = 0; m < M; m++)
					map.ceiling[n][m] = Integer.parseInt(line[m]);
			}
			for (int n = 0; n < N; n++)
			{
				line = br.readLine().split("\\s");
				for (int m = 0; m < M; m++)
					map.floor[n][m] = Integer.parseInt(line[m]);
			}

			double time = search(map, H, new Location(0, 0), true, new HashSet<Location>(), 0);

			System.out.println("Case #" + t + ": " + format.format(time));
			writer.println("Case #" + t + ": " + format.format(time));
		}
		writer.close();
	}

	static class Map
	{
		final int N;
		final int M;
		final int[][] floor;
		final int[][] ceiling;
		final double[][] visited;

		Map(int N, int M)
		{
			this.N = N;
			this.M = M;
			floor = new int[N][M];
			ceiling = new int[N][M];
			visited = new double[N][M];
			for (int n = 0; n < N; n++)
				Arrays.fill(visited[n], Double.MAX_VALUE);
		}

		public int floor(Location l)
		{
			return floor[l.row][l.column];
		}

		public int ceiling(Location l)
		{
			return ceiling[l.row][l.column];
		}

		public boolean visitedEarlier(Location l, double elapsed)
		{
			if (visited[l.row][l.column] <= elapsed)
				return true;

			visited[l.row][l.column] = elapsed;
			return false;
		}
	}

	static class Location
	{
		final int row;
		final int column;

		public Location(int row, int column)
		{
			super();
			this.row = row;
			this.column = column;
		}

		public Location move(int deltaRow, int deltaColumn)
		{
			return new Location(row + deltaRow, column + deltaColumn);
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
			Location other = (Location) obj;
			if (column != other.column)
				return false;
			if (row != other.row)
				return false;
			return true;
		}
	}

	public static double trySearch(Map map, int H, Location from, Location to, boolean starting, Set<Location> visiting, double elapsed)
	{
		if (Math.max(map.floor(from), map.floor(to)) + 50 > map.ceiling(to))
			return Double.POSITIVE_INFINITY;
		else if (map.floor(to) + 50 > map.ceiling(from))
			return Double.POSITIVE_INFINITY;

		double time = 0;

		if (H + 50 > map.ceiling(to))
		{
			time += (H - (map.ceiling(to) - 50)) / 10.0;
			H = map.ceiling(to) - 50;
			starting = false;
		}

		if (!starting)
		{
			if (H - map.floor(from) >= 20)
			{
				time += 1;
				H -= 10;
			}
			else
			{
				time += 10;
				H -= 100;
			}
		}

		return time + search(map, H, to, starting, visiting, elapsed + time);
	}

	public static double search(Map map, int H, Location location, boolean starting, Set<Location> visiting, double elapsed)
	{
		if (visiting.contains(location))
			return Double.POSITIVE_INFINITY;

		if (map.visitedEarlier(location, elapsed))
			return Double.POSITIVE_INFINITY;

		if (location.row == map.N - 1 && location.column == map.M - 1)
			return 0;

		visiting.add(location);

		double time = Double.MAX_VALUE;

		if (location.row > 0) // try North
			time = Math.min(time, trySearch(map, H, location, location.move(-1, 0), starting, visiting, elapsed));
		if (location.column > 0) // try West
			time = Math.min(time, trySearch(map, H, location, location.move(0, -1), starting, visiting, elapsed));
		if (location.row < map.N - 1) // try South
			time = Math.min(time, trySearch(map, H, location, location.move(1, 0), starting, visiting, elapsed));
		if (location.column < map.M - 1) // try East
			time = Math.min(time, trySearch(map, H, location, location.move(0, 1), starting, visiting, elapsed));

		visiting.remove(location);
		return time;
	}
}
