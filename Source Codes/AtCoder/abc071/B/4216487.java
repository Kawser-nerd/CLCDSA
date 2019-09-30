import java.util.Scanner;
public class Main {
public static void main(String[]srgs) {
	Scanner scan=new Scanner(System.in);
	String a=scan.next();
	String alfa[]= {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
	int ans=0;
	for(int i=0;i!=alfa.length;i++) {
		if(a.indexOf(alfa[i])==-1) {
			System.out.println(alfa[i]);
			return;
		}
	}
	System.out.println("None");
	scan.close();
}
}