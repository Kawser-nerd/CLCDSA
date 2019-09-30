import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int d=sc.nextInt();
		if(d==25)System.out.println("Christmas");
		if(d==24)System.out.println("Christmas Eve");
		if(d==23)System.out.println("Christmas Eve Eve");
		if(d==22)System.out.println("Christmas Eve Eve Eve");
	}
}