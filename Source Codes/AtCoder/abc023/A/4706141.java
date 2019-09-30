import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	String X = sc.next();
	int sum = 0;
	sum += X.charAt(0)-'0';
	sum += X.charAt(1)-'0';
	System.out.println(sum);
    }
}