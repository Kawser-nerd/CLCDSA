import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class B {

	B() throws Exception {

		File input = new File("input.txt"), output = new File("output.txt");

		Scanner scanner = new Scanner(input);
		BufferedWriter writer = new BufferedWriter(new FileWriter(output));

		int TestCases = scanner.nextInt();

		for (int Case = 1; Case <= TestCases; Case++) {

			writer.write("Case #" + Case + ": ");

			int L = scanner.nextInt();
			int P = scanner.nextInt();
			int C = scanner.nextInt();

			writer.write(f(L,P,C)+"");

			writer.newLine();
		}

		scanner.close();
		writer.close();
	}
	
	int f(int L, int P, int C) {

		if(P <= C*L) return 0;
		double x = 1.0*P/L;
		int n = (int)(Math.ceil(log(x,C)));
		return (int)Math.ceil(log(n,2));
	}

	private double log(double x, double c) {
		return Math.log(x)/Math.log(c);
	}

	public static void main(String[] args) throws Exception {
		new B();
	}
}