import java.util.Scanner;
//??????????????Mian???
public class Main{
	public static void main(String[] args){

		String moji;

		try(Scanner scan = new Scanner(System.in);){

			moji = scan.next();

		}

		if(moji.length() >= 2) {
			moji = moji.substring(0,1).toUpperCase() + moji.substring(1).toLowerCase();
		}else if(moji.length() == 1) {
			moji = moji.toUpperCase();
		}

		System.out.println(moji);

	}
}