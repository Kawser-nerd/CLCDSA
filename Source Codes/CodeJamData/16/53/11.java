import java.io.*;
import java.util.*;
public class c {
public static void main(String[] args) throws IOException {
	input.init(System.in);
	PrintWriter out = new PrintWriter(new File("c1.out"));
	int T = input.nextInt();
	for(int t = 0; t<T; t++)
	{
		int n = input.nextInt(), s = input.nextInt();
		int[] xs = new int[n], ys = new int[n], zs = new int[n];
		int[] vx = new int[n], vy = new int[n], vz = new int[n];
		for(int i = 0; i<n; i++)
		{
			xs[i] = input.nextInt();
			ys[i] = input.nextInt();
			zs[i] = input.nextInt();
			vx[i] = input.nextInt();
			vy[i] = input.nextInt();
			vz[i] = input.nextInt();
		}
		double lo = 0, hi = 2000;
		for(int iter = 0; iter < 60; iter++)
		{
			double mid = (lo+hi)/2;
			double mid2 = mid*mid;
			DisjointSet ds = new DisjointSet(n);
			for(int i = 0; i<n; i++)
				for(int j = i+1; j<n; j++)
				{
					double d2 = (xs[i] - xs[j])*(xs[i] - xs[j]) + (ys[i] - ys[j])*(ys[i] - ys[j]) + (zs[i] - zs[j])*(zs[i] - zs[j]);
					if(d2 <= mid2) ds.union(i, j);
				}
			if(ds.find(0) == ds.find(1)) hi = mid;
			else lo = mid;
		}
		out.println("Case #" + (t+1)+": "+hi);
	}
	out.close();
}
public static class DisjointSet
{
	int[] map; //negative if root, more negative means bigger set; if nonnegative, then it indicates the parent 
	public DisjointSet(int n)
	{
		map = new int[n+1];
		Arrays.fill(map, -1);
	}
	public int find(int x)
	{
		if(map[x] < 0) return x;
	    return map[x] = find(map[x]);
	}
	public void union(int a, int b)
	{
		int roota = find(a), rootb = find(b);
		if(roota == rootb)
			return;
		if(map[roota] < map[rootb])
		{
			map[roota] += map[rootb]; //add the sizes
			map[rootb] = roota; //connect the smaller to the bigger
		}
		else
		{
			map[rootb] += map[roota];
			map[roota] = rootb;
		}
	}
}
public static class input {
	static BufferedReader reader;
	static StringTokenizer tokenizer;

	static void init(InputStream input) {
		reader = new BufferedReader(new InputStreamReader(input));
		tokenizer = new StringTokenizer("");
	}

	static String next() throws IOException {
		while (!tokenizer.hasMoreTokens())
			tokenizer = new StringTokenizer(reader.readLine());
		return tokenizer.nextToken();
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(next());
	}
}
}

