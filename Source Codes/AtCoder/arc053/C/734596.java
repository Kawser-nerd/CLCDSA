import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		//??
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();
		List<Magic> magicListA = new ArrayList<Magic>();
		List<Magic> magicListB = new ArrayList<Magic>();
		for(int i=0; i<N; i++){
			int up = scan.nextInt();
			int down = scan.nextInt();
			if(up<=down){
				magicListA.add(new Magic(up,down));
			}else{
				magicListB.add(new Magic(up,down));
			}
		}		
		scan.close();
		
		// ???
		Collections.sort(magicListA, new Comparator<Magic>() {
			public int compare(Magic m1, Magic m2) {
				return m1.up - m2.up;
			}
		});
		Collections.sort(magicListB, new Comparator<Magic>() {
			public int compare(Magic m1, Magic m2) {
				return m2.down - m1.down;
			}
		});
		long max = 0;
		long current = 0;
		for(Magic m: magicListA){
			current += m.up;
			max = Math.max(max,current);
			current -= m.down;
		}
		for(Magic m: magicListB){
			current += m.up;
			max = Math.max(max,current);
			current -= m.down;
		}
		
		// ??
		System.out.println(max);		
	}
	
	
	static class Magic{
		public Magic(int up, int down) {
			this.up = up;
			this.down = down;
		}
		int up;
		int down;
	}
}