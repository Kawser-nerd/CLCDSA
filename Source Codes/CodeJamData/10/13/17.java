import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class NumberGame {
	public static void main(String args[]) throws IOException{
		BufferedReader in = new BufferedReader(new FileReader("C-large.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("C.out")));
		long alow, ahigh, blow, bhigh, cases;
		cases = Integer.parseInt(in.readLine());
		double gold = (1+Math.sqrt(5))/2;
		for(int i=1; i<=cases; i++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			alow = Integer.parseInt(st.nextToken());
			ahigh = Integer.parseInt(st.nextToken());
			blow = Integer.parseInt(st.nextToken());
			bhigh = Integer.parseInt(st.nextToken());
			long count = (ahigh-alow+1)*(bhigh-blow+1);
			for(long a=alow; a<=ahigh; a++) {
				long low = Math.max((long)(a/gold+1), blow);
				long high = Math.min(bhigh,(long)(a*gold));
				if(low<=bhigh&&high>=blow)
					count-=high-low+1;
				
			}
			out.println("Case #"+i+": "+count);
		}
			
		out.close();
	}
}
