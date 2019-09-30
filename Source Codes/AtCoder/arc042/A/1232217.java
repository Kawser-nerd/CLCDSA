import java.util.ArrayDeque;
import java.util.Scanner;

public class Main {
	static Scanner s = new Scanner(System.in);
	public static void main(String[] args) {
		int n=s.nextInt(),m=s.nextInt();
		ArrayDeque<Integer> deque=new ArrayDeque<>(m);
		boolean f[]=new boolean[n+1];
		for(int i=0;i<m;i++) {
			deque.addFirst(s.nextInt());
		}
		while (!deque.isEmpty()) {
			int p=deque.poll();
			if(!f[p]) {
				f[p]=true;
				System.out.println(p);
			}
		}
		for(int i=1;i<=n;i++) {
			if(!f[i]) {
				System.out.println(i);
			}
		}
	}
}