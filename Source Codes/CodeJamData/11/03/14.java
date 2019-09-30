import java.io.File;
import java.util.Arrays;
import java.util.Scanner;


public class Candy {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		Scanner scanner = new Scanner(new File(args[0]));
		int nCases = scanner.nextInt();

		for (int caseNo = 1; caseNo <= nCases; caseNo++) {
			String output = "NO";
			
			scanner.nextLine();
			int nCandies = scanner.nextInt();
			scanner.nextLine();
			int basicCheck = 0;
			long totalValue = 0;
			int smallestValue = Integer.MAX_VALUE;
			for (int i = 0; i < nCandies; i++) {
				int value = scanner.nextInt();
				//values[i] = value;
				basicCheck = basicCheck ^ value;
				totalValue += (long) value;
				
				if (value < smallestValue) {
					smallestValue = value;
				}
			}
			if (basicCheck == 0) {
				//possible
				long bigPile = totalValue - (long) smallestValue;
				output = "" + bigPile;
			}
			
			System.out.println("Case #" + caseNo + ": " + output);
			
		}


	}

}
