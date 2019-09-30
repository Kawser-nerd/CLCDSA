import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int a = sc.nextInt();
	int b = sc.nextInt();
	int ans = Math.abs(a-b);
	int cnt = a+1+9-b;
	ans = Math.min(ans,cnt);
	int cnt2 = 9-a+1+b;
	ans = Math.min(ans,cnt2);

	System.out.println(ans);
    }
}