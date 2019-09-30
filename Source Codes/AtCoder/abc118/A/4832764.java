import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
        int c = b % a;
        if(c == 0) System.out.println(a+b);
        else System.out.println(b-a);
	}
}