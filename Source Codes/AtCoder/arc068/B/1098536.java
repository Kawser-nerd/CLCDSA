import java.util.*;
     
    public class Main {
    	public static void main(String[] args) {
    		Scanner sc = new Scanner(System.in);
    		int n = sc.nextInt();
    		int[] a = new int[n];
    		for(int i = 0; i < n; i++)
    			a[i] = sc.nextInt();
    		int min = a[0];
    		int max = a[0];
    		for(int i = 1; i < n; i++) {
    			if(a[i] < min)
    				min = a[i];
    			else if(a[i] > max)
    				max = a[i];
    		}
    		boolean[] hash = new boolean[max - min + 1];
    		for(int i = 0; i < hash.length; i++)
    			hash[i] = false;
    		int identity = 0;
    		for(int i = 0; i < n; i++) {
    			if(!hash[a[i] - min]) {
    				identity++;
    				hash[a[i] - min] = true;
    			}
    		}
    		System.out.println(String.valueOf(identity - ((identity + 1)%2)));
    	}
    }