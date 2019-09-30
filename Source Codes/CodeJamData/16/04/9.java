import java.io.*;
import java.util.*; 

/** 
 * @author Olaf Matyja olafmat@gmail.com 
 */
public class Round0D {

	int cases;
	
	void process(Scanner scanner, PrintStream out) throws IOException {
		cases = scanner.nextInt();
		scanner.nextLine();
		
		for (int curCase = 0; curCase < cases; curCase++) {
			long K = scanner.nextLong();
			long C = scanner.nextLong();
			long S = scanner.nextLong();

			if (C * S < K) {
				out.println("Case #" + (curCase + 1) + ": IMPOSSIBLE");
			} else {
				out.print("Case #" + (curCase + 1) + ":");
				long k = 0;
				for (long s = 0; s < S && k < K; s++) {
					long num = 0;
					for (int i = 0; i < C; i++) {
						num = num * K + (k % K);
						k++;
					}
					out.print(' ');
					out.print(num + 1);
				}
				out.println();
			}
		}
	}
	
	Round0D() throws IOException {
		/*String sampleText = "5\r\n" + 
				"2 3 2\r\n" + 
				"1 1 1\r\n" + 
				"2 1 1\r\n" + 
				"2 1 2\r\n" + 
				"3 2 3"; 
		Scanner in = new Scanner(sampleText);
		PrintStream out = System.out;*/
		
		
		/*Scanner in = new Scanner(new File("C:\\Users\\Olaf\\Downloads\\D-small-attempt0.in"));
		PrintStream out = new PrintStream("out-D-small.txt");*/
		
		
		Scanner in = new Scanner(new File("C:\\Users\\Olaf\\Downloads\\D-large.in"));
		PrintStream out = new PrintStream("out-D-large.txt");
		
		process(in, out);
		
		in.close();
		out.close();
	}	
	
	public static void main(String[] args) throws IOException {
		new Round0D();
	}	
	
}
