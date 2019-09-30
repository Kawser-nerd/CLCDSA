import java.io.*;
import java.text.*;
import java.math.*;
import java.util.*;

class Main implements Runnable {

	final static String taskname = "C-large";
	
	int mod = 1000000007;
	int base = 1<<20;
	int[] tree;
	
	int sum(int left, int right)
	{
		left+=base;right+=base;
		int ans = 0;
		while (left+1<right)
		{
			if (left%2==1)
			{
				ans=(ans+tree[left])%mod;
				left++;
			}
			if (right%2==1)
			{
				right--;
				ans=(ans+tree[right])%mod;
			}
			left/=2;
			right/=2;
		}
		if (left<right)
			ans=(ans+tree[left])%mod;
		return ans;
	}
	
	public void update(int x, int value)
	{
		x+=base;
		while (x>0)
		{
			tree[x]=(tree[x]+value)%mod;
			x/=2;
		}
	}
	
	public void solve() throws Exception {
		int tests = iread();
		for (int t=1; t<=tests; t++)
		{
			int n = iread(), m = iread();
			long X = iread(), Y = iread(), Z = iread();
			int[] a = new int[m], b = new int[n];
			for (int i=0; i<m; i++)
				a[i] = iread();
			for (int i=0; i<n; i++)
			{
				b[i] = a[i%m];
				a[i%m] = (int)((X * a[i%m] + Y * (i + 1))%Z);
			}
			a = new int[n];
			for (int i=0; i<n; i++)
				a[i] = b[i];
			Arrays.sort(b);
			HashMap<Integer, Integer> num = new HashMap<Integer, Integer>();
			int k = 0;
			for (int i=0; i<n; i++)
				if (i==0||b[i]>b[i-1])
					num.put(b[i], ++k);
			for (int i=0; i<n; i++)
				a[i] = num.get(a[i]);
			int ans = 0;
			tree = new int[base*2];
			update(0, 1);
			for (int i=0; i<n; i++)
			{
				int val = sum(0, a[i]);
				ans = (ans+val)%mod;
				update(a[i], val);
			}
			out.write("Case #"+t+": "+ans+"\n");
			System.out.println(t);
		}
	}

	public void run() {
		try {
			//in = new BufferedReader(new InputStreamReader(System.in));
			//out = new BufferedWriter(new OutputStreamWriter(System.out));
			in = new BufferedReader(new FileReader(taskname + ".in"));
			out = new BufferedWriter(new FileWriter(taskname + ".out"));
			solve();
			out.flush();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	public int iread() throws Exception {
		return Integer.parseInt(readword());
	}

	public double dread() throws Exception {
		return Double.parseDouble(readword());
	}

	public long lread() throws Exception {
		return Long.parseLong(readword());
	}

	BufferedReader in;

	BufferedWriter out;

	public String readword() throws IOException {
		StringBuilder b = new StringBuilder();
		int c;
		c = in.read();
		while (c >= 0 && c <= ' ')
			c = in.read();
		if (c < 0)
			return "";
		while (c > ' ') {
			b.append((char) c);
			c = in.read();
		}
		return b.toString();
	}
	public static void main(String[] args) {
		//Locale.setDefault(Locale.US);
		new Thread(new Main()).start();
	}
}
