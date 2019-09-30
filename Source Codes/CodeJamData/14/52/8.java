import java.util.*;
public class b {
public static void main(String[] args)
{
	Scanner input = new Scanner(System.in);
	int T = input.nextInt();
	for(int t = 0; t<T; t++)
	{
		System.out.printf("Case #%d: ", t+1);
		p = input.nextInt(); q = input.nextInt(); int n = input.nextInt();
		hs = new int[n]; gs = new int[n];
		for(int i = 0; i<n; i++)
		{
			hs[i] = input.nextInt();
			gs[i] = input.nextInt();
		}
		{
			memo = new HashMap<Integer, Integer>();
			int[] data = new int[4];
			for(int i = 0; i<n; i++) data[i] = hs[i];
			System.out.println(dp(encode(data)));
		}
	}
}
static int[] hs, gs;
static int p, q;
static HashMap<Integer, Integer> memo;
static int dp(int key)
{
	int[] h = decode(key);
	//String s = Arrays.toString(h);
	//System.out.println(key+" "+Arrays.toString(h));
	if(memo.containsKey(key)) return memo.get(key);
	if(key == 0) return 0;
	int res = 0;
	for(int i = 0; i<4; i++)
	{
		if(h[i] == 0) continue;
		int temp = h[i];
		h[i] = Math.max(0, h[i] - p);
		boolean good = h[i] == 0;
		int[] next = upd(h);
		//System.out.println("NEXT: "+Arrays.toString(next)+" "+p+" "+h[i]+" "+i);
		//System.out.println(key+" "+encode(next));
		int nkey = encode(next);
		h[i] = temp;
		if(good) res = Math.max(res, gs[i] + dp(nkey));
		else res = Math.max(res, dp(nkey));
	}
	res = Math.max(res, dp(encode(upd(h))));
	//System.out.println(s+" "+Arrays.toString(h)+" "+res);
	memo.put(key, res);
	return res;
}
static int[] upd(int[] data)
{
	int[] res = new int[4];
	for(int i = 0; i<4; i++) res[i] = data[i];
	for(int i = 0; i<4; i++)
	{
		if(res[i] > 0)
		{
			res[i] = Math.max(0, res[i] - q);
			return res;
		}
	}
	return res;
}
static int encode(int[] a)
{
	return a[0] + a[1] * 201 + a[2] * 201*201 + a[3] * 201*201 * 201;
}
static int[] decode(int x)
{
	int[] res = new int[4];
	for(int i = 0; i<4; i++)
	{
		res[i] = x%201;
		x /= 201;
	}
	return res;
}
}
