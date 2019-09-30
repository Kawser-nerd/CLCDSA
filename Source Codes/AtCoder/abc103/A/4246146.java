import java.util.*;
class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int a1 = sc.nextInt();
	int a2 = sc.nextInt();
	int a3 = sc.nextInt();
	int b1 = (int)(Math.abs(a1-a2));
	int b2 = (int)(Math.abs(a3-a2));
	int b3 = (int)(Math.abs(a1-a3));
	int max = Math.max(b1,Math.max(b2,b3));
	System.out.println(b1+b2+b3-max);

    }
}