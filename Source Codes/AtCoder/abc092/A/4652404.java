import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
	int train = Math.min(sc.nextInt(), sc.nextInt());
	int bus	= Math.min(sc.nextInt(), sc.nextInt());
	System.out.println(train+bus);
    }
}