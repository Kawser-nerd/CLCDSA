import java.util.*;
import java.util.function.*;

class Main{
	static Scanner s=new Scanner(System.in);

	public static void main(String[]$){
		double p=s.nextDouble();
		DoubleUnaryOperator f=i->i+p/Math.pow(2,i/1.5);
		System.out.println(f.applyAsDouble(goldenSelectionSearch(0,p,1e-9,f)));
	}
	private static double goldenSelectionSearch(double l,double r,double off,DoubleUnaryOperator f){
		final double g=(1+Math.sqrt(5))/2;
		double a=(l*g+r)/(1+g),fa=f.applyAsDouble(a);
		double b=(l+r*g)/(1+g),fb=f.applyAsDouble(b);
		while(l+off<r){
			if(fa<=fb) {
				r=b;
				b=a;
				fb=fa;
				a=(l*g+r)/(1+g);
				fa=f.applyAsDouble(a);
			}else {
				l=a;
				a=b;
				fa=fb;
				b=(l+r*g)/(1+g);
				fb=f.applyAsDouble(b);
			}
		}
		return (a+b)/2;
	}
}