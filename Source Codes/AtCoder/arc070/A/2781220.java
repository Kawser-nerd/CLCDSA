import java.io.*;
import java.util.*;

class Main{
    public static void main(String[] args){
        solve();
    }

    public static void solve(){
        Scanner sc = new Scanner(System.in);
     	int x = sc.nextInt();
     	int count = 1;
     	int sum = 0;
     	while(true){
     		sum += count;
     		if(sum>=x){
     			break;
     		}
     		count++;
     	}   
     	System.out.println(count);
    }
}