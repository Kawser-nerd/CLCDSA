
import java.io.*;
import java.util.*;

public class A implements Runnable {
	private static String fileName = A.class.getSimpleName().replaceFirst("_.*", "");
	private static String inputFileName = fileName + ".in";
	private static String outputFileName = fileName + ".out";
	private static Scanner in;
	private static PrintWriter out;
	
	static int[] a = new int[2048];
	
	private void solve() {
		Scanner sc = new Scanner(in.nextLine());
		int mask = 0;
		while (sc.hasNextInt()) {
			mask |= 1 << sc.nextInt();
		}
		int ans = Integer.MAX_VALUE;
		for (int m = 0; m < a.length; m++) {
			if ((m & mask) == mask) {
				ans = Math.min(ans, a[m]);
			}
		}
		out.println(ans);
	}

	public void precalc() {
		Map<Integer, Long> ans = new HashMap<Integer, Long>();
		for (long t = 2; ans.size() < 512; t++) {
			int mask = 0;
			for (int b = 2; b <= 10; b++) {
				long s1 = t;
				long s2 = t;
				while (true) {
					s1 = square(s1, b);
					s2 = square(s2, b);
					s2 = square(s2, b);
					if (s2 == 1)
						break;
					if (s2 == s1)
						break;
				}
				if (s2 == 1) {
					mask |= 1 << b;
				}
			}
			if (!ans.containsKey(mask)) {
				ans.put(mask, t);
				System.out.println(mask + " " + t);
			}
		}
	}

	private long square(long s, int b) {
		int v = 0;
		while (s > 0) {
			int d = (int) (s % b);
			s /= b;
			v += d * d;
		}
		return v;
	}

	public void run() {
		int tests = in.nextInt();
		in.nextLine();
		for (int t = 1; t <= tests; t++) {
			out.print("Case #" + t + ": ");
			solve();
		}
	}

	public static void main(String[] args) throws IOException, InterruptedException {
		Arrays.fill(a, Integer.MAX_VALUE);
		a[20]=2;
		a[540]=3;
		a[52]=5;
		a[84]=6;
		a[1204]=7;
		a[276]=8;
		a[1044]=10;
		a[1052]=13;
		a[28]=17;
		a[1076]=19;
		a[1084]=23;
		a[60]=25;
		a[828]=27;
		a[1108]=44;
		a[1268]=49;
		a[284]=77;
		a[1148]=79;
		a[572]=81;
		a[1596]=91;
		a[564]=95;
		a[1300]=97;
		a[692]=125;
		a[700]=143;
		a[1180]=167;
		a[156]=191;
		a[340]=216;
		a[1340]=219;
		a[116]=229;
		a[308]=309;
		a[148]=311;
		a[532]=385;
		a[1556]=397;
		a[180]=401;
		a[628]=415;
		a[1140]=469;
		a[124]=533;
		a[316]=545;
		a[788]=553;
		a[1364]=608;
		a[1308]=623;
		a[92]=695;
		a[604]=707;
		a[188]=713;
		a[1564]=739;
		a[436]=1001;
		a[1588]=1009;
		a[1620]=1033;
		a[596]=1135;
		a[1852]=1177;
		a[1116]=1277;
		a[1692]=1337;
		a[636]=1695;
		a[372]=1975;
		a[668]=2159;
		a[252]=2207;
		a[1332]=2455;
		a[724]=2753;
		a[212]=2807;
		a[820]=2893;
		a[1684]=3137;
		a[796]=3487;
		a[1404]=3879;
		a[380]=4137;
		a[1844]=4417;
		a[348]=4557;
		a[1652]=4577;
		a[220]=4859;
		a[884]=4977;
		a[1236]=5527;
		a[444]=5719;
		a[1660]=6073;
		a[404]=6211;
		a[1244]=6307;
		a[412]=6351;
		a[948]=6393;
		a[244]=7307;
		a[1276]=7895;
		a[1812]=7961;
		a[1172]=8787;
		a[660]=9721;
		a[1876]=9867;
		a[860]=10089;
		a[1212]=10309;
		a[1820]=12085;
		a[1628]=12399;
		a[892]=23117;
		a[916]=24855;
		a[1916]=28099;
		a[852]=29627;
		a[1716]=29913;
		a[1460]=34527;
		a[924]=35785;
		a[1372]=37079;
		a[764]=37131;
		a[1396]=40285;
		a[756]=43465;
		a[1428]=44265;
		a[476]=47089;
		a[1884]=47775;
		a[1948]=48041;
		a[500]=48769;
		a[1436]=51909;
		a[508]=58775;
		a[732]=68091;
		a[1748]=71735;
		a[1908]=108161;
		a[1724]=120149;
		a[1468]=120407;
		a[468]=120785;
		a[956]=128821;
		a[1940]=142901;
		a[1780]=218301;
		a[1524]=245035;
		a[1972]=246297;
		a[1492]=285357;
		a[1980]=346719;
		a[1020]=569669;
		a[1756]=613479;
		a[988]=662619;
		a[1500]=697563;
		a[980]=710761;
		a[1788]=711725;
		a[1012]=1026657;
		a[2004]=2662657;
		a[1532]=2688153;
		a[2012]=4817803;
		a[2044]=11814485;
		a[2036]=18937233;
		Locale.setDefault(Locale.US);
		if (args.length >= 2) {
			inputFileName = args[0];
			outputFileName = args[1];
		}
		in = new Scanner(new FileReader(inputFileName));
		out = new PrintWriter(outputFileName);
		Thread thread = new Thread(new A());
		thread.start();
		thread.join();
		in.close();
		out.close();
	}
}
