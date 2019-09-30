import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc=new Scanner(System.in);

		String str=sc.next();
		String ans="";

		if(str.equals("A")) ans="T";
		else if(str.equals("C")) ans="G";
		else if(str.equals("G")) ans="C";
		else ans="A";

		System.out.println(ans);

		sc.close();

	}

}