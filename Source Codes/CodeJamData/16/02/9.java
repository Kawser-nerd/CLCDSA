import java.io.*;
import java.util.*; 

/** 
 * @author Olaf Matyja olafmat@gmail.com 
 */
public class Round0B {

	int cases;
	
	int count(String stack) {
		int flips = 0;
		for (int n = 1; n < stack.length(); n++) {
			if (stack.charAt(n - 1) != stack.charAt(n))
				flips++;
		}
		return flips;
	}
	
	void process(Scanner scanner, PrintStream out) throws IOException {
		cases = scanner.nextInt();
		scanner.nextLine();
		
		for (int curCase = 0; curCase < cases; curCase++) {
			String stack = scanner.nextLine().trim();			
			out.println("Case #" + (curCase + 1) + ": " + count(stack + "+"));
		}
	}
	
	Round0B() throws IOException {
		/*String sampleText = "5\r\n" + 
				"-\r\n" + 
				"-+\r\n" + 
				"+-\r\n" + 
				"+++\r\n" + 
				"--+-"; 
		Scanner in = new Scanner(sampleText);
		PrintStream out = System.out;*/
		
		
		/*Scanner in = new Scanner(new File("C:\\Users\\Olaf\\Downloads\\B-small-attempt0.in"));
		PrintStream out = new PrintStream("out-B-small.txt");*/
		
		
		Scanner in = new Scanner(new File("C:\\Users\\Olaf\\Downloads\\B-large.in"));
		PrintStream out = new PrintStream("out-B-large.txt");
		

		
		process(in, out);
		
		in.close();
		out.close();
	}	
	
	public static void main(String[] args) throws IOException {
		new Round0B();
	}	
	
}
