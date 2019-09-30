public class Main {
    public static void main(String[]$) {
        java.util.Scanner s=new java.util.Scanner(System.in);
        int a=s.nextInt(),b=s.nextInt(),c=s.nextInt(),d=s.nextInt(),t=s.nextInt(),v=s.nextInt(),p[]=new int[2];
        System.out.println(java.util.stream.IntStream.range(0,s.nextInt()).filter(i->Math.sqrt((a-(p[0]=s.nextInt()))*(a-p[0])+(b-(p[1]=s.nextInt()))*(b-p[1]))+Math.sqrt((c-p[0])*(c-p[0])+(d-p[1])*(d-p[1]))<=t*v).findAny().isPresent()?"YES":"NO");
    }
}