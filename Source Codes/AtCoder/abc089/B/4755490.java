import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		String color[] = new String[N];
		boolean or = false;
		for(int i = 0; i<N; i++) {
			color[i]= sc.next();
			if(color[i].equals("Y"))or = true;
		}
		if(!or)System.out.println("Three");
		else System.out.println("Four");
		sc.close();
	}

}