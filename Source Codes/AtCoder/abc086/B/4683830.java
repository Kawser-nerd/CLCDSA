import java.util.*;
class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int a = sc.nextInt();
	int b = sc.nextInt();
	int lnb = (int)Math.log10(b)+1;
	int num = a*(int)Math.pow(10,lnb) + b;
	for(int i = 1; i*i<=num; i++) {
	    if(i*i==num) {
		System.out.println("Yes");
		return;
	    }
	}
	System.out.println("No");
    }
}