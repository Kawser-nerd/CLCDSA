import java.util.*;
import java.lang.*;
import java.io.*;


public class Main {
    public static int maxOfArray(int[] a){
    	int ans = a[0];
    	for(int i=1;i<a.length;i++){
    		if(a[i]>ans) ans=a[i];
    	}
    	return ans;
    }
    public static int minOfArray(int[] a){
    	int ans = a[0];
    	for(int i=1;i<a.length;i++){
    		if(a[i]<ans) ans=a[i];
    	}
    	return ans;
    }
    public static int cost(int[] array, int target){
        int ans=0;
        for(int n=0;n<array.length;n++) ans += (array[n]-target)*(array[n]-target);
        return ans;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] a = new int[N];
        for(int n=0;n<N;n++) a[n]=sc.nextInt();
        
        int min = minOfArray(a);
        int max = maxOfArray(a);
        int ans = Integer.MAX_VALUE;
        for(int target=min;target<=max;target++){
        	ans = Math.min(ans, cost(a,target));
        }
        System.out.println(ans);
    }
}