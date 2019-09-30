import java.util.*;
class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int a = sc.nextInt();
	int b = sc.nextInt();
	int c = sc.nextInt();
	int d = sc.nextInt();
	int dist = Math.min(b,d)-Math.max(a,c);
	System.out.println((dist<0)?0:dist);
    }
}