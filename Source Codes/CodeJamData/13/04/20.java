import java.util.*;
import java.io.*;

public class D{
	public static void main(String[] args) throws Exception{
		BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
		
		int cases = Integer.parseInt(sc.readLine());
		a: for(int z=1; z<=cases; z++){
			StringTokenizer st = new StringTokenizer(sc.readLine());
			int k = Integer.parseInt(st.nextToken());
			int n = Integer.parseInt(st.nextToken());
			
			int[] keys = new int[200];
			st = new StringTokenizer(sc.readLine());
			while(st.hasMoreTokens()){
				keys[Integer.parseInt(st.nextToken())-1]++;
			}
			int[] tot = Arrays.copyOf(keys, 200);
			int[] need = new int[200];
			
			Chest[] chests = new Chest[n];
			for(int i=0; i<n; i++){
				st = new StringTokenizer(sc.readLine());
				int key = Integer.parseInt(st.nextToken());
				st.nextToken();
				Chest c = new Chest(key-1);
				need[key-1]++;
				while(st.hasMoreTokens()){
					int blah = Integer.parseInt(st.nextToken())-1;
					c.keys.add(blah);
					tot[blah]++;
				}
				chests[i] = c;
			}
			for(int i=0; i<200; i++){
				if(need[i] > tot[i]){
					System.out.println("Case #"+z+": IMPOSSIBLE");
					continue a;
				}
			}
			boolean[] dummy = new boolean[n];
			
			Stack<State> stack = new Stack<State>();
			for(int i=chests.length-1; i>=0; i--){
				if( keys[chests[i].open] > 0 ){
					State s = new State(n-1, Arrays.copyOf(dummy, dummy.length), Arrays.copyOf(keys, keys.length), "");
					s.state[i] = true;
					s.keys[chests[i].open]--;
					s.sb.append(i+1);
					for(int j=0; j<chests[i].keys.size(); j++){
						s.keys[ chests[i].keys.get(j) ]++;
					}
					stack.push(s);
				}
			}
			
			State ans = null;
			while(stack.size()>0){
				State s = stack.pop();
				// System.out.println(s.sb);
				if(s.closed == 0){
					ans = s;
					break;
				}
				for(int i=chests.length-1; i>=0; i--){
					if(!s.state[i] && s.keys[chests[i].open] > 0){
						State temp = new State(s.closed-1, Arrays.copyOf(s.state, s.state.length), Arrays.copyOf(s.keys, s.keys.length), s.sb.toString());
						temp.state[i] = true;
						temp.keys[chests[i].open]--;
						temp.sb.append(" " + (i+1));
						for(int j=0; j<chests[i].keys.size(); j++){
							temp.keys[chests[i].keys.get(j)]++;
						}
						
						boolean no = false;
						b: for(int j=0; j<chests.length; j++){
							if(!temp.state[j] && temp.keys[chests[j].open] == 0){
								for(int l=0; l<chests.length; l++){
									if(chests[l].open == chests[j].open) continue;
									if(chests[l].keys.contains(chests[j].open)) continue b;
								}
								no = true;
								break;
							}
						}
						if(!no){
							stack.push(temp);
						}
					}
				}
			}
			if(ans == null){
				System.out.println("Case #"+z+": IMPOSSIBLE");
			}else{
				System.out.println("Case #"+z+": "+ans.sb);
			}
		}
		
	}
}

class Chest{
	int open;
	ArrayList<Integer> keys = new ArrayList<Integer>();
	public Chest(int a){
		open = a;
	}
}

class State{
	StringBuilder sb;
	int closed;
	boolean[] state;
	int[] keys;
	public State(int a, boolean[] b, int[] c, String s){
		closed = a;
		state = b;
		keys = c;
		sb = new StringBuilder(s);
	}
}