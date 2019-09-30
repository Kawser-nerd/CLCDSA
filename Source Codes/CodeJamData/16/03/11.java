import java.io.*;
import java.util.*; 
import java.math.*; 

/** 
 * @author Olaf Matyja olafmat@gmail.com 
 */
public class Round0C {

	int cases;
	
	int[] primes = new int[] {
		2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97
	};
	
	int divisor(String number, int radix) {
		BigInteger num = new BigInteger(number, radix);
		for (int p: primes) {
			if (num.mod(BigInteger.valueOf(p)).intValue() == 0) {
				return p;
			}
		}
		return 0;
	}	
	
	Random random = new Random(1423444);
	
	String rand(int length) {
		StringBuffer buf = new StringBuffer("1");
		for (int i = 1; i < length - 1; i++) {
			buf.append(random.nextBoolean() ? '1' : '0');
		}
		buf.append('1');
		return buf.toString();
	}
	
	void process(Scanner scanner, PrintStream out) throws IOException {
		cases = scanner.nextInt();
		scanner.nextLine();
		int N = scanner.nextInt();
		int J = scanner.nextInt();		
		
		Set<String> checked = new HashSet<String>();
		int[] moduli = new int[11];
		for (int curCase = 0; curCase < cases; curCase++) {
			out.println("Case #" + (curCase + 1) + ":");
			while (J > 0) {
				String number = rand(N);
				if (checked.contains(number))
					continue;
				boolean ok = true;
				for (int radix = 2; radix <= 10; radix++) {
					moduli[radix] = divisor(number, radix);
					if (moduli[radix] == 0) {
						ok = false;
						break;
					}
				}
				if (ok) {
					out.print(number);
					for (int radix = 2; radix <= 10; radix++) {
						out.print(' ');
						out.print(moduli[radix]);
					}
					out.println();
					J--;
				}
				checked.add(number);
			}
		}
	}
	
	Round0C() throws IOException {
		/*String sampleText = "1\r\n" + 
				"32 500"; 
		Scanner in = new Scanner(sampleText);
		PrintStream out = System.out;*/
		
		
		/*Scanner in = new Scanner(new File("C:\\Users\\Olaf\\Downloads\\C-small-attempt0.in"));
		PrintStream out = new PrintStream("out-C-small.txt");*/
		
		
		Scanner in = new Scanner(new File("C:\\Users\\Olaf\\Downloads\\C-large.in"));
		PrintStream out = new PrintStream("out-C-large.txt");
		

		
		process(in, out);
		
		in.close();
		out.close();
	}	
	
	public static void main(String[] args) throws IOException {
		new Round0C();
	}	
	
}
