import java.io.*;
import java.util.*;

class MyComparator implements Comparator<Integer>{
	@Override
	public int compare(Integer x, Integer y){
		return x > y ? -1 : 1;
	}
}

class Main{
    public static void main(String[] args){
        solve();
    }

    public static void solve(){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[3*n];
        for(int i=0;i<3*n;i++){
        	a[i] = sc.nextInt();
        }
        long[] left = new long[n+1];
        long[] right = new long[n+1];
        Queue<Integer> que = new PriorityQueue<Integer>();
        long count = 0;
        for(int i=0;i<n;i++){
        	count += (long)a[i];
        	que.add(a[i]);
        }
        left[0] = count;
        for(int i=n;i<2*n;i++){
        	count += (long)a[i];
        	que.add(a[i]);
        	int x = que.poll();
        	count -= (long)x;
            left[i-n+1] = count;
        }

        count = 0;
        Queue<Integer> qu = new PriorityQueue<Integer>(new MyComparator());
        for(int i=3*n-1;i>=2*n;i--){
        	count += (long)a[i];
        	qu.add(a[i]);
        }
        right[n] = count;
        for(int i=2*n-1;i>=n;i--){
        	count += (long)a[i];
        	qu.add(a[i]);
        	int x = qu.poll();
        	count -= (long)x;
        	right[i-n] = count;
        }

        long ans = left[0] - right[0];
        for(int i=1;i<n+1;i++){
        	ans = (long)Math.max(ans, left[i] - right[i]);
        	//System.out.println(left[i] - right[i]);
        }

        System.out.println(ans);
    }
}