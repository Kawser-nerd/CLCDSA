import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String str1 = scan.nextLine();
		String str2 = scan.nextLine();
		if (str1.equals(str2)) {
			System.out.println("Yes");
			return;
		}
		String[] str_arr = new String[str1.length() - 1];
		for (int i = 0; i < str1.length() - 1; i++) {
			str_arr[i] = str1.substring(i + 1, str1.length()) + str1.substring(0, i + 1);
		}
		for (int i = 0; i < str_arr.length; i++) {
			if(str_arr[i].equals(str2)){
				System.out.println("Yes");
				return;
			}
		}
		System.out.println("No");
	}

}