import java.util.*;
import java.io.*;

public class A {

public static void main(String [] args) throws Exception
{
	//Scanner scan = new Scanner(new File("A-small-attempt0.in"));
	Scanner scan = new Scanner(new File("A-large.in"));
	
	//PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("outA1")));
	PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("outA2")));

	// solution
	int L = scan.nextInt();
	int D = scan.nextInt();
	int N = scan.nextInt();
	scan.nextLine();
	char[][] words = new char[D][L];
	for (int i = 0; i < D; i++)
	{
		String w = scan.nextLine();
		for (int d = 0; d < L; d++)
			words[i][d] = w.charAt(d);
	}
	
	for (int i = 1; i <= N; i++)
	{
		
		String s = scan.nextLine();
		boolean[][] set = new boolean[L][26];
		int a = 0;
		for (int k = 0; k < L; k++)
		{
			
			if (s.charAt(a) == '(')
			{
				a++;
				while (s.charAt(a) != ')')
				{
					set[k][s.charAt(a++)-'a'] = true;
				}
				a++;
			}
			else
				set[k][s.charAt(a++)-'a'] = true;			
		}
		
		int ans = 0;
		for (int d = 0; d < D; d++)
		{
			boolean accept = true;
			for (int k = 0; k < L; k++)	
			{
				accept = accept && set[k][words[d][k]-'a'];
			}
			if (accept) ans++;
		}
		out.println("Case #"+i+": "+ans);
	}
	
	out.close();
}
	
	
}