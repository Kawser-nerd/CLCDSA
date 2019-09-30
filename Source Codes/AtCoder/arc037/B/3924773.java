import java.util.*;
import java.awt.Point;
class Main {
    static ArrayList<Integer> alist;
    static Point[] p;
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int N = sc.nextInt();
	int M = sc.nextInt();
	alist = new ArrayList<Integer>();
	p = new Point[M];
	for(int i = 0; i < N; i++) {
	    alist.add(i+1);
	}
	for(int i = 0; i < M; i++) {
	    p[i] = new Point(sc.nextInt(), sc.nextInt());
	}
	int cnt = 0;
	while(alist.size() != 0) {
	    boolean isTrue = searchTree(alist.get(0));
	    if(isTrue) cnt++;
	}
	System.out.println(cnt);
    }
    public static int nextLeaf(int n) {
	for(int i = 0; i < p.length; i++) {
	    if(p[i].getX() == n){
		int num = (int)(p[i].getY());
		p[i].move(-1,-1);
		return num;
	    }
	    else if(p[i].getY() == n) {
		int num = (int)(p[i].getX());
		p[i].move(-1,-1);
		return num;
	    }
	}
	return -1;
    }
    public static boolean searchTree(int i) {
	if(alist.contains((Integer)(i))) {
	    alist.remove((Integer)(i));
	}else {
	    return false;
	}
	int nextLeaf;
	boolean isTree = true;
	while((nextLeaf = nextLeaf(i)) > 0) {
	    boolean isNext = searchTree(nextLeaf);
	    isTree = isTree && isNext;
	}
	return isTree;
    }
}