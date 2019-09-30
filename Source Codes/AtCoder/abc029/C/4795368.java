public class Main {
    public static void main(String[]$) {
        f(new java.util.Scanner(System.in).nextInt(),"");
    }

    static void f(int n,String s){
        if(n==0)System.out.println(s);else for(char c=97;c<=99;c++)f(n-1,s+c);
    }
}