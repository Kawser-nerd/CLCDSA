import java.util.Scanner;
 
public class Main {
 
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
        
        String s1 = sc.next();
        String s2 = sc.next();
        String s3 = sc.next();
        s1 = s1.toUpperCase();
        s2 = s2.toUpperCase();
        s3 = s3.toUpperCase();
        
        
        System.out.println(("" +s1.charAt(0) + s2.charAt(0) + s3.charAt(0)).toUpperCase());
	}
 
}