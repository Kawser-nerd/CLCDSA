public class Main {
    public static void main(String[] args) {
        java.util.Scanner s = new java.util.Scanner(System.in);
        int n = s.nextInt(), k = s.nextInt();
        System.out.println(java.util.stream.LongStream.range(0,n).map(i->s.nextInt()*Math.min(Math.min(Math.min(i+1,n-i),k),n-k+1)).sum());
    }
}