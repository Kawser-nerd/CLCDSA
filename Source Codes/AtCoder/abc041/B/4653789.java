import java.util.*;
class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	long a = sc.nextLong();
	long b = sc.nextLong();
	long c = sc.nextLong();
	System.out.println((a*b)%((long)Math.pow(10,9)+7)*c%((long)Math.pow(10,9)+7));
    }
}