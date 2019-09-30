import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
	Main m = new Main();
	m.answer();
    }

    private Scanner scan = new Scanner(System.in);
    private final int N;
    private final Box[] boxes;
    private final int[] dp;

    public Main() {
	N = Integer.parseInt(scan.next());
	boxes = new Box[N];
	for (int i = 0; i < N; i++) {
	    int w = Integer.parseInt(scan.next());
	    int h = Integer.parseInt(scan.next());
	    boxes[i] = new Box(w, h);
	}
	Arrays.sort(boxes);
	
	dp = new int[N];

	scan.close();
    }

    public final void answer() {
	BinaryIndexedTree bit = new BinaryIndexedTree(100001);
	
	for (int i = 0; i < N; i++) {
	    dp[i] = bit.query(boxes[i].w-1) + 1;
	    bit.update(boxes[i].w, dp[i]);
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
	    if(dp[i] > ans) ans = dp[i];
	}

	System.out.println(ans);
    }

    private static class BinaryIndexedTree {
	private final int[] bit;
	private final int n;

	public BinaryIndexedTree(int n) {
	    bit = new int[n];
	    this.n = n;
	}

	public final void update(int i, int a) {

	    for (int x = i; x <= n; x += x & -x) {
		set(x, Integer.max(get(x), a));
	    }
	}

	public final int query(int i) {
	    int max = 0;
	    for (int x = i; x > 0; x -= x & -x) {
		int tmp = get(x);
		if(tmp > max) max = tmp;
	    }
	    
	    return max;
	}

	private void set(int x, int value) {
	    bit[x-1] = value;
	}

	private int get(int x) {
	    return bit[x-1];
	}
    }

    private static class Box implements Comparable<Box> {
	final int w;
	final int h;

	public Box(int w, int h) {
	    this.w = w;
	    this.h = h;
	}

	@Override
	public int compareTo(Box o) {
	    if(this.h == o.h) return -(this.w - o.w);
	    else return this.h - o.h;
	}
    }
}