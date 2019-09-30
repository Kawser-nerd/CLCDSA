// uses http://introcs.cs.princeton.edu/java/stdlib/StdIn.java
public class Elf {
    long gcd(long x, long y) {
        if (x==0 || y==0) return x+y;
        return gcd(y, x%y);
    }
    
    int t = StdIn.readInt();
    
    {
        for (int i=0; i<t; i++) {
            String[] toks = StdIn.readString().split("/");
            long p = Long.parseLong(toks[0]);
            long q = Long.parseLong(toks[1]);
            System.out.print("Case #"+(i+1)+": ");
            long g = gcd(p, q);
            p /= g;
            q /= g;
            if (Long.bitCount(q) != 1) {
                System.out.println("impossible");
                continue;
            }
            int result = 0;
            while (p < q) {
                result ++;
                p *= 2;
            }
            System.out.println(result);
        }
    }
    
    public static void main(String[] args) {
        new Elf();
    }
}