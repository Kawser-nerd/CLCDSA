import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        double a=scan.nextDouble();
        double b=scan.nextDouble();
        if(b<a){
            double t=a;
            a=b;
            b=t;
        }
        double center=(a+b)/Math.sqrt(2);
        double ridge=Math.atan(a/b);
        int n=scan.nextInt();
        for(int i=0;i<n;++i){
            double c=scan.nextDouble();
            double d=scan.nextDouble();
            if(d<c){
                double t=c;
                c=d;
                d=t;
            }
            if(center<c){
                System.out.println("YES");
                continue;
            }
            if(c<a){
                System.out.println("NO");
                continue;
            }
            double p=Math.PI/4.0;
            double f=0.0;
            for(int j=0;j<50;++j){
                double x=(p+f)/2;
                if(a*Math.cos(x)+b*Math.sin(x)>=c)
                    p=x;
                else
                    f=x;
            }
            System.out.println(Math.min(b,a*Math.sin(p)+b*Math.cos(p))<=d?
                               "YES":"NO");
        }
    }
}