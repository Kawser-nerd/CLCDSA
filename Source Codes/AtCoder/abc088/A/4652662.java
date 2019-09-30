import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
	int n = sc.nextInt();
	int a =	sc.nextInt();
	if(n%500<=a) System.out.println("Yes");
        else System.out.println("No");
    }
}