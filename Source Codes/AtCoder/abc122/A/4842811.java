import java.util.Scanner;
public class Main {
	public static void main(String[] args) throws Exception {
		Scanner scan=new Scanner(System.in);
		char ch=(char)System.in.read();
		switch(ch) {
		case 'A':System.out.println("T");break;
		case 'G':System.out.println("C");break;
		case 'C':System.out.println("G");break;
		case 'T':System.out.println("A");break;
		}
	}
}