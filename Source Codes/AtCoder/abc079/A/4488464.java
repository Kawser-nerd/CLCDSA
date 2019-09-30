import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws Exception {

//    	File file = new File("test.txt");
//    	Scanner sc = new Scanner(file);
    	Scanner sc = new Scanner(System.in);
    	String N = sc.next();
    	sc.close();
    	String ans = "No";
    	if((N.charAt(0) == N.charAt(1) &&
    			N.charAt(1) == N.charAt(2)) ||
    			(N.charAt(1) == N.charAt(2) &&
    			N.charAt(2) == N.charAt(3))) ans = "Yes";
    	System.out.println(ans);
    }
}