import java.util.Scanner;

public class Main {
	public static void main(String args[]){
		Scanner s = new Scanner(System.in);

		String c = s.next();
		int max = c.length();

		for (int i=1; i < c.length(); i++) {
      if (c.charAt(i) != c.charAt(i-1)) {
        max = Math.min(max, Math.max(i ,c.length()-i));
      }
    }

		System.out.println(max);
	}
}