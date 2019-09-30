import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int a = sc.nextInt();
	int b = sc.nextInt();
	int tmp = (a-1)/b;
	int sum = b*(tmp+1);
	int ans = sum -a;
	System.out.println(ans);
    }
}