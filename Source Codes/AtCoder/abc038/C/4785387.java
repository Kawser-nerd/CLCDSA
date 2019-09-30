public class Main {
    private static java.util.Scanner s=new java.util.Scanner(System.in);
    static long l=0,n=s.nextInt(),b=s.nextInt();
    public static void main(String[]args){
        System.out.println(java.util.stream.LongStream.range(1,n).reduce(n,(a,i)->a+((b<(b=s.nextInt()))?i-l:(l=i)*0)));
    }
}