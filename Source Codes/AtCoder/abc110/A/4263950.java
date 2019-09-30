import java.util.*;

class Main {
	public static void main(String args[]) {
    	Scanner s = new Scanner(System.in);
      	int a = s.nextInt();
      	int b = s.nextInt();
      	int c = s.nextInt();
      	int ans = max(max(a*10+b+c,b*10+a+c),c*10+a+b);
      	System.out.println(ans);
    }
  	static int max (int a, int b) {
      return a > b ? a : b;
    }
}