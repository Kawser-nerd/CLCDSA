import java.util.*;

public class Main {
	static class Magic {
		int a,b;

		public Magic(int a, int b) {
			this.a = a;
			this.b = b;
		}
		
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		ArrayList<Magic> asc = new ArrayList<Magic>();
		ArrayList<Magic> desc = new ArrayList<Magic>();
		for(int i=0; i<N; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			if(a>b)
				asc.add(new Magic(a, b));
			else
				desc.add(new Magic(a, b));
		}
		
		Collections.sort(desc, new Comparator<Magic>() {
			public int compare(Magic m1, Magic m2) {
				return m1.a-m2.a;
			}
		});
		
		Collections.sort(asc, new Comparator<Magic>() {
			public int compare(Magic m1, Magic m2) {
				return -(m1.b-m2.b);
			}
		});
		
		long temp = 0;
		long max = 0;
		
		for(Magic m : desc) {
			temp += m.a;
			max = Math.max(max, temp);
			temp -= m.b;
		}
		for(Magic m : asc) {
			temp += m.a;
			max = Math.max(max, temp);
			temp -= m.b;
		}
		
		System.out.println(max);
		sc.close();
	}
	
}