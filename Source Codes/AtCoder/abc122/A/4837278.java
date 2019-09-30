import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner stdin = new Scanner(System.in);
		String a,b;
		a = stdin.next();
		switch(a) {
		case "A" :System.out.print("T");break;
		case "T" :System.out.print("A");break;
		case "C" :System.out.print("G");break;
		case "G" :System.out.print("C");break;
		}
	}
}