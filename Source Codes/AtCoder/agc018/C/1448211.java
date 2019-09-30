import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
	
	static final int GOLD = 0, SILVER = 1, BRONZE = 2;
	static Person[] people;
	static PriorityQueue<Diff>[] pqs;
	static int[] groupIndex;
	
	public static void main(String[] args) throws IOException {

		Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);

		int X = sc.nextInt(), Y = sc.nextInt(), Z = sc.nextInt();
		groupIndex = new int[X + Y + Z];
		people = new Person[X + Y + Z];
		pqs = new PriorityQueue[9];
		for(int i = 0; i < 9; ++i)
			pqs[i] = new PriorityQueue<>();
		long ans = 0;
		for(int i = 0; i < X + Y + Z; ++i)
		{
			people[i] = new Person(sc.nextInt(), sc.nextInt(), sc.nextInt());
			if(i < X)
			{
				ans += people[i].coins[GOLD];
				addToGroup(i, GOLD);
			}
			else if(i < X + Y)
			{	
				ans += people[i].coins[SILVER];
				addToGroup(i, SILVER);
			}
			else
			{
				ans += people[i].coins[BRONZE];
				addToGroup(i, BRONZE);
			}
		}
		
		main: while(true)
		{
			for(int i = 0; i < 3; ++i)
				for(int j = i + 1; j < 3; ++j)
				{
					long add = solve2(i, j);
					if(add > 0)
					{
						ans += add;
						continue main;
					}
				}

			// Gold -> Silver -> Bronze
			long add = solve3(GOLD, SILVER, BRONZE);
			if(add > 0)
			{
				ans += add;
				continue main;
			}
			// Bronze -> Silver  -> Gold
			add = solve3(BRONZE, SILVER, GOLD);
			if(add > 0)
			{
				ans += add;
				continue main;
			}
			break;
		}
		out.println(ans);
		out.close();
	}
	
	static void fix(int...pqIdx)
	{
		for(int pqIndex: pqIdx)
		{
			int group = pqIndex / 3;
			while(groupIndex[pqs[pqIndex].peek().idx] != group)
				pqs[pqIndex].remove();
		}
	}
	
	static void addToGroup(int idx, int group)
	{
		groupIndex[idx] = group;
		for(int t = 0; t < 3; ++t)
			if(t != group)
				add(group, t, idx);
	}
	
	static long solve2(int t1, int t2)
	{
		int pq1 = t1 * 3 + t2, pq2 = t2 * 3 + t1;
		fix(pq1, pq2);
		long add = pqs[pq1].peek().d + pqs[pq2].peek().d;
		if(add <= 0)
			return 0;
		int e1 = pqs[pq1].peek().idx, e2 = pqs[pq2].peek().idx;
		addToGroup(e1, t2);
		addToGroup(e2, t1);
		return add;
	}
	
	static long solve3(int t1, int t2, int t3)
	{
		int pq1 = t1 * 3 + t2, pq2 = t2 * 3 + t3, pq3 = t3 * 3 + t1;
		fix(pq1, pq2, pq3);
		long add =  pqs[pq1].peek().d + pqs[pq2].peek().d + pqs[pq3].peek().d;
		if(add <= 0)
			return 0;
		int e1 = pqs[pq1].peek().idx, e2 = pqs[pq2].peek().idx, e3 = pqs[pq3].peek().idx;
		addToGroup(e1, t2);
		addToGroup(e2, t3);
		addToGroup(e3, t1);
		return add;
		
	}
	
	static void add(int t1, int t2, int i)
	{
		pqs[t1 * 3 + t2].add(new Diff(people[i].coins[t2] - people[i].coins[t1], i));
	}
	
	static class Diff implements Comparable<Diff>
	{
		int d, idx;
		
		Diff(int a, int b) { d = a; idx = b; }
		
		public int compareTo(Diff diff) { return diff.d - d; }
	}
	
	static class Person
	{
		int[] coins = new int[3];
		
		Person(int a, int b, int c) { coins[GOLD] = a; coins[SILVER] = b; coins[BRONZE] = c; }
	}

	static class Scanner 
	{
		StringTokenizer st;
		BufferedReader br;

		public Scanner(InputStream s){	br = new BufferedReader(new InputStreamReader(s));}

		public Scanner(String s) throws FileNotFoundException{	br = new BufferedReader(new FileReader(s));}

		public String next() throws IOException 
		{
			while (st == null || !st.hasMoreTokens()) 
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}

		public int nextInt() throws IOException {return Integer.parseInt(next());}

		public long nextLong() throws IOException {return Long.parseLong(next());}

		public String nextLine() throws IOException {return br.readLine();}

		public double nextDouble() throws IOException { return Double.parseDouble(next()); }

		public boolean ready() throws IOException {return br.ready();} 
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.