import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
	int a =	sc.nextInt();
	int b =	sc.nextInt();
	int c =	sc.nextInt();
	int d =	sc.nextInt();
	int ab = (int)Math.abs(a-b);
	int bc = (int)Math.abs(b-c);
	int ca = (int)Math.abs(c-a);
	if(ca<=d) {
            System.out.println("Yes");
            return;
        }
	if(ab<=d && bc<=d) {
            System.out.println("Yes");
            return;
        }
        System.out.println("No");
    }
}