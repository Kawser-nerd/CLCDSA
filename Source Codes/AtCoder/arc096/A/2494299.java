import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner n=new Scanner(System.in);
        int a=n.nextInt();
        int b=n.nextInt();
        int c=n.nextInt()*2;
        int x=n.nextInt();
        int y=n.nextInt();
        int sum=0;

        if(a+b>c) {
            if (x > y) {
                sum += c * y;
                if (a < c) {
                    sum += a * (x - y);
                } else {
                    sum += c * (x - y);
                }
            } else {
                sum += c * x;
                if (b < c) {
                    sum += b * (y - x);
                } else {
                    sum += c * (y - x);
                }
            }
        }else{
            sum+=a*x+b*y;
        }
        System.out.println(sum);
    }
}