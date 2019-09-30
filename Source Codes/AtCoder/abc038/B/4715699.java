import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int H1 = sc.nextInt();
	int W1 = sc.nextInt();
	int H2 = sc.nextInt();
	int W2 = sc.nextInt();
	if ( H1 ==  H2 || W1 == W2 ) {
	    System.out.println("YES");
	    return;
	}
	int tmp;
	tmp = H2;
	H2 = W2;
	W2 = tmp;
	if ( H1 ==  H2 || W1 == W2 ) {
	    System.out.println("YES");
	    return;
	}
	System.out.println("NO");
    }
}