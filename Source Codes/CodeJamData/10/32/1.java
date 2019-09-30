import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class B {
	public static void main(String[] args) throws IOException	{
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("B.txt")));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int z = Integer.parseInt(br.readLine());
		for(int q = 1; q <= z; q++)	{
			StringTokenizer st = new StringTokenizer(br.readLine());
			long a = Integer.parseInt(st.nextToken());
			long b = Integer.parseInt(st.nextToken());
			long c = Integer.parseInt(st.nextToken());
			double ratio = 1.0*b/a;
			int n = 0;
			while(ratio > c)	{
				ratio = Math.sqrt(ratio);
				n++;
			}
			pw.println("Case #" + q + ": " + n);
		}
		pw.close();
	}
}
