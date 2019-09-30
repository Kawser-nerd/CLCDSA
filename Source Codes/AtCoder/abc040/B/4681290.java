import java.util.*;
class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int n = sc.nextInt();
	int min = Integer.MAX_VALUE;
	for(int i = 1; i<=n; i++) {
	    int x = (int)Math.abs((n/i)-i) + n%i;
	    min = Math.min(x,min);
	}
	System.out.println(min);
    }
}