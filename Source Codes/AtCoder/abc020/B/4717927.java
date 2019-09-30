import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	String A = sc.next();
	String B = sc.next();
	String tmp = A+B;
	long sum = Long.parseLong(tmp);
	sum *= 2;
	System.out.println(sum);
    }
}