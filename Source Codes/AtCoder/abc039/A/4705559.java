import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int A = sc.nextInt();
	int B = sc.nextInt();
	int C = sc.nextInt();
	System.out.println(A*B*2+B*C*2+C*A*2);
    }
}