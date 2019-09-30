import java.util.*;

class Main {
    static final double EPS=1.0e-9;
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        double pi=Math.acos(-1);
        int n=scan.nextInt();
        int[] x=new int[n],y=new int[n];
        for(int i=0;i<n;++i){
            x[i]=Integer.parseInt(scan.next());
            y[i]=Integer.parseInt(scan.next());
        }
        long acute=0,right=0,obtuse=0;
        for(int i=0;i<n;++i){
            double[] thetas=new double[n-1];
            int p=0;
            for(int j=0;j<n;++j){
                if(i==j)continue;
                thetas[p++]=Math.atan2(y[i]-y[j],x[i]-x[j]);
            }
            Arrays.sort(thetas);
            double[] thetaDup=new double[2*n-2];
            System.arraycopy(thetas,0,thetaDup,0,n-1);
            System.arraycopy(thetas,0,thetaDup,n-1,n-1);
            for(int j=n-1;j<2*n-2;++j)thetaDup[j]+=2*pi;
            for(int j=0;j<n-1;++j){
                double t1=thetas[j]+pi/2-EPS;
                double t2=thetas[j]+pi/2+EPS;
                double t3=thetas[j]+pi-EPS;
                int i1=Arrays.binarySearch(thetaDup,j+1,j+n-1,t1);
                int i2=Arrays.binarySearch(thetaDup,j+1,j+n-1,t2);
                int i3=Arrays.binarySearch(thetaDup,j+1,j+n-1,t3);
                if(i1<0)i1=-i1-1;
                if(i2<0)i2=-i2-1;
                if(i3<0)i3=-i3-1;
                right+=i2-i1;
                obtuse+=i3-i2;
            }
        }
        long nn=n;
        acute=nn*(nn-1)*(nn-2)/6-right-obtuse;
        System.out.println(acute+" "+right+" "+obtuse);
    }
}