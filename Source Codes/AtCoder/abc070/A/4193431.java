import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String inpt =  sc.next();
		sc.close();
		String [] sort = inpt.split("");
		String otpt = sort[2]+sort[1]+sort[0];
		System.out.println(inpt.equals(otpt)? "Yes":"No");
	}
}