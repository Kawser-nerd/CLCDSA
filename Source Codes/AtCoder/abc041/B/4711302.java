import java.util.*;

public class Main{
    public static final long MOD = 1000000000+7;    
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	long A = sc.nextLong();
	long B = sc.nextLong();
	long C = sc.nextLong();
	long X = A*B;
	X %= MOD;
	X *= C;
	X %= MOD;
	System.out.println(X);
    }
}