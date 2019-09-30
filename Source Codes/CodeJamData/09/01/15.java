import java.util.Scanner;
import java.util.regex.Pattern;

public class A
{

	public static void main(String[] args) throws Exception
	{
		new A();
	}

	int L, Dn, T;
	String[] D;

	A() throws Exception
	{
		Scanner in = new Scanner(System.in);
		L = in.nextInt();
		Dn = in.nextInt();
		T = in.nextInt();

		D = new String[Dn];
		for (int i = 0; i < Dn; ++i)
			D[i] = in.next();

		for (int ds = 1; T-- > 0; ++ds)
		{
			Pattern p = Pattern.compile(in.next().replace('(', '[').replace(')', ']'));
			int cnt = 0;
			for (String word : D)
				if (p.matcher(word).matches())
					++cnt;
			System.out.printf("Case #%d: %d%n", ds, cnt);
		}
	}

}
