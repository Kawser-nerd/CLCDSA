import java.util.*;
class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int N = sc.nextInt();
	int h = N/60/60;
	int m = N/60 - h*60;
	int s = N%60;
	System.out.printf("%02d:%02d:%02d",h,m,s);
	System.out.println();
    }
}