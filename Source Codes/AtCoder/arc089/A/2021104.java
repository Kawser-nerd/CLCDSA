import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		List<Pos>  list = new ArrayList<>();
		list.add(new Pos(0, 0, 0));
		for(int i = 0; i < N;i++){
			list.add(
				new Pos(scanner.nextInt(), scanner.nextInt(), scanner.nextInt())
			);
		}
		
		Pos tmp = list.get(0);
		for (int i = 1; i < list.size(); i++) {
			if(!tmp.isSide(list.get(i))){
				System.out.println("No");
				return;
			}
		}
		System.out.println("Yes");
	}
	
	public static class Pos{
		public final int t;
		public final int x;
		public final int y;
		public Pos(int t, int x, int y){
			this.t = t;
			this.x = x;
			this.y = y;
		}
		
		public boolean isSide(Pos o){
			int time = o.t - this.t;
			int xAxis = Math.abs(this.x - o.x);
			int yAxis = Math.abs(this.y - o.y);
			return xAxis + yAxis <= time && time % 2 == (xAxis + yAxis) % 2 ;
		}
	}
}