import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO ???????????????
		Scanner scan = new Scanner(System.in);
		String InStr = scan.nextLine();

		String[] AryStr = InStr.split(" ");

		long cnt5 = 0;
		long cnt7 = 0;
		int i = 0;
      
		while(i <= 2) {
          if (AryStr[i].equals("5") ) {
				cnt5++;
			}
			if (AryStr[i].equals("7") ) {
				cnt7++;
			}
			i++;
		}

		if (cnt5 == 2 && cnt7 == 1) {
			System.out.println("YES");
		} else {
			System.out.println("NO");
		}
		scan.close();
	}
}