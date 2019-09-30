import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();int count=n;
        for(int i=0;i<=n;i++){
            int t=i;
            int c=0;
            while(t>0){
                c+=t%6;
                t/=6;
            }
            t=n-i;
            while(t>0){
                c+=t%9;
                t/=9;
            }
            count=Math.min(count,c);
        }
        System.out.println(count);
    }
}