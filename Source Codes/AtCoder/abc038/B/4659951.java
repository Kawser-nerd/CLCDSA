import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int w1 = sc.nextInt();
	int h1 = sc.nextInt();
	int w2 = sc.nextInt();
	int h2 = sc.nextInt();
	if(w1==w2 || w1==h2 || h1==h2 || w2==h1) System.out.println("YES");
	else System.out.println("NO");
    }
}