import java.util.*;
public class c {
public static void main(String[] args)
{
	Scanner input = new Scanner(System.in);
	int T = input.nextInt();
	for(int t = 0; t<T; t++)
	{
		System.out.printf("Case #%d: ", t+1);
		int n = input.nextInt();
		char[] last = new char[2001];
		int[] lasti = new int[2001];
		Arrays.fill(lasti, -1);
		Arrays.fill(last, 'a');
		boolean good = true;
		char[] types = new char[n];
		int[] ids = new int[n];
		//int maskedEntry = 0, maskedExit = 0;
		TreeSet<Integer> maskedEntry = new TreeSet<Integer>(), maskedExit = new TreeSet<Integer>();
		for(int i = 0; i<n; i++)
		{
			types[i] = input.next().charAt(0);
			ids[i] = input.nextInt();
			if(ids[i] == 0)
			{
				if(types[i] == 'E') maskedEntry.add(i);
				else maskedExit.add(i);
			}
			if(ids[i] != 0 && last[ids[i]] == types[i])
			{
				if(types[i] == 'E')
				{
					//use masked exit
					Integer prev = maskedExit.ceiling(lasti[ids[i]]);
					if(prev == null) good = false;
					else maskedExit.remove(prev);
				}
				else
				{
					Integer prev = maskedEntry.ceiling(lasti[ids[i]]);
					if(prev == null) good = false;
					else maskedEntry.remove(prev);
				}
			}
			last[ids[i]] = types[i];
			lasti[ids[i]] = i;
		}
		TidalFlow tf = new TidalFlow(n);
		for(int i = 0; i<n; i++)
		{
			if(types[i] == 'E') tf.add(tf.s, i, 1);
			else tf.add(i, tf.t, 1);
		}
		for(int i = 0; i<n; i++)
			for(int j = i+1; j<n; j++)
			{
				if(types[j] == 'E' && ids[i] == ids[j] && ids[i] != 0) break; // Found re-entry, must exit before that.
				if(types[i] == 'L' || types[j] == 'E') continue;
				if(ids[i] == ids[j] || ids[i] == 0 || ids[j] == 0) tf.add(i, j, 1);
				if(ids[i] == ids[j] && ids[i] != 0) break; //Found a definite exit for this person - must not exit later than this.
			}
		int flow = tf.getFlow();
		int totEnter = 0;
		for(int i = 0; i<n; i++) if(types[i] == 'E') totEnter++;
		if(good) System.out.println(totEnter - flow);
		else System.out.println("CRIME TIME");
	}
}
static class TidalFlow {
	ArrayDeque<Edge> stk = new ArrayDeque<Edge>();
	int N, s, t, oo = 987654321, fptr, bptr;
	ArrayList<Edge>[] adj;
	int[] q, dist, pool;

	@SuppressWarnings("unchecked")
	TidalFlow(int NN) {
		N=(t=(s=NN)+1)+1;
		adj = new ArrayList[N];
		for(int i = 0; i < N; adj[i++] = new ArrayList<Edge>());
		dist = new int[N];
		pool = new int[N];
		q = new int[N];
	}
	void add(int i, int j, int cap) {
		Edge fwd = new Edge(i, j, cap, 0);
		Edge rev = new Edge(j, i, 0, 0);
		adj[i].add(rev.rev=fwd);
		adj[j].add(fwd.rev=rev);
	}
	int augment() {
		Arrays.fill(dist, Integer.MAX_VALUE);
		pool[t] = dist[s] = fptr = bptr = 0;
		pool[q[bptr++] = s] = oo;
		while(bptr > fptr && q[fptr] != t)
			for(Edge e : adj[q[fptr++]]) {
				if(dist[e.i] < dist[e.j])
					pool[e.j] += e.carry = Math.min(e.cap - e.flow, pool[e.i]);
				if(dist[e.i] + 1 < dist[e.j] && e.cap > e.flow)
					dist[q[bptr++] = e.j] = dist[e.i] + 1;
			}
		if(pool[t] == 0) return 0;
		Arrays.fill(pool, fptr = bptr = 0);
		pool[q[bptr++] = t] = oo;
		while(bptr > fptr) 
			for(Edge e : adj[q[fptr++]]) {
				if(pool[e.i] == 0) break;
				int f = e.rev.carry = Math.min(pool[e.i], e.rev.carry);
				if(dist[e.i] > dist[e.j] && f != 0) {
					if(pool[e.j] == 0) q[bptr++] = e.j;
					pool[e.i] -= f;
					pool[e.j] += f;
					stk.push(e.rev);
				}
			}
		int res = pool[s];
		Arrays.fill(pool, 0);
		pool[s] = res;
		while(stk.size() > 0) {
			Edge e = stk.pop();
			int f = Math.min(e.carry, pool[e.i]);
			pool[e.i] -= f;
			pool[e.j] += f;
			e.flow += f;
			e.rev.flow -= f;
		}
		return res;
	}
	int getFlow() {
		int res = 0, f = 1;
		while(f != 0)
			res += f = augment();
		return res;
	}
	class Edge {
		int i, j, cap, flow, carry;
		Edge rev;
		Edge(int ii, int jj, int cc, int ff) {
			i=ii; j=jj; cap=cc; flow=ff;
		}
	}
}
}
