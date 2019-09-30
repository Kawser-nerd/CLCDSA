import java.util.Scanner;
//??????????????Mian???
public class Main{
	public static void main(String[] args){

		int num;

		try(Scanner scan = new Scanner(System.in);){

			num = scan.nextInt();

		}

		num++;

		if(num >= 13) {

			num = 1;
		}

		System.out.println(num);

	}
}