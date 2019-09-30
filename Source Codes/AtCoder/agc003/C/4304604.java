import java.util.LinkedList;
import java.util.Scanner;

public class Main {
	private class Num implements Comparable<Num>{
		private int index = 0;
		private int num = 0;
		
		public Num(int index, int num) {
			this.index = index;
			this.num = num;
		}
		
		public boolean isEvenOrOdd(int evenOrOdd) {
			return (this.index % 2 == evenOrOdd);
		}

		@Override
		public int compareTo(Num o) {
			return Integer.compare(this.num, o.num);
		}
	}
	
	public long solve() {
		LinkedList<Num> list = new LinkedList<Num>();
		try (Scanner in = new Scanner(System.in)) {
			int N = in.nextInt();
			
			for (int i=0; i<N; i++) {
				list.addLast(new Num(i, in.nextInt()));
			}
		}
		list.sort(null);
		
		long count = 0;
		int index = 0;
		for (Num n : list) {
			if (n.isEvenOrOdd(index % 2) == false) {
				count++;
			}
			index++;
		}
		
		return count / 2;
	}
	
	public static void main(String[] args) {
		Main main = new Main();
		System.out.println(main.solve());
	}
}