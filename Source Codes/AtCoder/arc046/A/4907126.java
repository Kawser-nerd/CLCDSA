public class Main {
    public static void main(String[]$) {
        int n=new java.util.Scanner(System.in).nextInt()-1;
        System.out.println((n%9+1)*(int)(10/9d*Math.pow(10,n/9)));
    }
}