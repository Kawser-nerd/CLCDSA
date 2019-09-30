import java.io.File;
import java.util.Arrays;
import java.util.Scanner;


public class GoroSort {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		Scanner scanner = new Scanner(new File(args[0]));
		int nCases = scanner.nextInt();

		for (int caseNo = 1; caseNo <= nCases; caseNo++) {
			
			scanner.nextLine();
			int nArrayElements = scanner.nextInt();
			scanner.nextLine();
			int[] array = new int[nArrayElements];
			for (int i = 0; i < nArrayElements; i++) {
				array[i] = scanner.nextInt();
			}
			
			int[] sorted = array.clone();
			Arrays.sort(sorted);
			
			int nElementsNeedingSort = 0;
			for (int i = 0; i < nArrayElements; i++) {
				if (array[i] != sorted[i]) {
					nElementsNeedingSort++;
				}
			}
			String output = nElementsNeedingSort + ".000000";
			System.out.println("Case #" + caseNo + ": " + output);
			
		}

	}

}
