import java.util.*;

public class Main {
	
	public class RMQ {
		int n;
		int [] data;
		int [] ind;
		int MAX = Integer.MAX_VALUE;
		
		public RMQ(int n) {
			this.n = 1;
			while(this.n < n) this.n *= 2;
			data = new int[2 * this.n - 1];
			Arrays.fill(data, MAX);
			ind = new int[2 * this.n - 1];
			Arrays.fill(ind, -1);
			for(int i = this.n-1; i < ind.length; i++){
				ind[i] = i - (this.n - 1);
			}
		}

		void update(int k, int a){
			k += n - 1;
			data[k] = a;
			while(k > 0){
				k = (k - 1) / 2;
				data[k] = Math.min(data[k * 2 + 1], data[k * 2 + 2]);
				ind[k] = minInd(k * 2 + 1, k * 2 + 2);
			}
		}
		
		int minInd(int left, int right){
			if(data[right] == MAX){
				return ind[left];
			}
			else if(data[left] == MAX){
				return ind[right];
			}
			
			if(data[left] < data[right]){
				return ind[left];
			}
			else{
				return ind[right];
			}
		}
		
		int query(int a, int b){
			return query(a, b, 0, 0, n);
		}
		
		int query(int a, int b, int k, int l, int r){
			if(r <= a || b <= l)return MAX;
			
			if(a <= l && r <= b) return data[k];
			else{
				int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
				int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
				return Math.min(vl, vr);
			}
		}
		
		int queryIndex(int a, int b){
			return queryIndex(a, b, 0, 0, n);
		}
		
		int queryIndex(int a, int b, int k, int l, int r){
			if(r <= a || b <= l)return -1;
			
			if(a <= l && r <= b) return ind[k];
			else{
				int vl = queryIndex(a, b, k * 2 + 1, l, (l + r) / 2);
				int vr = queryIndex(a, b, k * 2 + 2, (l + r) / 2, r);
				if(vl == -1 && vr == -1){
					return -1;
				}
				else if(vr == -1){
					return vl;
				}
				else if(vl == -1){
					return vr;
				}
				if(data[n-1 + vl] < data[n-1 + vr]){
					return vl;
				}
				else{
					return vr;
				}
			}
		}

	}
	
	class C implements Comparable<C>{
		int left, right, value, ind;

		public C(int left, int right, int ind, int value) {
			super();
			this.left = left;
			this.right = right;
			this.value = value;
			this.ind = ind;
		}

		@Override
		public int compareTo(C o) {
			return this.value - o.value;
		}

		@Override
		public String toString() {
			return "C [left=" + left + ", right=" + right + ", value=" + value + ", ind=" + ind + "]";
		}
		
	}
	
	private void doit(){
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			int n = sc.nextInt();
			int [] data = new int[n];
			RMQ even = new RMQ(n);
			RMQ odd = new RMQ(n);
			
			for(int i = 0; i < n;i++){
				data[i] = sc.nextInt();
				if(i % 2 == 0){
					even.update(i, data[i]);
				}
				else{
					odd.update(i, data[i]);
				}
			}
			
			PriorityQueue<C> open = new PriorityQueue<>();
			int ind = even.queryIndex(0, n);
			open.add(new C(0, n, ind, data[ind]));
			
			StringBuilder sb = new StringBuilder();
			while(!open.isEmpty()){
				C now = open.poll();
				
				int resInd;
				if(now.right % 2 == 0){
					resInd = odd.queryIndex(now.ind + 1, now.right);
				}
				else{
					resInd = even.queryIndex(now.ind + 1, now.right);
				}
				sb.append(" " + now.value + " " + data[resInd]);

				if(now.left + 1 == now.right) continue;
				
				int leftind;
				if(now.left % 2 == 0){
					leftind = even.queryIndex(now.left, now.ind);
				}
				else{
					leftind = odd.queryIndex(now.left, now.ind);
				}
				if(leftind != -1){
					open.add(new C(now.left, now.ind, leftind, data[leftind]));
				}
				
				
				int centerind;
				if((now.ind + 1) % 2 == 0){
					centerind = even.queryIndex(now.ind + 1, resInd);
				}
				else{
					centerind = odd.queryIndex(now.ind + 1, resInd);
				}
				if(centerind != -1){
					open.add(new C(now.ind + 1, resInd, centerind, data[centerind]));
				}
				
				int rightind;
				if((resInd + 1) % 2 == 0){
					rightind = even.queryIndex(resInd+1, now.right);
				}
				else{
					rightind = odd.queryIndex(resInd + 1, now.right);
				}
				if(rightind != -1){
					open.add(new C(resInd + 1, now.right, rightind, data[rightind]));
				}
			}
			System.out.println(sb.substring(1));
		}
	}



	private void debug(Object... o) {
		System.out.println("debug = " + Arrays.deepToString(o));
	}

	public static void main(String[] args) {
		new Main().doit();
	}

}