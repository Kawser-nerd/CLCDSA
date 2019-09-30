import java.io.*;
import java.util.*;
import java.math.*;

class A
{
	private static final boolean DEBUG_ON = true;
	private static final boolean ECHO_ON = true;

	private static BufferedReader input;
	private static BufferedWriter output;

	private static final int INF = Integer.MAX_VALUE / 2;
	private static final int MOD = 10007;

	public static void main(String[] args)
	{
		try
		{
			input = new BufferedReader(new FileReader(args[0]  + ".in"));
			output = new BufferedWriter(new FileWriter(args[0] + ".out"));

			HashMap<Character, Character> map = new HashMap<Character, Character>();
			HashSet<Character> out = new HashSet<Character>();

			char[][] sampleIn = new char[3][];
			sampleIn[0] = "ejp mysljylc kd kxveddknmc re jsicpdrysi".toCharArray();
			sampleIn[1] = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd".toCharArray();
			sampleIn[2] = "de kr kd eoya kw aej tysr re ujdr lkgc jv".toCharArray();

			char[][] sampleOut = new char[3][];
			sampleOut[0] = "our language is impossible to understand".toCharArray();
			sampleOut[1] = "there are twenty six factorial possibilities".toCharArray();
			sampleOut[2] = "so it is okay if you want to just give up".toCharArray();

			map.put('y', 'a'); out.add('a');
			map.put('e', 'o'); out.add('o');
			map.put('q', 'z'); out.add('z');

			for (int i = 0; i < 3; i++)
			for (int j = 0; j < sampleIn[i].length; j++)
			{
				if (!map.containsKey(sampleIn[i][j])) {map.put(sampleIn[i][j], sampleOut[i][j]); out.add(sampleOut[i][j]);}
			}

			char missingIn = 'a', missingOut = 'a';
			for (char c : "abcdefghijklmnopqrstuvwxyz".toCharArray())
			{
				if (!map.containsKey(c)) {missingIn = c;}
				if (!out.contains(c)) {missingOut = c;}
			}

			map.put(missingIn, missingOut);

			debug("" + map.size());

			String line = input.readLine();
			int testcases = getInt(line, 0);

			for (int testcase = 1; testcase <= testcases; testcase++)
			{
				char[] testIn = input.readLine().toCharArray();
				StringBuffer buffer = new StringBuffer();
				for (char c : testIn)
				{
					buffer.append("" + map.get(c));
				}

				String result = "Case #" + testcase + ": " + buffer.toString();
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
		int R = getInt(line, 0);
		int C = getInt(line, 1);
		char[][] matrix = new char[R][C];
		for (int i = 0; i < R; i++)
		{
			line = input.readLine();
			for (int j = 0; j < C; j++) {matrix[i][j] = line.charAt(j);}
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
