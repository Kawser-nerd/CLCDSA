import java.util.*;
import java.io.*;
import java.util.regex.*;

public class C {

public static void main(String [] args) throws Exception
{
	
	//Scanner scan = new Scanner(new File("C-small-attempt0.in"));
	Scanner scan = new Scanner(new File("C-large.in"));
	//PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("outC1")));
	PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("outC2")));

	// solution
	int n = scan.nextInt();
	scan.nextLine();
	char[] str = "welcome to code jam".toCharArray();
	
	for (int c = 1; c <= n; c++)
	{
		long ans = 0;
		char[] line = scan.nextLine().toCharArray();
		int len = line.length;
		int[][] count = new int[19][len];
		
		if (line[0] == str[0])
			count[0][0] = 1;
		for (int i = 1; i < len; i++)
			count[0][i] = count[0][i-1] + ((line[i] == str[0])?1:0);
		for (int i = 1; i < 19; i++)
			for (int j = i; j < len; j++)
				count[i][j] = (count[i][j-1] + ((str[i] == line[j])?count[i-1][j-1]:0))% 10000;
		
		ans = count[18][len-1] % 10000;
		out.print("Case #"+c+": ");
		if (ans > 999)
			out.println(ans);
		else if (ans > 99)
			out.println("0"+ans);
		else if (ans > 9)
			out.println("00"+ans);
		else
			out.println("000"+ans);
	}
	
	out.close();
}
}