import java.io.*;
import java.util.*;
import java.text.*;

public class C
{
	public PrintStream out = System.out;
	public PrintStream err = System.err;
	public Scanner in = new Scanner(System.in);
	public DecimalFormat fmt = new DecimalFormat("0.000000");
	
	public int Mod = 10000;
	public String K = "welcome to code jam";
	public char[] T, key;
	public int[][] S;
	public int Tn, Kn;

	public void main()
	{
		try
		{
//			err = new PrintStream(new FileOutputStream("error.log"),true);			
			int TCase,cc;
			int i, j, k;
			
			key = K.toCharArray();
			Kn = K.length();

			TCase = in.nextInt();
			in.nextLine();
			for(cc=1;cc<=TCase;++cc)
			{
				T = Line().toCharArray();
				Tn = T.length;

				S = new int[Tn+1][Kn+1];

				i = Tn;
				S[i][Kn] = 1;

				for(--i;i>=0;--i)
				{
					S[i][Kn] = 1;
					for(j=Kn-1;j>=0;--j)
					{
						S[i][j] = S[i+1][j];
						if(T[i] == key[j])
						{
							S[i][j] = (S[i][j] + S[i+1][j+1])%Mod;
						}
					}
				}

				String res = "0000"+S[0][0];
				out.println("Case #"+cc+": "+res.substring(res.length()-4));
			}
		}
		catch(Exception e) { e.printStackTrace(); }
	}//end public void main()
	
	public int Int() { return in.nextInt(); }
	public long Long() { return in.nextLong(); }
	public String Token() { return in.next(); }
	public String Line() { return in.nextLine(); }

	public static void main(String[] args)
	{
		long startTime=System.currentTimeMillis();

		(new C()).main();

		System.err.println("Time Spent: "+(System.currentTimeMillis()-startTime)+"(ms)");
	}
}
