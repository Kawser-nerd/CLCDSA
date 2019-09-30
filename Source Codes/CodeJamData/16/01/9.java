import java.io.*;
import java.util.*; 

/** 
 * @author Olaf Matyja olafmat@gmail.com 
 */
public class Round0A {

	int cases;
	
	long calc(long N) {
		boolean seen[] = new boolean[10];
		int nSeen = 0;
		long x = N;
		while (true) {
			String s = "" + x;
			for (int n = 0; n < s.length(); n++) {
				char c = s.charAt(n);
				if (!seen[c - '0']) {
					seen[c - '0'] = true;
					nSeen++;
				}
			}
			if (nSeen == 10)
				break;
			x += N;
		}
		return x;
	}
	
	String calcS(long N) {
		if (N == 0)
			return "INSOMNIA";
		return "" + calc(N);
	}
	
	void process(Scanner scanner, PrintStream out) throws IOException {
		cases = scanner.nextInt();
		scanner.nextLine();
		
		for (int curCase = 0; curCase < cases; curCase++) {
			long N = scanner.nextLong();
			out.println("Case #" + (curCase + 1) + ": " + calcS(N));
		}
	}
	
	Round0A() throws IOException {
		/*String sampleText = "5\r\n" + 
				"0\r\n" + 
				"1\r\n" + 
				"2\r\n" + 
				"11\r\n" + 
				"1692"; 
		Scanner in = new Scanner(sampleText);
		PrintStream out = System.out;*/
		
		
		/*Scanner in = new Scanner(new File("C:\\Users\\Olaf\\Downloads\\A-small-attempt0.in"));
		PrintStream out = new PrintStream("out-A-small.txt");*/
		
		
		Scanner in = new Scanner(new File("C:\\Users\\Olaf\\Downloads\\A-large.in"));
		PrintStream out = new PrintStream("out-A-large.txt");
		

		
		process(in, out);
		
		in.close();
		out.close();
	}	
	
	public static void main(String[] args) throws IOException {
		new Round0A();
	}	
	
}
