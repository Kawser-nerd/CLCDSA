import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
	int x =	sc.nextInt();
	if(x%10 == 9 || x/10 == 9) System.out.println("Yes");
        else System.out.println("No");
    }
}