import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		try (Scanner scTmp = new Scanner(System.in);) {

			String sTmp = scTmp.nextLine();
			String sOut = "";
			int iLen = sTmp.length();

			for (int i = 0; i < iLen; i++) {
				char cTmp = sTmp.charAt(i);
				switch (cTmp) {
				case '0':
					sOut = sOut.concat("0");
					break;
				case '1':
					sOut = sOut.concat("1");
					break;
				case 'B':
					if (sOut.length() > 0) {
						sOut = sOut.substring(0, sOut.length() - 1);
					}
					break;
				}
			}

			System.out.println(sOut);
		}
	}
}