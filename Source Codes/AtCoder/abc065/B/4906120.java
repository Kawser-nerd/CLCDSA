import java.util.*;
public class Main{
    public static void main(String[]args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        int cnt = 0;
        int s = 1;
        for(int i=0; i<n; i++){
            a[i] = sc.nextInt();
        }
        
        for(int i=0; i<a.length; i++){
            s = a[s-1];
            cnt++;
            if(s == 2){
                System.out.println(cnt);
                return;
            }
        }
        System.out.println("-1");
    }
}