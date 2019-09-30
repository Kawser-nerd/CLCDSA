import java.math.BigDecimal;
import java.math.MathContext;
import java.math.RoundingMode;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	private static Scanner sc;
	private static long start;
	
	public static void main(String[] args) {
		sc = new Scanner(System.in);
		int t = sc.nextInt();
		sc.nextLine();
		for (int i = 0; i < t; i++) {
			start = System.currentTimeMillis();
			System.out.printf("Case #%d: %s\n", i + 1, exec());
			long end = System.currentTimeMillis();
//			System.err.printf("Time taken: %.2f\n", .001 * (end - start));
		}
	}
	
	private static final MathContext ROUND_CONTEXT = new MathContext(8, RoundingMode.HALF_EVEN);
	
	public static String exec() {
		int a = sc.nextInt();
		int b = sc.nextInt();
		BigDecimal[] bd = new BigDecimal[a];
		for (int i = 0; i < a; i++) bd[i] = new BigDecimal(sc.next());
//		for (int i = 0; i < a; i++) bd[i] = BigDecimal.valueOf(0.5);
		
		BigDecimal[] rs = new BigDecimal[a + 2];
		rs[0] = new BigDecimal(b + 2); //hit enter and retype
		int backspacesNeeded = a;
//		BigDecimal runningChance = BigDecimal.ONE;
		double runningChance = 1.0;
		for (int i = 0; i < a; i++) {
			int charsNeededOnSuccess = backspacesNeeded + b - i + 1;
			int charsNeededOnFail = charsNeededOnSuccess + b + 1;
//			BigDecimal onSuccess = new BigDecimal(charsNeededOnSuccess).multiply(runningChance);
//			BigDecimal onFail = new BigDecimal(charsNeededOnFail).multiply(BigDecimal.ONE.subtract(runningChance));
//			rs[i + 1] = onSuccess.add(onFail);
			double onSuccess = runningChance * charsNeededOnSuccess;
			double onFail = (1.0 - runningChance) * charsNeededOnFail;
			rs[i + 1] = new BigDecimal(onSuccess + onFail);
//			runningChance = runningChance.multiply(bd[i]);
//			runningChance.round(ROUND_CONTEXT);
			runningChance *= bd[i].doubleValue();
			backspacesNeeded--;
//			if ( i % 100 == 0) System.err.printf("** R%7d: %.06f -- %.04f\n", i, rs[i + 1], .001 * (System.currentTimeMillis() - start));
		}
//		rs[a + 1] = new BigDecimal(b - a + 1).multiply(runningChance).add(new BigDecimal(b - a + 1 + b + 1).multiply(BigDecimal.ONE.subtract(runningChance)));
		rs[a + 1] = new BigDecimal((runningChance * (b - a + 1)) + ((1.0 - runningChance) * (b - a + 1 + b + 1)));
		Arrays.sort(rs);
		BigDecimal result = rs[0];
		return String.format("%.06f", result);
	}
}
