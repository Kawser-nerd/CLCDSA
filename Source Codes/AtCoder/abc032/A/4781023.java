import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner s=new Scanner(System.in);
        int a=s.nextInt(),b=s.nextInt(),n=s.nextInt();
        for (int i=n;i>=n;i++)
            if (i%a==0&&i%b==0){
                System.out.println(i);
                System.exit(0);
            }
    }
}