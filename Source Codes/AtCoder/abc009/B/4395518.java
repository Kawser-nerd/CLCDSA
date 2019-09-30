import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
        int i,x,n = sc.nextInt(),m1=1,m2=0;
        for(i=0;i<n;i++){
            x = sc.nextInt();
            if(m1<x){
                m2 = m1;
                m1 = x;
            }
            if(m2<x && m1!=x)
                m2 = x;
        }
        System.out.println(m2);
    }
}