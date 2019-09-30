import java.util.*;
import java.math.*;
class Main{
	public static void main(String [] argv){
		Scanner sc = new Scanner(System.in);
		int tests = sc.nextInt();
		for(int t = 1; t <= tests; t++){
			int n = sc.nextInt();
			double x = 0., y = 0, z = 0, dx = 0, dy = 0, dz = 0;
			for(int i = 0; i < n; i++){
				x += sc.nextDouble();
				y += sc.nextDouble();
				z += sc.nextDouble();
				dx += sc.nextDouble();
				dy += sc.nextDouble();
				dz += sc.nextDouble();
			}
			x /= n;
			y /= n;
			z /= n;
			dx /= n;
			dy /= n;
			dz /= n;
			double a = dx*dx + dy*dy + dz*dz;
			double b = 2 * (dx*x + dy*y+dz*z);
			double c = x*x + y*y + z*z;
			double s;
			if(a == 0 && b == 0){
				s = 0;
			}else if(a == 0 && b / c > 0){
				s = 0;
			}else if(a ==0){
				s = -c / b;
			}else if(b / a > 0){//smallest when t = 0
				s = 0;
			}else{//smallest when t = -b/2a
				s = -b / a / 2;
			}
			double v = a * s * s + b * s + c;
			if(v < 0){
				v = 0;
			}
			v = Math.sqrt(v);
			
			System.err.println(t);
			System.out.printf("Case #%d: %.08f %.08f\n", t, v,s);
		}
	}

}
