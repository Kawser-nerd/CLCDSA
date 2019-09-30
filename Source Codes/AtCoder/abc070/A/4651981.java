import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
	int x =	sc.nextInt();
	if(x%10 == x/100) System.out.println("Yes");
        else System.out.println("No");
    }
}