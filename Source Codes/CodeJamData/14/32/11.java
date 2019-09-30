import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;


public class GCJ2014_R1C_2 {
	
	static final int MODNUM = 1000000007;
	
	public static void main(String[] args) throws Exception {
//		String fname = "B_example";
//		String fname = "B_small";
		String fname = "B_large";
	
		
		File file = new File(fname+"_in.txt");
		Scanner scanner = new Scanner(file);

		FileWriter outFile = new FileWriter(fname+"_out.txt");
		PrintWriter outp = new PrintWriter(outFile);
		
		int T = scanner.nextInt();
		
		for (int i=1;i<=T;i++)
		{
			int N = scanner.nextInt();
			
			String[] slist = new String[101];			
			
			int[] ixBeginingWith = new int[128];
			int[] ixEndingWith = new int[128];
			int[] ixInside = new int[128];
			int[] countBothEnd = new int[128];
			
			for (char c='a';c<='z';c++)
			{
				ixBeginingWith[c] = -1;
				ixEndingWith[c] = -1;
				ixInside[c] = -1;
				countBothEnd[c] = 0;
			}
			
			
			boolean impossible = false;
			
			for (int j=0;j<N;j++)
			{
				slist[j] = scanner.next();
			
				char first = slist[j].charAt(0);
				char last = slist[j].charAt(slist[j].length()-1);
				
				if (first == last)
				{
					countBothEnd[first] ++;
				}
				else
				{				
					if (ixBeginingWith[first] != -1)
						impossible = true;
					ixBeginingWith[first] = j;

					if (ixEndingWith[last] != -1)
						impossible = true;
					ixEndingWith[last] = j;
				}
				
				for (int k=1;k<slist[j].length()-1;k++)
				{
					char cn = slist[j].charAt(k);
					if ((cn != first) && (cn != last))
					{
						if ((ixInside[cn] != -1) && (ixInside[cn] != j))
							impossible = true;
						ixInside[cn] = j;
					}
				}
				boolean[] charSeenInWord = new boolean[128];
				charSeenInWord[first] = true;
				for (int k=1;k<slist[j].length();k++)
				{
					char cn = slist[j].charAt(k);
					if (charSeenInWord[cn] && (slist[j].charAt(k-1) != cn))
						impossible = true;
					charSeenInWord[cn] = true;
				}
			}
			System.out.println(i);
			System.out.println(impossible);
			for (char c='a';c<='z';c++)
			{
				System.out.printf("%c: %d %d %d %d\n",c,ixBeginingWith[c],ixEndingWith[c],countBothEnd[c],ixInside[c]);
			}
			
			
			boolean[] canBeginSub = new boolean[128];
			boolean[] canEndSub = new boolean[128];
			for (char c='a';c<='z';c++)
			{
				canBeginSub[c] = false;
				canEndSub[c] = false;
				
				if ((ixInside[c]!=-1) && ((ixBeginingWith[c] != -1) || (ixEndingWith[c] != -1) || (countBothEnd[c] != 0)))
					impossible = true;
				
				if (((ixBeginingWith[c] != -1) || (countBothEnd[c] != 0)) && (ixEndingWith[c] == -1))
					canBeginSub[c] = true;

				if (((ixEndingWith[c] != -1) || (countBothEnd[c] != 0)) && (ixBeginingWith[c] == -1))
					canEndSub[c] = true;
			}
			int endCount = 0;
			for (char c='a';c<='z';c++)
			{
				if (canBeginSub[c]) endCount++;
				if (canEndSub[c]) endCount++;
			}
			if (endCount % 2 == 1)
				impossible = true;
			if (endCount == 0)
				impossible = true;
			
			System.out.printf("%d /2  : endCount: %d\n",i,endCount);
			System.out.println(impossible);
			for (char c='a';c<='z';c++)
			{
				System.out.printf("%c: %b %b %d\n",c,canBeginSub[c],canEndSub[c],countBothEnd[c]);
			}
		
			if (impossible)
				outp.printf("Case #%d: 0\n",i);
			else
			{
				long res = 1;
				int subCount = endCount / 2;
				for (int k=1;k<=subCount;k++)
				{
					res = res * k;
					res = res  % MODNUM;
				}
				System.out.printf("**** %d\n",res);
				for (char c='a';c<='z';c++)
					if (countBothEnd[c] >= 2)
						for (int k=1;k<=countBothEnd[c];k++)
						{
							res = res * k;
							res = res % MODNUM;
						}
				System.out.printf("******** %d\n",res);
				outp.printf("Case #%d: %d\n",i,res);
				
			}
			
			
			
/*
			if (min != -1)
				outp.printf("Case #%d: %d\n",i,min);
			else 
				outp.printf("Case #%d: Fegla Won\n",i);*/
			
		}
		
		outp.close();
	}

}
