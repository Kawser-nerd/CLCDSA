import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		String line = null;
		List<String> tmpList = new ArrayList<>();
		try (Scanner sc = new Scanner(System.in)) {
			line = sc.nextLine();

			String[] tmpArray = line.split(" ");
			int letterNum = Integer.parseInt(tmpArray[0]);
			//int letterLength = Integer.parseInt(tmpArray[1]);

			for(int i = 0;i<letterNum;i++){
				tmpList.add(sc.nextLine());
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
		tmpList.stream().sorted().forEach(i -> System.out.print(i));
	}
}