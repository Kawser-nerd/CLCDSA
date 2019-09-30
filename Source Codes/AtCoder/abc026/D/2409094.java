import java.util.Scanner;

public class Main {
    
    private static double eps=1e-9;
    
    private static double f(int a,int b,int c,double x){
        return a*x+b*Math.sin(c*x*Math.PI);
    }
    
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int a=Integer.parseInt(sc.next());
        int b=Integer.parseInt(sc.next());
        int c=Integer.parseInt(sc.next());
        // ????
        double left=0.0,right=1000.0;
        for(int i=0;i<100;i++){
            double mid=(left+right)/2;
            if(f(a,b,c,mid)-100>eps){
                right=mid;
            }
            else{
                left=mid;
            }
        }
        System.out.println(left);
    }
}