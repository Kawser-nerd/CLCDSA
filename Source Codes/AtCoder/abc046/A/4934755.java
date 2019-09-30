import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a=sc.nextInt();
        int b=sc.nextInt();
        int c=sc.nextInt();
        int ans=3;
        if(a==b)ans--;
        if(a==c)ans--;
        if(b==c)ans--;
        System.out.println(ans==0?1:ans);

    }
    
 
}