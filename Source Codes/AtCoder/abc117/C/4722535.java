import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {
	public static int mark_game(ArrayList<Integer> lenge,int N) {
		int result = 0;
		if(N <= 1) {
			for(int x : lenge) {
				result += x;
			}
			return result;
		}

		lenge.remove(lenge.size()-1);
		return mark_game(lenge,N-1);
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc  = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		ArrayList<Integer> data = new ArrayList<Integer>();
		ArrayList<Integer> lenge = new ArrayList<Integer>();
		
		for(int i = 0; i < M; i++) {
			data.add(sc.nextInt());
		}
		data.sort((a,b) -> Integer.compare(a,b));
		
		for(int i = 0; i < M-1; i++) {
			lenge.add(Math.abs(data.get(i)-data.get(i+1)));
		}
		lenge.sort((a,b) -> Integer.compare(a,b));
		
		if(N >= M) {
			System.out.println(0);
		}else {
			System.out.println(mark_game(lenge,N));
		}
		
		
		sc.close();
	}
}