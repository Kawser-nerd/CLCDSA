import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc=new Scanner(System.in);

		String str=sc.next();

		String[] strs=str.split("/");

		if(Integer.parseInt(strs[1])>4) System.out.println("TBD");
		else System.out.println("Heisei");

		sc.close();

	}

}