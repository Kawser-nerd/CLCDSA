import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int a = Integer.parseInt(sc.next());
		int b = Integer.parseInt(sc.next());
		int c = Integer.parseInt(sc.next());
		if(a<b){
			if(c<a){
				System.out.println(b-c);
			}else {
				if(b>c) {
					System.out.println(b-a);
				}else {
					System.out.println(c-a);
				}
			}
		}else {
			if(b>c) {
				System.out.println(a-c);
			}else{
				if(a>c) {
					System.out.println(a-b);
				}else {
					System.out.println(c-b);
				}
			}
		}

	}
}