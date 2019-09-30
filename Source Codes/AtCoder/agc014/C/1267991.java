/*http://agc014.contest.atcoder.jp/submissions/1266693*/
import java.util.ArrayDeque;
import java.util.Scanner;
import java.util.function.LongSupplier;
import java.util.stream.IntStream;
 
public class Main{
	static final Scanner s=new Scanner(System.in);
	static final long[] fal_rnd(long[] ar,LongSupplier sp){
		int l=-1,r=ar.length;
		while(l+1!=r)
			ar[Math.random()<0.5?++l:--r]=sp.getAsLong();
		return ar;
	}
	static final IntStream REPS(int v){
		return IntStream.range(0,v);
	};
	static int h,w,k;
	public static void main(String[] __){
		h=s.nextInt();
		w=s.nextInt();
		k=s.nextInt();
		char[][]f=new char[h][];
		int x=-1,y=-1;
		for(int i=0;i<h;i++) {
			String in=s.next();
			if(x==-1) {
				x=in.indexOf('S');
				y=i;
			}
			f[i]=in.toCharArray();
		}
		
		int u=y,d=y,r=x,l=x;
		
		int[]dx= {0,1,0,-1};
		int[]dy= {1,0,-1,0};
		
		
		ArrayDeque<Point> deque=new ArrayDeque<>();
		deque.add(new Point(y,x));
		for(int i=0;i<=k;i++) {
			for(int j=deque.size();j>0;j--) {
				Point poll=deque.poll();
				
				u=Math.min(u,poll.y);
				d=Math.max(d,poll.y);
				l=Math.min(l,poll.x);
				r=Math.max(r,poll.x);
				
				
				f[poll.y][poll.x]='#';
				for(int bufd=0;bufd<4;bufd++) {
					if(range(poll.y+dy[bufd],poll.x+dx[bufd])
							&&f[poll.y+dy[bufd]][poll.x+dx[bufd]]=='.') {
						deque.add(new Point(poll.y+dy[bufd],poll.x+dx[bufd]));
				f[poll.y+dy[bufd]][poll.x+dx[bufd]]='#';
					}
				}
			}
		}
		/*
		System.out.println(u);
		System.out.println(h-1-d);
		System.out.println(l);
		System.out.println(w-1-r);
		*/
		System.out.println((IntStream.of(u,h-1-d,l,w-1-r).min().getAsInt()+k-1)/k+1);
	}
	
	static final boolean range(int y,int x) {
		return 0<=y&&y<h&&0<=x&&x<w;
	}
	static class Point{
		int y,x;
		Point(int y,int x){
			this.y=y;
			this.x=x;
		}
	}
}