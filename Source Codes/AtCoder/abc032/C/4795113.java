public class Main {
    public static void main(String[]$) {
        java.util.Scanner c=new java.util.Scanner(System.in);
        int n=c.nextInt(),k=c.nextInt(),r=0,i=0,l=0;
        long s[]=new long[n],a=0,t=1;
        while(i<n)if((s[i++]=c.nextInt())==0){System.out.println(n);return;}
        for(;l<n;l++){
            while (r<n&&t*s[r]<=k){t*=s[r];a=Math.max(a,r++-l+1);}
            if(r==l)r++;else t/=s[l];
        }
        System.out.println(a);
    }
}