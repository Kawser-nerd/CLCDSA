import java.io.*;
import java.util.*;
import java.math.*;

class D
{
	private static final boolean DEBUG_ON = true;
	private static final boolean ECHO_ON = true;

	private static BufferedReader input;
	private static BufferedWriter output;

	private static final int INF = Integer.MAX_VALUE / 2;
	private static final int MOD = 10007;

	private static int H, W, D, row, col;

	public static int gcd(int n, int m) {return (0 == m) ? (n) : gcd(m, n % m);}

	public static int sqrt(int X)
	{
		int answer = 1, interval = 1;
		for (int i = String.valueOf(X).length() / 2; i > 0; i--) {interval *= 10;}
		while (interval >= 1)
		{
			while ((answer * answer) <= X) {answer += interval;}
			answer -= interval;
			interval /= 10;
		}
		return answer;
	}

	public static void main(String[] args)
	{
		try
		{
			input = new BufferedReader(new FileReader(args[0]  + ".in"));
			output = new BufferedWriter(new FileWriter(args[0] + ".out"));

			String line = input.readLine();
			int testcases = getInt(line, 0);

			for (int testcase = 1; testcase <= testcases; testcase++)
			{
				char[][] real = getCharMatrix(input);

				HashSet<Integer> valid = new HashSet<Integer>();

				for (int i = row - D; i <= row + D; i++)
				{
					int range = sqrt((D * D) - ((i - row) * (i - row)));

					for (int j = col - range; j <= col + range; j++)
					{
						int diffX = i - row;
						int diffY = j - col;
						if (0 == diffX && 0 == diffY) {continue;}

						int gcd = gcd(Math.abs(diffX), Math.abs(diffY));
						int direction = (((diffX/gcd) + D) << 16) + ((diffY/gcd) + D);
						if (valid.contains(direction)) {continue;}

						int x = 100 * row + 50;
						int y = 100 * col + 50;

						for (int k = 0; k < 100; k++)
						{
							int nextX = x + diffX;
							int nextY = y + diffY;
							int xCell = x / 100;
							int yCell = y / 100;
							int nextXCell = nextX / 100; if (0 == nextX % 100) {nextXCell = (nextX + diffX) / 100;}
							int nextYCell = nextY / 100; if (0 == nextY % 100) {nextYCell = (nextY + diffY) / 100;}

							if (xCell == nextXCell && yCell == nextYCell) {x = nextX; y = nextY;}
							else if (xCell != nextXCell && yCell == nextYCell)
							{
								if ('#' != real[nextXCell][nextYCell]) {x = nextX; y = nextY;}
								else
								{
									diffX = -diffX;
									if (nextXCell < xCell) {x = (100 * (nextXCell + 1)) - (x - (100 * (nextXCell + 1)));}
									else {x = (100 * nextXCell) + ((100 * nextXCell) - x);}
									x = x + diffX; y = y + diffY;
								}
							}
							else if (xCell == nextXCell && yCell != nextYCell)
							{
								if ('#' != real[nextXCell][nextYCell]) {x = nextX; y = nextY;}
								else
								{
									diffY = -diffY;
									if (nextYCell < yCell) {y = (100 * (nextYCell + 1)) - (y - (100 * (nextYCell + 1)));}
									else {y = (100 * nextYCell) + ((100 * nextYCell) - y);}
									x = x + diffX; y = y + diffY;
								}
							}
							else
							{
								int cornerX = -1, cornerY = -1;

								if (nextXCell < xCell && nextYCell < yCell) {cornerX = 100 * (nextXCell + 1); cornerY = 100 * (nextYCell + 1);}
								else if (nextXCell > xCell && nextYCell < yCell) {cornerX = 100 * nextXCell; cornerY = 100 * (nextYCell + 1);}
								else if (nextXCell < xCell && nextYCell > yCell) {cornerX = 100 * (nextXCell + 1); cornerY = 100 * nextYCell;}
								else if (nextXCell > xCell && nextYCell > yCell) {cornerX = 100 * nextXCell; cornerY = 100 * nextYCell;}

								if ('#' == real[nextXCell][nextYCell] && '#' == real[xCell][nextYCell] && '#' == real[nextXCell][yCell])
								{
									diffX = -diffX; diffY = -diffY;
									if (nextXCell < xCell) {x = (100 * (nextXCell + 1)) - (x - (100 * (nextXCell + 1)));}
									else {x = (100 * nextXCell) + ((100 * nextXCell) - x);}
									if (nextYCell < yCell) {y = (100 * (nextYCell + 1)) - (y - (100 * (nextYCell + 1)));}
									else {y = (100 * nextYCell) + ((100 * nextYCell) - y);}
									x = x + diffX; y = y + diffY;
								}
								else if ('#' == real[nextXCell][nextYCell] && '#' == real[xCell][nextYCell] && '#' != real[nextXCell][yCell])
								{
									diffY = -diffY;
									if (nextYCell < yCell) {y = (100 * (nextYCell + 1)) - (y - (100 * (nextYCell + 1)));}
									else {y = (100 * nextYCell) + ((100 * nextYCell) - y);}
									x = x + diffX; y = y + diffY;
								}
								else if ('#' == real[nextXCell][nextYCell] && '#' != real[xCell][nextYCell] && '#' == real[nextXCell][yCell])
								{
									diffX = -diffX;
									if (nextXCell < xCell) {x = (100 * (nextXCell + 1)) - (x - (100 * (nextXCell + 1)));}
									else {x = (100 * nextXCell) + ((100 * nextXCell) - x);}
									x = x + diffX; y = y + diffY;
								}
								else if ('#' != real[nextXCell][nextYCell] && '#' == real[xCell][nextYCell] && '#' == real[nextXCell][yCell])
								{
									if ((cornerX - x) * (nextY - y) == (nextX - x) * (cornerY - y)) {x = nextX; y = nextY;} // passing corner
									else
									{
										diffX = -diffX; diffY = -diffY;
										if (nextXCell < xCell) {x = (100 * (nextXCell + 1)) - (x - (100 * (nextXCell + 1)));}
										else {x = (100 * nextXCell) + ((100 * nextXCell) - x);}
										if (nextYCell < yCell) {y = (100 * (nextYCell + 1)) - (y - (100 * (nextYCell + 1)));}
										else {y = (100 * nextYCell) + ((100 * nextYCell) - y);}
										x = x + diffX; y = y + diffY;
									}
								}
								else if ('#' == real[nextXCell][nextYCell] && '#' != real[xCell][nextYCell] && '#' != real[nextXCell][yCell])
								{
									if ((cornerX - x) * (nextY - y) == (nextX - x) * (cornerY - y)) {break;} // hitting corner
									else if (Math.abs((cornerX - x) * (nextY - y)) < Math.abs((nextX - x) * (cornerY - y))) // hitting Y
									{
										diffY = -diffY;
										if (nextYCell < yCell) {y = (100 * (nextYCell + 1)) - (y - (100 * (nextYCell + 1)));}
										else {y = (100 * nextYCell) + ((100 * nextYCell) - y);}
										x = x + diffX; y = y + diffY;
									}
									else
									{
										diffX = -diffX;
										if (nextXCell < xCell) {x = (100 * (nextXCell + 1)) - (x - (100 * (nextXCell + 1)));}
										else {x = (100 * nextXCell) + ((100 * nextXCell) - x);}
										x = x + diffX; y = y + diffY;
									}
								}
								else if ('#' != real[nextXCell][nextYCell] && '#' == real[xCell][nextYCell] && '#' != real[nextXCell][yCell])
								{
									if (Math.abs((cornerX - x) * (nextY - y)) <= Math.abs((nextX - x) * (cornerY - y))) {x = nextX; y = nextY;}
									else
									{
										diffY = -diffY;
										if (nextYCell < yCell) {y = (100 * (nextYCell + 1)) - (y - (100 * (nextYCell + 1)));}
										else {y = (100 * nextYCell) + ((100 * nextYCell) - y);}
										x = x + diffX; y = y + diffY;
									}
								}
								else if ('#' != real[nextXCell][nextYCell] && '#' != real[xCell][nextYCell] && '#' == real[nextXCell][yCell])
								{
									if (Math.abs((cornerX - x) * (nextY - y)) >= Math.abs((nextX - x) * (cornerY - y))) {x = nextX; y = nextY;}
									else
									{
										diffX = -diffX;
										if (nextXCell < xCell) {x = (100 * (nextXCell + 1)) - (x - (100 * (nextXCell + 1)));}
										else {x = (100 * nextXCell) + ((100 * nextXCell) - x);}
										x = x + diffX; y = y + diffY;
									}
								}
								else if ('#' != real[nextXCell][nextYCell] && '#' != real[xCell][nextYCell] && '#' != real[nextXCell][yCell]) {x = nextX; y = nextY;}
							}

							if ((100 * row + 50) == x && (100 * col + 50) == y) {valid.add(direction); break;}
						}
					}
				}

				String result = "Case #" + testcase + ": " + valid.size();
				output(result);
			}

			input.close();
			output.close();
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
	}

	public static int getInt(String line, int index) {return Integer.parseInt(getString(line, index));}
	public static long getLong(String line, int index) {return Long.parseLong(getString(line, index));}
	public static double getDouble(String line, int index) {return Double.parseDouble(getString(line, index));}
	public static String getString(String line, int index)
	{
		line = line.trim();
		while (index > 0) {line = line.substring(line.indexOf(' ') + 1); index--;}

		if ((-1) == line.indexOf(' ')) {return line;}
		else {return line.substring(0, line.indexOf(' '));}
	}

	public static int[] getIntArray(String line)
	{
		String[] strings = getStringArray(line);
		int[] numbers = new int[strings.length];
		for (int i = 0; i < strings.length; i++) {numbers[i] = Integer.parseInt(strings[i]);}
		return numbers;
	}
	public static long[] getLongArray(String line)
	{
		String[] strings = getStringArray(line);
		long[] numbers = new long[strings.length];
		for (int i = 0; i < strings.length; i++) {numbers[i] = Long.parseLong(strings[i]);}
		return numbers;
	}
	public static double[] getDoubleArray(String line)
	{
		String[] strings = getStringArray(line);
		double[] numbers = new double[strings.length];
		for (int i = 0; i < strings.length; i++) {numbers[i] = Double.parseDouble(strings[i]);}
		return numbers;
	}
	public static String[] getStringArray(String line) {return line.trim().split("(\\s)+", 0);}

	public static int[] getIntArray(String line, int begin, int end)
	{
		String[] strings = getStringArray(line, begin, end);
		int[] numbers = new int[end - begin];
		for (int i = begin; i < end; i++) {numbers[i - begin] = Integer.parseInt(strings[i - begin]);}
		return numbers;
	}
	public static long[] getLongArray(String line, int begin, int end)
	{
		String[] strings = getStringArray(line, begin, end);
		long[] numbers = new long[end - begin];
		for (int i = begin; i < end; i++) {numbers[i - begin] = Long.parseLong(strings[i - begin]);}
		return numbers;
	}
	public static double[] getDoubleArray(String line, int begin, int end)
	{
		String[] strings = getStringArray(line, begin, end);
		double[] numbers = new double[end - begin];
		for (int i = begin; i < end; i++) {numbers[i - begin] = Double.parseDouble(strings[i - begin]);}
		return numbers;
	}
	public static String[] getStringArray(String line, int begin, int end)
	{
		String[] lines = line.trim().split("(\\s)+", 0);
		String[] results = new String[end - begin];
		for (int i = begin; i < end; i++) {results[i - begin] = lines[i];}
		return results;
	}

	public static char[][] getCharMatrix(BufferedReader input) throws Exception
	{
		String line = input.readLine();
		H = getInt(line, 0);
		W = getInt(line, 1);
		D = getInt(line, 2);
		char[][] matrix = new char[H][W];
		for (int i = 0; i < H; i++)
		{
			line = input.readLine();
			for (int j = 0; j < W; j++)
			{
				char c = matrix[i][j] = line.charAt(j);
				if ('X' == c) {row = i; col = j;}
			}
		}
		return matrix;
	}
	public static int[][] getIntMatrix(BufferedReader input) throws Exception
	{
		String line = input.readLine();
		int R = getInt(line, 0);
		int C = getInt(line, 1);
		int[][] matrix = new int[R][C];
		for (int i = 0; i < R; i++)
		{
			line = input.readLine();
			for (int j = 0; j < C; j++) {matrix[i][j] = getInt(line, j);}
		}
		return matrix;
	}

	public static boolean[][] newBooleanMatrix(int R, int C, boolean value)
	{
		boolean[][] matrix = new boolean[R][C];
		for (int i = 0; i < R; i++) for(int j = 0; j < C; j++) {matrix[i][j] = value;}
		return matrix;
	}
	public static char[][] newCharMatrix(int R, int C, char value)
	{
		char[][] matrix = new char[R][C];
		for (int i = 0; i < R; i++) for(int j = 0; j < C; j++) {matrix[i][j] = value;}
		return matrix;
	}
	public static int[][] newIntMatrix(int R, int C, int value)
	{
		int[][] matrix = new int[R][C];
		for (int i = 0; i < R; i++) for(int j = 0; j < C; j++) {matrix[i][j] = value;}
		return matrix;
	}
	public static long[][] newLongMatrix(int R, int C, long value)
	{
		long[][] matrix = new long[R][C];
		for (int i = 0; i < R; i++) for(int j = 0; j < C; j++) {matrix[i][j] = value;}
		return matrix;
	}
	public static double[][] newDoubleMatrix(int R, int C, double value)
	{
		double[][] matrix = new double[R][C];
		for (int i = 0; i < R; i++) for(int j = 0; j < C; j++) {matrix[i][j] = value;}
		return matrix;
	}

	public static void output(String s) throws Exception
	{
		if (ECHO_ON) {System.out.println(s);}
		output.write(s);
		output.newLine();
	}

	public static String toKey(boolean[] array)
	{
		StringBuffer buffer = new StringBuffer(array.length + ",");
		for (int i = 0; i < array.length / 16; i++)
		{
			char c = 0;
			for (int j = 0; j < 16; j++)
			{
				c <<= 1; if (array[i * 16 + j]) {c += 1;}
			}
			buffer.append(c + "");
		}
		char c = 0;
		for (int j = 0; j < (array.length % 16); j++)
		{
			c <<= 1; if (array[(array.length / 16) * 16 + j]) {c += 1;}
		}
		buffer.append(c + "");
		return buffer.toString();
	}
	public static String toKey(int[] array, int bit)
	{
		StringBuffer buffer = new StringBuffer(array.length + ",");
		if (bit > 16)
		{
			for (int i = 0; i < array.length; i++)
			{
				char c1 = (char)(array[i] >> 16);
				char c2 = (char)(array[i] & 0xFFFF);
				buffer.append("" + c1 + c2);
			}
		}
		else
		{
			int n = 16 / bit;
			for (int i = 0; i < array.length / n; i++)
			{
				char c = 0;
				for (int j = 0; j < n; j++)
				{
					c <<= bit; c += array[i * n + j];
				}
				buffer.append(c + "");
			}
			char c = 0;
			for (int j = 0; j < (array.length % n); j++)
			{
				c <<= bit; c += array[(array.length / n) * n + j];
			}
			buffer.append(c + "");
		}
		return buffer.toString();
	}

	public static void debug(String s)
	{if (DEBUG_ON) {System.out.println(s);}}
	public static void debug(String s0, double l0)
	{if (DEBUG_ON) {System.out.println(s0+" = "+l0);}}
	public static void debug(String s0, double l0, String s1, double l1)
	{if (DEBUG_ON) {System.out.println(s0+" = "+l0+"; "+s1+" = "+l1);}}
	public static void debug(String s0, double l0, String s1, double l1, String s2, double l2)
	{if (DEBUG_ON) {	System.out.println(s0+" = "+l0+"; "+s1+" = "+l1+"; "+s2+" = "+l2);}}
	public static void debug(String s0, double l0, String s1, double l1, String s2, double l2, String s3, double l3)
	{if (DEBUG_ON) {System.out.println(s0+" = "+l0+"; "+s1+" = "+l1+"; "+s2+" = "+l2+"; "+s3+" = "+l3);}}
	public static void debug(String s0, double l0, String s1, double l1, String s2, double l2, String s3, double l3, String s4, double l4)
	{if (DEBUG_ON) {System.out.println(s0+" = "+l0+"; "+s1+" = "+l1+"; "+s2+" = "+l2+"; "+s3+" = "+l3+"; "+s4+" = "+l4);}}

	public static void debug(boolean[] array) {if (DEBUG_ON) {debug(array, " ");}}
	public static void debug(boolean[] array, String separator)
	{
		if (DEBUG_ON)
		{
			StringBuffer buffer = new StringBuffer();
			for (int i = 0; i < array.length - 1; i++) {buffer.append((array[i] == true ? "1" : "0") + separator);}
			buffer.append((array[array.length - 1] == true) ? "1" : "0");
			System.out.println(buffer.toString());
		}
	}
	public static void debug(boolean[][] array) {if (DEBUG_ON) {debug(array, " ");}}
	public static void debug(boolean[][] array, String separator)
	{if (DEBUG_ON) {for (int i = 0; i < array.length; i++) {debug(array[i], separator);}}}

	public static void debug(char[] array) {if (DEBUG_ON) {debug(array, " ");}}
	public static void debug(char[] array, String separator)
	{
		if (DEBUG_ON)
		{
			StringBuffer buffer = new StringBuffer();
			for (int i = 0; i < array.length - 1; i++) {buffer.append(array[i] + separator);}
			buffer.append(array[array.length - 1]);
			System.out.println(buffer.toString());
		}
	}
	public static void debug(char[][] array) {if (DEBUG_ON) {debug(array, " ");}}
	public static void debug(char[][] array, String separator)
	{if (DEBUG_ON) {for (int i = 0; i < array.length; i++) {debug(array[i], separator);}}}

	public static void debug(int[] array) {if (DEBUG_ON) {debug(array, " ");}}
	public static void debug(int[] array, String separator)
	{
		if (DEBUG_ON)
		{
			StringBuffer buffer = new StringBuffer();
			for (int i = 0; i < array.length - 1; i++) {buffer.append(array[i] + separator);}
			buffer.append(array[array.length - 1]);
			System.out.println(buffer.toString());
		}
	}
	public static void debug(int[][] array) {if (DEBUG_ON) {debug(array, " ");}}
	public static void debug(int[][] array, String separator)
	{if (DEBUG_ON) {for (int i = 0; i < array.length; i++) {debug(array[i], separator);}}}
}
