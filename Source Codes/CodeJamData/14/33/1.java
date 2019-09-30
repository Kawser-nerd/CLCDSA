// uses http://introcs.cs.princeton.edu/java/stdlib/StdIn.java
public class Enclosure {
    static int opt(int n, int m, int k) {
        if (k==1 || m==1 || n==1) return k;
        int res = m*n+1;
        //String best = "";
        for (int a=0; a<m && a<n; a++)
            for (int e=0; a+e<m; e++)
            for (int b=0; a+e+b<m && b<n; b++)
            for (int g=0; b+g<n; g++)
            for (int c=0; b+g+c<n && c<=a+e+b; c++)
            for (int d=0; c+d <= a+e+b && a+d<=b+g+c; d++) {
            int f = a+e+b-c-d;
            int h = b+g+c-a-d;
            int K = (a+e+b+1)*(b+g+c+1);
            K -= a*(a+1)/2;
            K -= b*(b+1)/2;
            K -= c*(c+1)/2;
            K -= d*(d+1)/2;
            if (K >= k && a+b+c+d+e+f+g+h < res) {
                res = a+b+c+d+e+f+g+h;
                //best = a+" "+e+" "+b+" "+g+" "+c+" "+f+" "+d+" "+h+","+Math.abs(a-c)+" "+Math.abs(b-d);
            }
        }
        //String check = best.substring(best.length()-3);
        //if (check.charAt(0) > '1' || check.charAt(2) > '1') {
        //System.out.println(n+" "+m+" "+k+": "+res);
        //System.out.println(best);        
        //}
        return res;
    }
    public static void main(String[] args) {
        int cases = StdIn.readInt();
        for (int i=0; i<cases; i++) {
            System.out.print("Case #" + (i+1) +": ");
            int n = StdIn.readInt();
            int m = StdIn.readInt();
            int k = StdIn.readInt();
            System.out.println(opt(n, m, k));
        }
    }
    public static void main1(String[] args) {
        for (int m=1; m<=6; m++)
            for (int n=m+1; n<=6; n++)
            for (int k=2; k<=n*m; k++)
            opt(n, m, k);
    }
}