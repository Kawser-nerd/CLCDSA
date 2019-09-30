import java.io.*;
import java.util.*;

public class A
{
	private static int r, c, w;
	private static final int oo = 1000000000;

	private static int [][][] memo1, memo2[];

	public static void main(String[] args) throws IOException
	{
		BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream(new File("input.in"))));
		PrintWriter writer = new PrintWriter(new File("output.out"));
		StringTokenizer tokenizer = new StringTokenizer(reader.readLine());

		memo1 = new int[20][20][1<<20];
		//memo2 = new int[20][20][1<<20][20];

		int tc = Integer.parseInt(tokenizer.nextToken());

		int time = 1;

		while(tc-- > 0)
		{
			//System.err.println(time);
			tokenizer = new StringTokenizer(reader.readLine());
			r = Integer.parseInt(tokenizer.nextToken());
			c = Integer.parseInt(tokenizer.nextToken());
			w = Integer.parseInt(tokenizer.nextToken());

			int res = r*(c/w);
			int mask = 1<<(w-1);
			int last = w-1;
			while(last+w < c)
				last += w;
			int left = last-(w-1);
			int right = Math.min(c-1, last+(w-1));
			right -= left;
			left -= left;


			for(int [][] fill1 : memo1)
				for(int [] fill2 : fill1)
					Arrays.fill(fill2, -1);

			/*for(int [][][] fill1 : memo2)
				for(int [][] fill2 : fill1)
					for(int [] fill3 : fill2)
						Arrays.fill(fill3, -1);*/
			res += rec(left, right, mask);

			writer.println("Case #"+(time++)+": "+res);
		}

		writer.flush();
		writer.close();
	}

	private static int rec(int left, int right, int mask)
	{
		if(right-left+1 == w)
			return w - Integer.bitCount(mask);

		if(memo1[left][right][mask] != -1)
			return memo1[left][right][mask];

		int res = oo;
		for (int next = left; next <= right; next++)
			if (((1 << next) & mask) == 0)
			{
				res = Math.min(res, 1 + rec2(left, right, mask, next));
			}

		return memo1[left][right][mask] = res;
	}

	private static int rec2(int left, int right, int mask, int next)
	{
	//	if(memo2[left][right][mask][next] != -1)
	//		return memo2[left][right][mask][next];

		int res = 0;
		//is a bomb
		{
			int nMask = mask | (1 << next);
			int lowest = Integer.lowestOneBit(nMask);
			int lid = 0;
			while (1 << lid != lowest)
				lid++;
			int highest = Integer.highestOneBit(nMask);
			int hid = 0;
			while (1 << hid != highest)
				hid++;

			int nLeft = Math.max(0, hid - (w - 1));
			int nRight = Math.min(c - 1, lid + (w - 1));
			if (hid - lid + 1 <= w && nRight - nLeft + 1 >= w)
				res = Math.max(res, rec(nLeft, nRight, nMask));
		}

		//not a bomb
		{
			int lowest = Integer.lowestOneBit(mask);
			int lid = 0;
			while (1 << lid != lowest)
				lid++;
			int highest = Integer.highestOneBit(mask);
			int hid = 0;
			while (1 << hid != highest)
				hid++;

			if(next < lid)
				if(right-next >= w)
					res = Math.max(res, rec(next+1, right, mask));
			if(next > hid)
				if(next - left >= w)
					res = Math.max(res, rec(left, next-1, mask));

		//	return memo2[left][right][mask][next] = res;
			return res;
		}

	}


}