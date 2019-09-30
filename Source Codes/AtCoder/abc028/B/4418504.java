import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		String s = scan.next();
		String[] ss = new String[s.length()];
		ss = s.split("");

		int countA = 0;
		int countB = 0;
		int countC = 0;
		int countD = 0;
		int countE = 0;
		int countF = 0;

		for(int i=0; i<ss.length; i++) {
			if(ss[i].contains("A"))
				countA++;
			else if(ss[i].contains("B"))
				countB++;
			else if(ss[i].contains("C"))
				countC++;
			else if(ss[i].contains("D"))
				countD++;
			else if(ss[i].contains("E"))
				countE++;
			else if(ss[i].contains("F"))
				countF++;
		}
		System.out.println(countA+" "+countB+" "+countC+" "+countD+" "
				+countE+" "+countF);
	}
}