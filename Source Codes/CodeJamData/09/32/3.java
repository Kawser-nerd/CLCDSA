import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.*;


public class B {
	static BigDecimal totalX = BigDecimal.ZERO;
	static BigDecimal totalY = BigDecimal.ZERO;
	static BigDecimal totalZ = BigDecimal.ZERO;
	static BigDecimal totalVX = BigDecimal.ZERO;
	static BigDecimal totalVY = BigDecimal.ZERO;
	static BigDecimal totalVZ = BigDecimal.ZERO;
	

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		s.useDelimiter("\\s+");
		
		int testCases = s.nextInt();
		
		for ( int t = 0 ; t < testCases ; t++ ) {
			int n = s.nextInt();
			
			totalX = BigDecimal.ZERO;
			totalY = BigDecimal.ZERO;
			totalZ = BigDecimal.ZERO;
			totalVX = BigDecimal.ZERO;
			totalVY = BigDecimal.ZERO;
			totalVZ = BigDecimal.ZERO;
			
			for ( int f = 0 ; f < n ; f++ ) {
				totalX = totalX.add(new BigDecimal(s.nextInt()));
				totalY = totalY.add(new BigDecimal(s.nextInt()));
				totalZ = totalZ.add(new BigDecimal(s.nextInt()));
				totalVX = totalVX.add(new BigDecimal(s.nextInt()));
				totalVY = totalVY.add(new BigDecimal(s.nextInt()));
				totalVZ = totalVZ.add(new BigDecimal(s.nextInt()));
			}
			BigDecimal numFlies = new BigDecimal(n);
			totalX = totalX.divide(numFlies, 50, RoundingMode.HALF_EVEN);
			totalY = totalY.divide(numFlies, 50, RoundingMode.HALF_EVEN);
			totalZ = totalZ.divide(numFlies, 50, RoundingMode.HALF_EVEN);
			totalVX = totalVX.divide(numFlies, 50, RoundingMode.HALF_EVEN);
			totalVY = totalVY.divide(numFlies, 50, RoundingMode.HALF_EVEN);
			totalVZ = totalVZ.divide(numFlies, 50, RoundingMode.HALF_EVEN);
			
			//vector 1 = VX/VY/VZ
			//vector 2 = -X/-Y/-Z
			//c1 = VX*-X + VY*-Y + VZ*-Z
			//c2 = VX*VX + VY*VY + VZ*VZ
			//b = c1/c2
			//(X+b*VX) (Y+b*VY) (Z + b * VZ)
			
			BigDecimal c1 = totalVX.multiply(totalX.negate()).add(totalVY.multiply(totalY.negate())).add(totalVZ.multiply(totalZ.negate()));
			BigDecimal c2 = totalVX.multiply(totalVX).add(totalVY.multiply(totalVY)).add(totalVZ.multiply(totalVZ));
			
			BigDecimal time;
			
			if ( c2.compareTo(BigDecimal.ZERO) == 0 ) {
				time = BigDecimal.ZERO;
			} else {
				time = c1.divide(c2, 50, RoundingMode.HALF_EVEN);
			}
			
			
			if ( time.compareTo(BigDecimal.ZERO) < 0 ) {
				time = BigDecimal.ZERO;
			}
			
			BigDecimal tX = totalX.add(time.multiply(totalVX));
			BigDecimal tY = totalY.add(time.multiply(totalVY));
			BigDecimal tZ = totalZ.add(time.multiply(totalVZ));
			
			double d = Math.sqrt(tX.multiply(tX).add(tY.multiply(tY)).add(tZ.multiply(tZ)).doubleValue());
			
			System.out.printf("Case #%d: %.8f %.8f\n", t+1, d, time);
		}
	}
	
	static BigDecimal distanceAtSq(BigDecimal time) {
		BigDecimal pX = totalX.add(totalVX.multiply(time));
		BigDecimal pY = totalY.add(totalVY.multiply(time));
		BigDecimal pZ = totalZ.add(totalVZ.multiply(time));
		return pX.multiply(pX).add(pY.multiply(pY)).add(pZ.multiply(pZ));
	}
}
