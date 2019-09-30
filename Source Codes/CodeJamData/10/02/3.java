import java.io.*;
import java.util.*;
import java.math.*;

public class Main implements Runnable
{
	static Scanner scanner;
	static BufferedReader input;
	static PrintWriter pw;

	public static void main(String[] args) throws Exception
	{
		new Thread(new Main()).start();
	}

	public void run()
	{
		try
		{
			input = new BufferedReader(new FileReader("input.txt"));
			scanner = new Scanner(input);
			pw = new PrintWriter(new File("output.txt"));

			solve();

			pw.close();
		}
		catch(Exception e)
		{
			e.printStackTrace();
			System.exit(1);
		}
	}

	public void solve() throws Exception
	{
		int qq = scanner.nextInt();
		for(int ii = 0; ii < qq; ii++)
		{
			int n = scanner.nextInt();
			BigInteger[] a = new BigInteger[n];
			for(int i = 0; i < n; i++)
			{
				a[i] = scanner.nextBigInteger();
			}
			BigInteger x = BigInteger.ZERO;
			for(int i = 1; i < n; i++)
			{
				x = x.gcd(a[i].subtract(a[0]));
			}
			BigInteger ans = (x.subtract(a[0].mod(x))).mod(x);
			pw.println("Case #" + (ii+1) + ": " + ans);
		}
	}
}
