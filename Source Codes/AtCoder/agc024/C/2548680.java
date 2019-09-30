/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;

public class Main {
	public static void main (String[] args) {
	    Scanner sc = new Scanner(System.in);
	    int n = sc.nextInt();
	    int arr[] = new int[n];
	    for(int i=0;i<n;i++){
	        arr[i] = sc.nextInt();
	    }
	    if(arr[0]!=0){
	        System.out.println(-1);return;
	    }
	    for(int i=1;i<n;i++){
	        int dif = arr[i] - arr[i-1];
	        if(dif>1){
	            System.out.println(-1);return;
	        }
	    }
	    long ans = 0;
	    for(int i=n-1;i>=0;i--){
	        ans+=arr[i];
	        if(arr[i]>0){
	            while(i>0 && arr[i] - arr[i-1] == 1){
	                i--;
	            }
	        }
	    }
	    System.out.println(ans);return;
	}
}