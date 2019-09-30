import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class Round1C {

	public static void main(String[] args) throws Exception{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter("C.txt");
		int T = Integer.parseInt(in.readLine());
		for(int c=1;c<=T;c++){
			int n = Integer.parseInt(in.readLine());
			int[] next = new int[n+5];
			ArrayList<ArrayList<Integer>> prev = new ArrayList<ArrayList<Integer>>();
			for (int i = 0; i < next.length; i++) {
				prev.add(new ArrayList<Integer>());
			}
			String[] spl = in.readLine().split(" ");
			for (int i = 1; i <= n; i++) {
				int nei = Integer.parseInt(spl[i-1]);
				next[i] = nei;
				prev.get(nei).add(i);
			}
			ArrayList<Integer> twoCycles = new ArrayList<Integer>();
			int d = 1;
			for (int i = 1; i <= n; i++) {
				boolean[] vis = new boolean[n+5];
				vis[i] = true;
				boolean inC = true;
				int Next = i;
				int cnt = 1;
				while(true){
					Next = next[Next];
					if(Next == i){
						break;
					}
					if(vis[Next]){
						inC = false;
						break;
					}
					vis[Next] = true;
					cnt++;
				}
				if(inC){
					if(cnt>2)
						d = Math.max(d, cnt);
					else if(i < next[i]){
						twoCycles.add(i);
					}
				}
			}
			int tot = 0;
			for(int j=0;j<twoCycles.size();j++){
				Queue<Integer> q = new LinkedList<Integer>();
				int u = twoCycles.get(j); int v = next[u];
				int[] nums = new int[]{u,v};
				tot+=2;
				for(int i=0;i<nums.length;i++){
					int[] dist = new int[n+5];
					Arrays.fill(dist, Integer.MAX_VALUE);
					dist[nums[i]] = 0;
					dist[nums[1-i]]=0;
					q.add(nums[i]);
					while(!q.isEmpty()){
						int cur = q.remove();
						for(int nei: prev.get(cur)){
							if(dist[nei] == Integer.MAX_VALUE){
								dist[nei] = dist[cur]+1;
								q.add(nei);
							}
						}
					}
					int md = 0;
					for(int i2=0;i2<dist.length;i2++){
						if(dist[i2]<Integer.MAX_VALUE){
							md = Math.max(md, dist[i2]);
						}
					}
					tot+=md;
				}
			}
			d = Math.max(d, tot);
			pw.println("Case #"+c+": "+d);
		}
		pw.close();
	}

}
