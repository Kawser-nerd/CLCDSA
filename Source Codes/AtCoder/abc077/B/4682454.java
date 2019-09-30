import java.util.*;
class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int N = sc.nextInt();
	int max = 0;
	for(int i = 1; i*i<=N; i++) {
	    max = Math.max(max, i*i);
	}
	System.out.println(max);
    }
}