import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int A = sc.nextInt();
	int B = sc.nextInt();
	int tmp = (B-1)/A;
	System.out.println(tmp+1);
    }
}