import java.util.Collections;
import java.util.Iterator;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Scalar {
	public static void main(String args[]) {
		int caseTotal;
		int caseNum = 1;
		int vectorSize;
		Scanner scanner = new Scanner(System.in);
		
		caseTotal = scanner.nextInt();
		while (caseTotal != 0) {
			System.out.print("Case #" + caseNum + ": ");
			vectorSize = scanner.nextInt();
			ArrayList<Integer> x = new ArrayList<Integer>(vectorSize);
			ArrayList<Integer> y = new ArrayList<Integer>(vectorSize);
			for (int i=0; i<vectorSize; i++) {
				x.add(scanner.nextInt());
			}
			for (int i=0; i<vectorSize; i++) {
				y.add(scanner.nextInt());
			}
			
			Collections.sort(x);
			Collections.sort(y);
			
			int iy = vectorSize - 1;
			int result = 0;
			for (int ix=0; ix<vectorSize; ix++) {
				result += x.get(ix) * y.get(iy);
				--iy;
			}
			
			System.out.println(result);
			
			++caseNum;
			--caseTotal;
		}
	}
}
