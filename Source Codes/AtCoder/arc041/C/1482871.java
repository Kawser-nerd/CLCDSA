import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
                Scanner sc = new Scanner(System.in);            
		int n = sc.nextInt();
		int l = sc.nextInt();
		
		ArrayDeque<Integer> rq = new ArrayDeque<Integer>();
		ArrayDeque<Integer> lq = new ArrayDeque<Integer>();
		long ans = 0;
		long sumi_cnt = 0;
		
		for (int i = 0; i < n; i++) {
			int x = sc.nextInt();
			char direction = sc.next().charAt(0);
			
			if(direction == 'L') {	
				if(rq.isEmpty()) {		
					long cnt = x - 1 - sumi_cnt;
					ans += cnt;
					sumi_cnt++;
				} else {
					lq.addLast(x);
				}
			} else {
				if(lq.isEmpty()) {
					rq.addLast(x);
				} else {
					long cnt = calc(rq, lq);
					ans += cnt;
					rq.push(x);
				}
			}
		}

		if(lq.isEmpty()) {

			sumi_cnt = 0;
			while(rq.size() > 0) {
				int x = rq.pollLast();

				long cnt = l - x - sumi_cnt;

				ans += cnt;
				sumi_cnt++;
			}
		} else {
			ans += calc(rq, lq);
		}
		System.out.println(ans);
	}
	
	static long calc(ArrayDeque<Integer> rq, ArrayDeque<Integer> lq) {

		int rx = rq.pollLast();
		int rcount = 1;
		long ans = 0;
		while(rq.size() > 0) {
			int x = rq.pollLast();
			long cnt = rx - x - rcount;
			ans += cnt;
			rcount++;
		}
		int lx = lq.pollFirst();
		int lcount = 1;
		while(lq.size() > 0) {
			int x = lq.pollFirst();
			long cnt = x - lx - lcount;
			ans += cnt;
			lcount++;
		}
		long max_cnt = Math.max(rcount, lcount);
		long cnt = max_cnt * (lx - rx - 1);
		ans += cnt;
		return ans;
	}
}