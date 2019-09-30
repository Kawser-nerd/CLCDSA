import java.io.*;
import java.util.*;

class Main{
    public static void main(String[] args){
        solve();
    }

    public static void solve(){
        Scanner sc = new Scanner(System.in);
     	int n = sc.nextInt();
     	String s = sc.next();
     	int counter = 0;
     	int ans = n;
     	for(int i=1;i<s.length();i++){
     		if(s.charAt(i)=='E'){
     			counter++;
     		}
     	} 
     	int count = 0;
     	ans = counter;
     	for(int i=1;i<s.length();i++){
     		if(s.charAt(i-1)=='W'){
     			count++;
     		}
     		if(s.charAt(i)=='E'){
     			counter--;
     		}
     		ans = Math.min(ans, count+counter);
     	}

     	System.out.println(ans);
    }
}