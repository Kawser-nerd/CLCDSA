import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {
	public static void dame_mons(ArrayList<Integer> mons,int a_index,int b_index) {
		if(mons.size() < 2) {
			return;
		}
		int a = mons.get(a_index);
		int b = mons.get(b_index);
		mons.set(b_index, b % a);
		if(b % a == 0) {
			mons.remove(b_index);
			dame_mons(mons,0,1);
		}else {
			dame_mons(mons,b_index,a_index);
		}
		
	}
	public static int game_mons(ArrayList<Integer> mons) {
		mons.sort((a,b) -> Integer.compare(a, b));
		dame_mons(mons,0,1);
		
		return mons.get(0); 
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc  = new Scanner(System.in);
		int N = sc.nextInt();
		int result;
		ArrayList<Integer> mons = new ArrayList<Integer>();
		for(int i = 0; i < N; i++) {
			mons.add(sc.nextInt());
		}
		
		result = game_mons(mons);
		System.out.println(result);
		
		sc.close();
	}

}