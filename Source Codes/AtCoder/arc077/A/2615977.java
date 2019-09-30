import java.io.*;
import java.util.*;

class Main{
    public static void main(String[] args){
        solve();
    }

    public static void solve(){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for(int i=0;i<n;i++){
        	a[i] = sc.nextInt();
        }
      	Deque<Integer> b = new ArrayDeque<Integer>();
      	boolean flag = true;

      	for(int i=0;i<n;i++){
      		if(flag){
      			b.addLast(a[i]);
      		}
      		else{
      			b.addFirst(a[i]);
      		}
      		flag = !flag;
      	}

      	if(flag){
      		for(int i=0;i<n;i++){
      			if(i!=n-1){
      				System.out.print(b.pollFirst()+" ");
      			}
      			else{
      				System.out.println(b.pollFirst());
      			}
      		}
      	}
      	else{
      		for(int i=0;i<n;i++){
      			if(i!=n-1){
      				System.out.print(b.pollLast()+" ");
      			}
      			else{
      				System.out.println(b.pollLast());
      			}
      		}
      	}
    }
}