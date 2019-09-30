import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] a = new int[N];
        for(int n=0;n<N;n++) a[n]=sc.nextInt();
        
        int[] divBy2 = new int[3];
        for(int n=0;n<N;n++){
        	if(a[n]%4==0) divBy2[2]++;
        	else if(a[n]%2==0) divBy2[1]++;
        	else divBy2[0]++;
        }
        boolean ans = true;
        if(divBy2[0]>divBy2[2]+1) ans=false;
        if(divBy2[0]==divBy2[2]+1 && divBy2[1]>0) ans=false;
        System.out.println(ans ? "Yes" : "No");
    }
}