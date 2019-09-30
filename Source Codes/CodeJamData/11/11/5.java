import java.io.*;
import java.util.*;

public class freecell {
	public static void main(String[] args) throws IOException{
		BufferedReader in = new BufferedReader(new FileReader("freecell.in"));
		PrintWriter out = new PrintWriter(new FileWriter("freecell.out"));
		int numCases = Integer.parseInt(in.readLine());
		for (int cas = 1; cas<=numCases; cas++){
			out.print("Case #"+cas+": ");
			StringTokenizer st = new StringTokenizer(in.readLine());
			long maxNum = Long.parseLong(st.nextToken());
			int percToday = Integer.parseInt(st.nextToken());
			int percTotal = Integer.parseInt(st.nextToken());
			int numPlayed = 100/gcd(100, percToday);
			if (numPlayed<=maxNum && test(percToday, percTotal))
				out.println("Possible");
			else
				out.println("Broken");
		}
		out.close();
	}
	
	public static int gcd (int a, int b){
		if (a>b)
			return gcd(b,a);
		if (a==0)
			return b;
		return gcd(b%a, a);
	}
	
	public static boolean test (int today, int total){
		if (total==100 && today<100 || total==0 && today>0)
			return false;
		return true;
	}
}
