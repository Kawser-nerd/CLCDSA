import java.util.*;
class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int x = sc.nextInt();
	int y = sc.nextInt();
	int z = sc.nextInt();
	int ans = x/(z+y);
	if(ans*(z+y)+z<=x) System.out.println(ans);
	else System.out.println(ans-1);
    }
}