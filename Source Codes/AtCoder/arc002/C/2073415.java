import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	public static void main(String args[]){
		// ??????
		String[] str_list= new String[4];
		str_list[0] = "A";
		str_list[1] = "B";
		str_list[2] = "X";
		str_list[3] = "Y";
		// 2??????
		ArrayList<String> str2list = new ArrayList<String>();
		for (int i = 0; i < 4; i++){
			for (int j = 0; j < 4; j++){
				String strTmp = str_list[i] + str_list[j];
				str2list.add(strTmp);
			}
		}

		// ????
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		String command = scan.next();
		scan.close();

		// ???2??????????????
		int min = n;
		for (int i = 0; i < 16; i++){
			for (int j = i + 1; j < 16; j++){
				String str1 = str2list.get(i);
				String str2 = str2list.get(j);
				int newMin = commandMin(str1, str2, n, command);
				if (newMin < min) min =newMin;
			}
		}

		System.out.println(min);
	}

	public static int commandMin(String str1, String str2, int n, String command){
		int i = 0;
		// ???????????
		int m = n;
		while (true) {
			if (i > n - 2) break;
		    String comStr1 = String.valueOf(command.charAt(i));
		    String comStr2 = String.valueOf(command.charAt(i + 1));
		    String strTmp = comStr1 + comStr2;
			if (strTmp.equals(str1) || strTmp.equalsIgnoreCase(str2)) {
				m -= 1;
				i += 2;
			} else {
				i ++;
			}
		}
		return m;
	}
}