import java.math.BigInteger;
import java.util.Scanner;

class c
{
  class num
  {
    BigInteger a, b;
    public num( BigInteger ta, BigInteger tb )
    {
//       ta = ta.mod(BigInteger.valueOf(1000));
      BigInteger gcd = ta.gcd(tb);
      ta = ta.divide(gcd);
      tb = tb.divide(gcd);
      gcd = gcd.mod(BigInteger.valueOf(1000));
      ta = ta.multiply(gcd);
      tb = tb.multiply(gcd);
      a = ta.add(BigInteger.ZERO);
      b = tb.add(BigInteger.ZERO);
    }
    
    public num mul( num x )
    {
      // (a+b5)*(xa+xb5)=(a*xa+5*b*xb+(a*xb+b*xa)5)
      BigInteger ta = a.multiply(x.a).add(b.multiply(x.b).multiply(BigInteger.valueOf(5)));
      BigInteger tb = a.multiply(x.b).add(b.multiply(x.a));
      return new num(ta, tb);
    }
  }

  BigInteger sqrt( BigInteger a )
  {
    BigInteger mn = BigInteger.ZERO;
    BigInteger mx = a.add(BigInteger.ZERO);
    while (mn.compareTo(mx) < 0)
    {
      BigInteger av = mn.add(mx).add(BigInteger.ONE).divide(BigInteger.valueOf(2));
      BigInteger tmp = av.multiply(av);
      if (tmp.compareTo(a) <= 0)
        mn = av;
      else
        mx = av.subtract(BigInteger.ONE);
    }
    return mn;
  }

  void run()
  {
    Scanner input = new Scanner(System.in);
    int tn = input.nextInt();
    for (int test = 1; test <= tn; test++)
    {
      int n = input.nextInt();
      if (n > 500)
        n = 200 + n % 100;
      num res = new num(BigInteger.valueOf(1), BigInteger.valueOf(0));
      num a = new num(BigInteger.valueOf(3), BigInteger.valueOf(1));
      for (int nn = n; nn > 0; nn >>= 1)
      {
        if ((nn & 1) != 0)
          res = res.mul(a);
        a = a.mul(a);
//         System.err.println("  res = (" + res.a.toString().length() + "," + res.b.toString().length() + ")");
//         System.err.println("  a = (" + a.a.toString().length() + "," + a.b.toString().length() + ")");
//         System.err.println("  gcd = " + res.a.gcd(res.b));
      }
//       System.err.println("  " + res.a + " + " + res.b + "*sqrt(5)");
      BigInteger tmp = res.b.multiply(res.b).multiply(BigInteger.valueOf(5));
//       System.err.println("  tmp = " + tmp);
      tmp = sqrt(tmp);
//       System.err.println("  tmp = " + tmp);
      tmp = tmp.add(res.a);
//       System.err.println("  tmp = " + tmp);
      tmp = tmp.mod(BigInteger.valueOf(1000));
//       tmp = tmp.subtract(tmp.divide(BigInteger.valueOf(1000)).multiply());
      String ans = tmp.toString();
      while (ans.length() < 3)
        ans = "0" + ans;
      System.out.println("Case #" + test + ": " + ans);
    }
  }
  
  public static void main( String[] args )
  {
    new c().run();
  }
}
