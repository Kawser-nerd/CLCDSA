import java.math.BigInteger;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Scanner;

public class C
{
	private static String res;

	public static void main(String [] args)
	{
		Scanner in = new Scanner(System.in);

		int tc = in.nextInt();

		for(int t = 1 ; t <= tc ; t++)
		{
			res = "-1";
			int n = in.nextInt();
			int m = in.nextInt();

			boolean [][] graph = new boolean[n][n];
			String [] zip = new String[n];

			for(int i = 0 ; i < n ; i++)
				zip[i] = in.next();

			for(int i = 0 ; i < m ; i++)
			{
				int a = in.nextInt() - 1;
				int b = in.nextInt() - 1;

				graph[a][b] = graph[b][a] = true;
			}

			int [] order = new int[n];
			for(int i = 0 ; i < n ; i++)
				order[i] = i;

			permute(order, 0, zip, graph, n, m);

			System.out.println("Case #"+t+": "+res);
		}
	}

	private static void permute(int[] order, int start, String[] zip, boolean[][] graph, int n, int m)
	{
		if(start == order.length)
		{

			int next = 1;
			LinkedList<Integer> ret = new LinkedList<Integer>();
			ret.addLast(0);

			while(next < order.length)
			{
				while(!ret.isEmpty() && !graph[order[ret.getLast()]][order[next]])
					ret.removeLast();
				if(ret.isEmpty())
					break;
				ret.addLast(next);
				next++;
			}

			if(next == order.length)
			{
				String build = "";
				for(int i = 0 ; i < n ; i++)
					build += zip[order[i]];

				if(res.equals("-1") || res.compareTo(build) > 0)
					res = build;
			}

			return;
		}
		for(int i = start ; i < order.length ; i++)
		{
			int temp = order[i];
			order[i] = order[start];
			order[start] = temp;

			permute(order, start+1, zip, graph, n, m);

			temp = order[i];
			order[i] = order[start];
			order[start] = temp;
		}
	}
}