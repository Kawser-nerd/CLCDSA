import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 * https://abc038.contest.atcoder.jp/tasks/abc038_d
 */
public class Main {

	static Integer[] widArray;

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		Set<Integer> wid = new HashSet<>();
		int N = sc.nextInt();
		Box[] boxes = new Box[N];
		for(int i=0; i<N; i++){
			boxes[i] = new Box(Integer.parseInt(sc.next()), Integer.parseInt(sc.next()));
			wid.add(boxes[i].w);
		}
		sc.close();
		
		
		Arrays.sort(boxes, new Comparator<Box>(){
			public int compare(Box b1, Box b2) {
				return b1.w < b2.w ? -1 : 1;
			}
		});
		widArray = wid.toArray(new Integer[wid.size()]);
		Arrays.sort(widArray);
		Node root = createTree(0, widArray.length-1);
		
		Arrays.sort(boxes, new Comparator<Box>(){
			public int compare(Box b1, Box b2) {
				if(b1.h==b2.h){
					return b1.w > b2.w ? -1 : 1;
				}else{
					return b1.h < b2.h ? -1 : 1;
				}
			}
		});
		
		int[] dp = new int[N];
		dp[0] = 1;
		root = updateBinarySearchTree(root, new Node(boxes[0].w, dp[0]));
		for(int i=1; i<N; i++){
			Box box = boxes[i];
			Node node = findBinarySearchTree(root, box.w);
			dp[i] = node==null ? 1 : node.max+1;
			root = updateBinarySearchTree(root, new Node(box.w, dp[i]));
		}
		
		int ans = 0;
		for(int d:dp){
			ans = Math.max(ans, d);
		}
		System.out.println(ans);
		
	}
	
	static Node createTree(int l, int r) {
		if(l>r) return null;
		int mid = (l+r)/2;
		Node root = new Node(widArray[mid], 0);
		root.left = createTree(l,mid-1);
		root.right = createTree(mid+1, r);
		return root;
	}

	static class Box{
		int w;
		int h;
		Box(int w, int h){
			this.w = w;
			this.h = h;
		}
	}
	
	static class Node{
		int id;
		int key;
		int max;
		Node parent;
		Node left;
		Node right;
		Node(int key, int max){
			this.key = key;
			this.max = max;
		}
	}
	
	static Node findBinarySearchTree(Node root, int key){
		Node current = root;
		Node target = null;
		while(current!=null){
			if(current.key>=key){			
				current = current.left;
			}else if(current.key<key){
				if(target==null || current.max>target.max) target = current;
				current = current.right;
			}
		}
		return target;
	}
	
	static Node updateBinarySearchTree(Node root, Node node){
		if(root==null) return node;
		Node current = root;
		while(current!=null){
			if(current.key>=node.key){
				current.max = Math.max(current.max, node.max);
				if(current.key == node.key) return root;
				current = current.left;
			}else{
				current = current.right;
			}
		}
		return root;
	}
	
}