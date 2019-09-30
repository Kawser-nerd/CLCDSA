import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.TreeMap;


public class C {

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new File("C-large.in"));
		PrintWriter pw = new PrintWriter("C-large.out");
//		Scanner sc = new Scanner(new File("C-small-attempt0.in"));
//		PrintWriter pw = new PrintWriter("C-small-attempt0.out");
//		Scanner sc = new Scanner(new File("C-small.in"));
//		PrintWriter pw = new PrintWriter("C-small.out");
		
		int tc = sc.nextInt();
		for(int t=1; t<=tc; t++){
			int N = sc.nextInt();
			int M = sc.nextInt();
			long[] boxes = new long[N];
			long[] toys = new long[M];
			int[] bType = new int[N];
			int[] tType = new int[M];
			for(int i=0; i<N; i++){
				boxes[i] = sc.nextLong();
				bType[i] = sc.nextInt();
			}
			
			for(int i=0; i<M; i++){
				toys[i] = sc.nextLong();
				tType[i] = sc.nextInt();
			}
			
			TreeMap<State, Long> map = new TreeMap<State, Long>();
			pw.println("Case #" + t + ": " + doDp(map, boxes, bType, toys, tType, new State(0,0,boxes[0],toys[0])));
		}
		
		pw.close();
		sc.close();
	}
	
	private static long doDp(TreeMap<State, Long> map, long[] boxes,
			int[] bType, long[] toys, int[] tType, State state) {
		
		if(map.containsKey(state)){
			return map.get(state);
		}
		
		if(state.b == boxes.length || state.t == toys.length)
			return 0;
		
		if(bType[state.b] == tType[state.t] ){
			long ret = Math.min(state.bc, state.tc);
			State newState = new State(state.b, state.t, state.bc, state.tc);
			newState.tc -= ret;
			newState.bc -= ret;
			
			if(newState.tc == 0){
				newState.t++;
				if(newState.t < toys.length)
					newState.tc = toys[newState.t];
			}
			
			if(newState.bc == 0){
				newState.b++;
				if(newState.b < boxes.length)
					newState.bc = boxes[newState.b];
			}
			
			ret += doDp(map, boxes, bType, toys, tType, newState);
			map.put(state, ret);
			return ret;
		}else{
			State newState = new State(state.b+1, state.t, 0, state.tc);
			if(newState.b < boxes.length) newState.bc = boxes[newState.b];
			long one = doDp(map, boxes, bType, toys, tType, newState);
			
			newState = new State(state.b, state.t+1, state.bc, 0);
			if(newState.t < toys.length) newState.tc = toys[newState.t];
			long two = doDp(map, boxes, bType, toys, tType, newState);
			long best = Math.max(one, two);
			map.put(state, best);
			return best;
		}
		
	}

	static class State implements Comparable<State>{
		int b;
		int t;
		long bc;
		long tc;
		public State(int b, int t, long bc, long tc){
			this.b=b;
			this.t=t;
			this.bc=bc;
			this.tc=tc;
		}
		
		public boolean equals(Object o){
			State rhs = (State)o;
			if(b==rhs.b && t==rhs.t && bc==rhs.bc && tc==rhs.tc){
				return true;
			}
			return false;
		}
		
		public int compareTo(State rhs){
			int l = b*100+t;
			int r = rhs.b*100+rhs.t;
			if(l!=r) return l-r;
			if(bc < rhs.bc) return -1;
			if(bc > rhs.bc) return 1;
			if(tc < rhs.tc) return -1;
			if(tc > rhs.tc)return 1;
			return 0;
		}
		
	}

}
