//input file must be in.txt in this directory
//output file will be out.txt
import java.io.*;
import java.util.*;
public class A
{
	public static Scanner in;
	public static PrintStream out;
	public static String googlerese = "yhesocvxduiglbkrztnwjpfmaq";
	public static void main(String [] args) throws Throwable
	{
		in = new Scanner(new File("in.txt"));
		int cases = in.nextInt();
		in.nextLine();
		out = new PrintStream(new File("out.txt"));
		for (int i = 1; i <= cases; i++)
		{
			out.print("Case #" + i + ": ");
			printResult();
			out.println();
		}
	}
	public static void printResult()
	{
		char c;
		String s = in.nextLine();
		for (int i = 0; i < s.length(); i++)
		{
			c = s.charAt(i);
			if (c >= 'A' && c <= 'Z')
				c += 'a' - 'A';
			if (c >= 'a' && c <= 'z')
			{
				c = googlerese.charAt(c - 'a');
			}
			out.print(c);
		}
		
	}
} 