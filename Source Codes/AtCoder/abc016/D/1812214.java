import java.util.*;

class Main {
    static final double E=1.0e-9;
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        double ax=scan.nextDouble();
        double ay=scan.nextDouble();
        double dx=scan.nextDouble()-ax;
        double dy=scan.nextDouble()-ay;
        int n=scan.nextInt();
        double[]x=new double[n],y=new double[n];
        for(int i=0;i<n;++i){
            double u=scan.nextDouble()-ax;
            double v=scan.nextDouble()-ay;
            x[i]=(dx*u+dy*v)/(dx*dx+dy*dy);
            y[i]=(-dy*u+dx*v)/(dx*dx+dy*dy);
        }
        int k=0;
        for(int i=0;i<n;++i){
            if(y[i]*y[(i+1)%n]>=0)continue;
            double z=x[i]*y[(i+1)%n]-x[(i+1)%n]*y[i];
            z/=-y[i]+y[(i+1)%n];
            if(z>E&&z<1-E)k++;
        }
        System.out.println(k/2+1);
    }
}