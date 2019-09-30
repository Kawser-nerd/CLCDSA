import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        String ans = "Positive";
        if(a<=0&&b>=0) ans = "Zero";
        if(b<0&&(b-a+1)%2==1) ans = "Negative";
        System.out.println(ans);
    }
}