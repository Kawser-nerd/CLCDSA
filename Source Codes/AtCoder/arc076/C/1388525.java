import java.util.*;

public class Main {
	static int R, C;
	public static class Terminal {
		int d;
		int idx;
		public Terminal(int d, int idx) {
			this.d = d;
			this.idx = idx;
		}
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		R = sc.nextInt();
		C = sc.nextInt();
		int N = sc.nextInt();
		ArrayList<Terminal> list = new ArrayList<>();
		
		for(int i=0; i<N; i++) {
			int x1 = sc.nextInt();
			int y1 = sc.nextInt();
			int x2 = sc.nextInt();
			int y2 = sc.nextInt();
			
			if(isOnEdge(x1, y1) && isOnEdge(x2, y2)) {
				list.add(new Terminal(convert(x1, y1), i));
				list.add(new Terminal(convert(x2, y2), i));
			}
		}
		Collections.sort(list, new Comparator<Terminal>() {
			public int compare(Terminal t1, Terminal t2) {
				return t1.d - t2.d;
			}
		});
		
		LinkedList<Terminal> stack = new LinkedList<>();
		
		for(Terminal t : list) {
			if(!stack.isEmpty() && stack.peek().idx == t.idx)
				stack.pop();
			else
				stack.push(t);
		}
		
		System.out.println(stack.isEmpty() ? "YES" : "NO");
		
		sc.close();
	}
	
	static boolean isOnEdge(int x, int y) {
		return x==0 || x==R || y==0 || y==C;
	}
	
	static int convert(int x, int y) {
		if(x==0)
			return y;
		else if(y==C)
			return C + x;
		else if(x==R)
			return C + R + (C-y);
		else
			return C + R + C + (R-x);
	}
}