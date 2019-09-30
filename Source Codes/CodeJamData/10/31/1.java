import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class A {
	public static void main(String[] args) throws IOException	{
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("A.txt")));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int z = Integer.parseInt(br.readLine());
		for(int q = 1; q <= z; q++)	{
			int n = Integer.parseInt(br.readLine());
			int[] a = new int[n];
			int[] b = new int[n];
			for(int i = 0; i < n; i++)	{
				StringTokenizer st = new StringTokenizer(br.readLine());
				a[i] = Integer.parseInt(st.nextToken());
				b[i] = Integer.parseInt(st.nextToken());
			}
			int t = 0;
			for(int i = 0; i < n; i++)	{
				for(int j = i+1; j < n; j++)	{
					if(a[i] < a[j] && b[i] > b[j])	{
						t++;
					}
					else if(a[j] < a[i] && b[j] > b[i])	{
						t++;
					}
				}
			}
			pw.println("Case #" + q + ": " + t);
		}
		pw.close();
	}
	public static int num(String a)	{
		StringTokenizer x = new StringTokenizer(a, "/");
		int n = 0;
		while(x.hasMoreTokens()){
			x.nextToken();
			n++;
		}
		return n;
	}
	public static int compare(String a, String b)	{
		StringTokenizer x = new StringTokenizer(a, "/");
		StringTokenizer y = new StringTokenizer(b, "/");
		int nonMatch = 0;
		while(x.hasMoreTokens() && y.hasMoreTokens())	{
			if(!x.nextToken().equals(y.nextToken()))	{
				nonMatch++;
				break;
			}
		}
		while(y.hasMoreTokens())	{
			y.nextToken();
			nonMatch++;
		}
		return nonMatch;
	}
}
