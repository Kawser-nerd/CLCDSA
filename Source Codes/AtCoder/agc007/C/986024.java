import java.util.*;
import java.math.*; 
public class Main {
	public static void main(String[] args) {
		MathContext mc = new MathContext(25, RoundingMode.HALF_DOWN);
		Scanner in=new Scanner(System.in);
        int n = in.nextInt();
        int a = in.nextInt();
        int x = in.nextInt();
        BigDecimal L= new BigDecimal(1); 
        BigDecimal ans= new BigDecimal(2*x);
        for(int i=2;i<=n;++i)
        {
        	BigDecimal t=new BigDecimal(i);
        	L=L.add(BigDecimal.ONE.divide(BigDecimal.valueOf(i),mc));
        	t=L.add(BigDecimal.valueOf(i));
        	t=t.multiply(BigDecimal.valueOf(x));
        	BigDecimal t2=ans.multiply(BigDecimal.valueOf(2)).divide(BigDecimal.valueOf(i),mc);
        	ans=ans.add(t).add(t2);
        }
        L=L.add(BigDecimal.ONE.divide(BigDecimal.valueOf(n+1),mc));
        L=L.subtract(BigDecimal.ONE);
        L=L.multiply(BigDecimal.valueOf(n+1)).multiply(BigDecimal.valueOf(2*a-3*x));
        L=L.divide(BigDecimal.valueOf(2),mc);
        ans=ans.add(L);
        System.out.print(ans);
	}
}