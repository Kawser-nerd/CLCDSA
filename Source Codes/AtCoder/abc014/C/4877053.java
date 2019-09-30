public class Main {
    public static void main(String[]$) {
        java.util.Scanner s = new java.util.Scanner(System.in);
        int n=s.nextInt(),a[]=new int[1000002],b=0;
        while(n-->0){
            a[s.nextInt()]++;
            a[s.nextInt() + 1]--;
        }
        java.util.Arrays.parallelPrefix(a,Integer::sum);
        for(int j:a)
            b=Math.max(b,j);
        System.out.println(b);
    }
}