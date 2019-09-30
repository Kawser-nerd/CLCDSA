import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
	int a =	sc.nextInt();
	int b =	sc.nextInt();
	if(b>a)	{
            System.out.println(Math.min(b-a, 10-(b-a)));
	}else {
            System.out.println(Math.min(a-b, 10-(a-b)));
	}
    }
}