import java.util.Scanner;
import java.util.*;
class Main{
  
  static int[] h;
  static long mod = 1000000007;
  
  static class Node{
    List<Node> child;
    long w=0, h=0;
    long dp1=1, dp2=1;
    Node(long w, long h){this.w=w;this.h=h;}
  }
  
  static Node dfs(int l, int r, long base){
    if(r-l==0)return null;
    long minh = Integer.MAX_VALUE;
    for(int i=l;i<r;++i)minh = Math.min(minh, h[i]);
    int minl = l;
    int w = -1;
    List<Node> nodelist = new ArrayList<>();
    for(int i=l;i<=r;++i){
        if(i==r || h[i]==minh){
            ++w;
            if(minl!=i)nodelist.add(dfs(minl, i, minh));
            minl = i+1;
        }
    }
    Node node = new Node((long)w, minh - base);
    node.child = nodelist;
    return node;
  }
    
  
  static long pow(long a, long p, long mod){
    long res = 1;
    for(int i=0;i<64;++i){
      if(((p>>i)&1)==1)res=(res*a)%mod;
      a = (a*a)%mod;
    }
    return res;
  }
  
  static void culc(Node node){
    if(node.child.isEmpty()){
		node.dp1 = pow(2, node.h, mod) ;
        node.dp2 = (pow(2, node.w, mod)-2+mod)%mod;
    }else{
        long dp1 = 1;
        long dp2 = 1;
        for(Node c : node.child){
            culc(c);
			dp1 = (dp1*c.dp1)%mod;
			dp2 = (dp2 * (c.dp1*2+c.dp2)%mod)%mod;
		}
		dp2 = (dp2 - dp1*pow(2, node.child.size(), mod)%mod + mod)%mod;
        node.dp1 = (dp1 * pow(2, node.h, mod)%mod);
        node.dp2 = (dp1*((pow(2, node.w + node.child.size(), mod)-2+mod)%mod)%mod + dp2*(pow(2, node.w, mod)%mod))%mod;
    }
  }
  
  public static void main(String[] args){
    Scanner scan = new Scanner(System.in);
    int n = scan.nextInt();
    h = new int[n];
    for(int i=0;i<n;++i)h[i]=scan.nextInt();
	Node root = dfs(0, n, 0);
    culc(root);
    System.out.println((root.dp1+root.dp2)%mod);
  }
}