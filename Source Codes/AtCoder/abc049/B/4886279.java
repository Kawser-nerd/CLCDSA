import java.util.Scanner;

public class Main{
	public static void main(String args[]){
		Scanner scan = new Scanner(System.in);

		int h = scan.nextInt();
		int w = scan.nextInt();

		String[] str = new String[h];
		for(int i = 0; i < h; i++){
			str[i] = scan.next();
		}

		for(int i = 0; i < h; i++){
			System.out.println(str[i]);
			System.out.println(str[i]);
		}
	}
}