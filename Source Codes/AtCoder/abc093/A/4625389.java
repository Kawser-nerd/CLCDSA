import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		char[] str = scn.nextLine().toCharArray();
		boolean a=false,b=false,c=false;
		for(int i = 0;i < 3;i++) {
			if(str[i] == 'a')a = true;
			if(str[i] == 'b')b = true;
			if(str[i] == 'c')c = true;
		}
		System.out.println(a&&b&&c?"Yes":"No");
	}

}