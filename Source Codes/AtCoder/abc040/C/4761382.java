public class Main {
    public static void main(String[]args) {
        java.util.Scanner s=new java.util.Scanner(System.in);
        int n=s.nextInt(),a[]=new int[n],d[]=new int[n];
        d[1]=Math.abs((a[0]=s.nextInt())-(a[1]=s.nextInt()));
        for(int i=2;i<n;i++)d[i]=Math.min(d[i-1]+Math.abs(a[i-1]-(a[i]=s.nextInt())),d[i-2]+Math.abs(a[i-2]-a[i]));
        System.out.println(d[n-1]);
    }
}