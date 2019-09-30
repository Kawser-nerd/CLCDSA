import java.util.*;
public class Main{
	public static void main(String[] args) {
		D();
	}
	
	public static void A() {
		Scanner sc = new Scanner(System.in);
		Integer n = sc.nextInt();
		sc.close();
		String num = n.toString();
		if(num.charAt(1) != num.charAt(2)) {
			System.out.println("No");
			return;
		}
		char mid = num.charAt(1);
		if(mid == num.charAt(0) || mid == num.charAt(3)) {
			System.out.println("Yes");
		}
		else System.out.println("No");
	}
	
	public static void B() {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		if(N==1) {
			System.out.println(1);
			return;
		}
		sc.close();
		long Li = 2;
		long Lj = 1;
		long temp;
		for(int i=2;i<N+1;i++) {
			temp = Lj;
			Lj = Li+Lj;
			Li = temp;
		}
		System.out.println(Lj);
	}
	
	// ??????????????????????????null
	// 1 + 2 - 3 =  ->  1 + 2 | -3 ..?????????
	public static void C() {
		Scanner sc = new Scanner(System.in);
		String num = sc.next();
		int[] nums = new int[4];
		for(int i=0;i<4;i++) {
			nums[i] = Character.getNumericValue(num.charAt(i)); 
		}
		ArrayList<Character> lis = calc(nums,7);
		System.out.print(nums[0]);
		for(int i=0;i<3;i++) {
			System.out.print(lis.get(i)+ "" +nums[i+1]);
		}
		System.out.println("=7");
	}
	public static ArrayList<Character> calc(int[] nums, int right) {
		return calc(nums,nums.length-1,right,new ArrayList<Character>());
	}
	public static ArrayList<Character> calc(int[] nums, int idx, int right, ArrayList<Character> lis) {
		if(idx == 0) {
			if(nums[0] == right) return lis;
			else return null;
		}
		ArrayList<Character> cand1 = calc(nums,idx-1,right+nums[idx],lis);
		if(cand1 != null) {
			cand1.add('-');
			return cand1;
		}
		ArrayList<Character> cand2 = calc(nums,idx-1,right-nums[idx],lis);
		if(cand2 != null) {
			cand2.add('+');
			return cand2;
		}
		return null;
	}
	
	//?????que?BFS
	public static void D() {
		Scanner sc = new Scanner(System.in);
		int H = sc.nextInt();
		int W = sc.nextInt();
		Node[] nodes = new Node[10];
		for(int i=0;i<10;i++) {
			int[] adjcost = new int[10];
			for(int j=0;j<10;j++) {
				adjcost[j] = sc.nextInt();
			}
			nodes[i] = new Node(i,adjcost);
		}
		int[] costs = new int[10];
		for(int i=0;i<10;i++) {
			costs[i] = dks(nodes[i],nodes[1],nodes);
		}
		int ret = 0;
		for(int i=0;i<H*W;i++) {
			int a = sc.nextInt();
			if (a==-1) continue;
			ret += costs[a];
		}
		System.out.println(ret);
	}
	
	public static class Node{
		public int data;
		public int cost;
		public int[] adjcost;
		public Node adj; //???????????????
		public Node(int data, int[] adjcost) {
			this.data = data;
			this.adjcost = adjcost;
		}
	}
	public static int dks(Node start, Node goal, Node[] lis) {
		for(Node n: lis) {
			n.cost = Integer.MAX_VALUE;
		}
		start.cost = 0;
		HashSet<Node> done = new HashSet<Node>();
		Node n = start;
		while(n!=goal) {
			n = updatecost(n,lis,done);
		}
		return n.cost;
	}
	// now ???????????done???????????cost????? now.cost+weight???????????
	public static Node updatecost(Node now, Node[] lis, HashSet<Node> done) {
		done.add(now);
		int mincost = Integer.MAX_VALUE;
		Node minNode = null;
		for(Node n : lis) {
			if(done.contains(n)) continue;
			n.cost = Math.min(n.cost, now.cost+now.adjcost[n.data]);
			if(n.cost < mincost) {
				mincost = n.cost;
				minNode = n;
			}
		}
		return minNode;
	}
}