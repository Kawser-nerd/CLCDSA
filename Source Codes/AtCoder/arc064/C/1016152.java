import java.util.*;

public class Main {
	static class Path {
		int idx;
		double dd;
		public Path(int idx, double dd) {
			this.idx = idx;
			this.dd = dd;
		}
		
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		double xs = sc.nextDouble();
		double ys = sc.nextDouble();
		double xt = sc.nextDouble();
		double yt = sc.nextDouble();
		int N = sc.nextInt();

		int L = N+2;
		double[] x = new double[L];
		double[] y = new double[L];
		double[] r = new double[L];
		for(int i=0; i<N; i++) {
			x[i] = sc.nextDouble();
			y[i] = sc.nextDouble();
			r[i] = sc.nextDouble();
		}
		x[N] = xs;
		y[N] = ys;
		x[N+1] = xt;
		y[N+1] = yt;
		
		double[][] d = new double[L][L];
		for(int i=0; i<L; i++) {
			for(int j=0; j<L; j++) {
				d[i][j] = d[j][i] = Math.max(0, dis(x[i],y[i],x[j],y[j])-r[i]-r[j]);
			}
		}
		
		int s = N;
		int t = s+1;
		double[] minD = new double[L];
		Arrays.fill(minD, 1l<<40);
		
		PriorityQueue<Path> q = new PriorityQueue<Path>(new Comparator<Path>() {
			public int compare(Path p1, Path p2) {
				return Double.compare(p1.dd, p2.dd);
			}
		});
		
		q.add(new Path(s, 0));
		while(!q.isEmpty()) {
			Path cur = q.poll();
			if(cur.dd < minD[cur.idx]) {
				minD[cur.idx] = cur.dd;
				if(cur.idx==t)
					break;
				for(int i=0; i<L; i++)
					if(cur.dd + d[cur.idx][i] < minD[i])
						q.add(new Path(i, cur.dd + d[cur.idx][i]));
			}
		}
		
		System.out.println(minD[t]);
		sc.close();
	}
	
	static double dis(double x1, double y1, double x2, double y2) {
		return Math.sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	}
}