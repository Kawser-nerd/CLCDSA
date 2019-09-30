import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		char[] str = scn.nextLine().toCharArray();
		int ans = 700;
		for(int i = 0;i < 3;i++) {
			if(str[i] == 'o')ans += 100;
		}
		System.out.println(ans);
	}

}