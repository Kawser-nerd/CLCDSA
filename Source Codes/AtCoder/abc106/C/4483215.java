import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
    	Scanner input = new Scanner(System.in);
      	String S = input.next();
      	long K = input.nextLong();
      	String ans = "";
      	double days = 5.0 * Math.pow(10, 15);
      	for (int i = 0; i < S.length(); i++) {
        	char c = S.charAt(i);
          	int n = Character.getNumericValue(c);
          	K -= (long)Math.pow(n, days);
          	if (K <= 0) {
              	System.out.println(c);
            	return;
            }
        }
    } 	
}