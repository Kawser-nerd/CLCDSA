import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class A {

	A() throws Exception {

		File input = new File("input.txt"), output = new File("output.txt");

		Scanner scanner = new Scanner(input);
		BufferedWriter writer = new BufferedWriter(new FileWriter(output));

		int TestCases = scanner.nextInt();

		for (int Case = 1; Case <= TestCases; Case++) {

			writer.write("Case #" + Case + ": ");

			int Wires = scanner.nextInt();
			
			int[] A = new int[Wires], B = new int[Wires];
			
			int count = 0;
			
			for(int i = 0; i < Wires; i++) {
				A[i] = scanner.nextInt();
				B[i] = scanner.nextInt();
				for(int j = 0; j < i; j++) {
					if(A[i]>A[j] && B[i]<B[j] || A[i]<A[j] && B[i]>B[j]) count++;
				}
			}

			writer.write(count+"");

			writer.newLine();
		}

		scanner.close();
		writer.close();
	}

	public static void main(String[] args) throws Exception {
		new A();
	}
}