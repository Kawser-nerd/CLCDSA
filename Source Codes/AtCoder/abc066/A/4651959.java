import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
	int a =	sc.nextInt();
	int b =	sc.nextInt();
	int c =	sc.nextInt();
	int ab = a+b;
	int bc = b+c;
	int ca = c+a;
	int ans	= Math.min(ab,bc);
	System.out.println(Math.min(ans,ca));
    }
}