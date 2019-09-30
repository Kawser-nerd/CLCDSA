import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);

		String name = scn.next();

		name = name.substring(0,1).toUpperCase()+name.substring(1,name.length()).toLowerCase();
		System.out.println(name);
	}
}