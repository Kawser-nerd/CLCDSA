import java.util.LinkedList;
import java.util.Scanner;

public class Main {
	
	static long  baseTime;
	static long  nowTime;

	private void solve() {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int[][] LR = new int[N][2];
		for(int i=0;i<N; i++) {
			LR[i][0] = in.nextInt();
			LR[i][1] = in.nextInt();
		}
		
		LinkedList<Range> list = new LinkedList<>();
		LinkedList<Range> list2 = new LinkedList<>();
		for(int i=0;i<N; i++) {
			Range range = new Range(LR[i][0],LR[i][1]);
			list.add(range);
			list2.add(range);
		}
		
		long sum1 = game(list,list2,true);
		
		list = new LinkedList<>();
		list2 = new LinkedList<>();
		for(int i=0;i<N; i++) {
			Range range = new Range(LR[i][0],LR[i][1]);
			list.add(range);
			list2.add(range);
		}
		long sum2 = game(list,list2,false);
		
		System.out.println(Math.max(sum1,sum2));
		
	}
	
	public static void main(String[] args) {
		new Main().solve();
	}
	
	public long game(LinkedList<Range> list,LinkedList<Range>list2, boolean toRight) {
			list.sort((a,b)->b.left-a.left);
			list2.sort((a,b) -> a.right-b.right);
			
			int base = 0;
			long sum = 0;
			loop : while(!list.isEmpty()) {
				int distance;
				int nextBase;
				if(toRight) {
					while(list.get(0).used) {
						list.remove(0);
						if(list.isEmpty()) break loop;
					}
					nextBase = list.get(0).left;
					distance = nextBase-base;
					list.get(0).used = true;
					list.remove(0);
				}else{
					while(list2.get(0).used) {
						list2.remove(0);
						if(list2.isEmpty()) break loop;
					}
					nextBase = list2.get(0).right;
					distance = base-nextBase;
					list2.remove(0);
				}
				if(distance<0) break;
				sum += distance;
				base = nextBase;
				toRight = !toRight;
			}
			return sum + Math.abs(base);	
	}
	
	class Range{
		boolean used;
		int left;
		int right;
		
		public Range(int left, int right) {
			this.used = false;
			this.left = left;
			this.right = right;
		}
	}
}