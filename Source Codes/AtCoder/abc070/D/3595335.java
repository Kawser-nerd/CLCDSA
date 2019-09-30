import java.util.HashMap;
import java.util.LinkedList;
import java.util.Scanner;

	class oneNodeList {
	
		  LinkedList<Integer> list = new LinkedList<Integer>();
		  HashMap<Integer,Long> map = new HashMap<Integer,Long>();
		  public void push(int a){
		    list.add(a);
		  }
		  public int poll(){
		    int a = list.poll();
		    return a;
		  }
		  public int peek(){
		    int a = list.peek();
		    return a;
		  }

		  //???true???
		  public boolean isEmpty(){
		    return list.isEmpty();
		  } 
		  
		  public void put(int a,long b){
			  map.put(a, b);
		}
		  public long get(int a){
			  return map.get(a);
		  }

}

public class Main{
	
	static long[] length;
	static oneNodeList[] rin;
	static int[]v;
	public static void main(String args[])throws Exception{
		
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] a = new int[N+1];
		int[] b = new int[N+1];
		long[] c = new long[N+1];
		for(int i=0;i<N-1;i++){
			a[i] = sc.nextInt();
			b[i] = sc.nextInt();
			c[i] = sc.nextLong();
		}
		int Q = sc.nextInt();
		int K = sc.nextInt();
		int[] x = new int[Q];
		int[] y = new int[Q];
		
		for(int i=0;i<Q;i++){
			x[i] = sc.nextInt();
			y[i] = sc.nextInt();
			
			
		}
		rin = new oneNodeList[N+1];
		for(int i=1;i<=N;i++){
			rin[i] = new oneNodeList();
		}
		
		v = new int[N+1];
		v[K] = 1;
		
		for(int i = 0; i < N-1; i++){
		      int haji1 = a[i];
		      int haji2 = b[i];
		      rin[haji1].push(haji2);
		      rin[haji1].put(haji2,c[i]);
		      rin[haji2].push(haji1);
		      rin[haji2].put(haji1,c[i]);
		    }
		
		length = new long[N+1];
		length[K] = 0;
		Search(K);
		
		for(int i=0;i<Q;i++){
			System.out.println(length[x[i]] + length[y[i]]);
		}
	}
	private static void Search(int i) {
		
		while(!rin[i].isEmpty()){
			int j = rin[i].poll();
			if(v[j]==0){
				v[j] = 1;
			length[j] = length[i] + rin[i].get(j);
			Search(j);
			
			
			}
		}
	}
	
}