import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		//Blue_card
		int how_b = sc.nextInt();
		String blue[] = new String[how_b];
		for(int i=0 ; i<blue.length ; i++) {
			blue[i] = sc.next();
		}
		//Red_card
		int how_r = sc.nextInt();
		String red[] = new String[how_r];
		for(int i=0 ; i<red.length ; i++) {
			red[i] = sc.next();
		}
		int ans=0;
		int get_money;
		
		for(int j=0 ; j<blue.length ; j++) {
			get_money=0;
			for(int i=0 ; i<blue.length ; i++) {
				if(blue[j].equals(blue[i])) {
					get_money++;
				}
			}
			for(int i=0 ; i<red.length ; i++) {
				if(blue[j].equals(red[i])) {
					get_money--;
				}
			}
			if(ans < get_money) {
				ans = get_money;
			}
		}
		System.out.print(ans);
	}

}