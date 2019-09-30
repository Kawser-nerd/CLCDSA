import java.util.*;

public class Main {
	static Scanner in = new Scanner(System.in);
	static class Node {
		int x1, y1, x2, y2;
		boolean flag;
	}
	static Node node[];
	static int mx, my, l;
	static void dfs(int x) {
		node[x].flag = false;
		mx = Math.max(mx, node[x].x2);
		my = Math.max(my, node[x].y2);
		l = Math.min(l, node[x].x1+node[x].y1);
		for(int i=0; i!=node.length; ++i) {
			if(!node[i].flag) continue;
			int cnt = 0;
			if(node[i].x2<node[x].x1&&node[i].y2<node[x].y1) continue;
			if(node[x].x2<node[i].x1&&node[x].y2<node[i].y1) continue;
			if(node[i].x2+1<node[x].x1) continue;
			if(node[i].y2+1<node[x].y1) continue;
			if(node[i].x1>node[x].x2+1) continue;
			if(node[i].y1>node[x].y2+1) continue;
			dfs(i);
		}
	}
	public static void main(String[] args) {
		int t = in.nextInt();
		for(int ca=1; ca<=t; ++ca) {
			int n = in.nextInt();
			node = new Node[n];
			for(int i=0; i!=n; ++i) {
				node[i] = new Node();
				node[i].x1 = in.nextInt();
				node[i].y1 = in.nextInt();
				node[i].x2 = in.nextInt();
				node[i].y2 = in.nextInt();
				node[i].flag = true;
			}
			int ans = 0;
			for(int i=0; i!=n; ++i) {
				if(node[i].flag) {
					mx = 0;
					my = 0;
					l = Integer.MAX_VALUE;
					dfs(i);
					ans = Math.max(ans, mx+my-l);
				}
			}
			System.out.println("Case #"+ca+": "+(ans+1));
		}
	}
}
