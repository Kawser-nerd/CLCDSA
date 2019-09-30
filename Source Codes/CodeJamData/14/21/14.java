import java.util.*;

public class Main
{
	Scanner in = new Scanner(System.in);

	public static void main(String[] args)
	{
		new Main().run();
	}

	void run()
	{
		int ts = in.nextInt();
		for (int ti = 1; ti <= ts; ti++)
		{
			int n = in.nextInt();
			boolean ok = true;
			String[] parts = null;
			int[][] count = null;
			for (int l = 0; l < n; l++)
			{
				String[] line = split(in.next());
				if (parts == null) {
					parts = line;
					count = new int[parts.length][n];
				} else if (line.length != parts.length) {
					ok = false;
				} else {
					for (int i = 0; i < parts.length; i++) {
						if (parts[i].charAt(0) != line[i].charAt(0)) {
							ok = false;
							break;
						}
					}
				}
				if (ok)
				{
					for (int i = 0; i < parts.length; i++)
					{
						count[i][l] = line[i].length();
					}
				}
			}
			int ans = 0;
			if (ok)
			{
				for (int i = 0; i < parts.length; i++)
				{
					ans += cost(count[i]);
				}
			}

			System.out.format("Case #%d: %s\n", ti, ok ? ans : "Fegla Won");
		}
	}

	String[] split(String line)
	{
		ArrayList<String> res = new ArrayList<String>();
		StringBuilder current = new StringBuilder();
		char prev = line.charAt(0);
		for (char c : line.toCharArray())
		{
			if (c != prev) {
				res.add(current.toString());
				current.setLength(0);
				prev = c;
			}
			current.append(c);
		}
		res.add(current.toString());
		return res.toArray(new String[0]);
	}

	int cost(int[] arr)
	{
		int m = median(arr), s = 0;
		for (int i : arr) s += Math.abs(i - m);
		return s;
	}

	int median(int[] arr)
	{
		Arrays.sort(arr);
		return arr[arr.length / 2];
	}
}
