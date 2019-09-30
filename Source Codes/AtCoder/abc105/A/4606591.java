import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		if(sc.nextInt()%sc.nextInt()==0) {
			System.out.println(0);	
		}else {
			System.out.println(1);
		}
	}
}