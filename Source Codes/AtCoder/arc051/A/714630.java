import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
	static BufferedReader br;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		String[] cir = br.readLine().split(" ");
		String[] reg = br.readLine().split(" ");
		int[] Cir = new int[3];
		int[] Reg = new int[4];
		for (int i = 0; i < 3; i++) {
			Cir[i] = Integer.parseInt(cir[i]);
			Reg[i] = Integer.parseInt(reg[i]);
		}
		Reg[3] = Integer.parseInt(reg[3]);
		String a = (regionReg(Reg, Cir[0], Cir[1] + Cir[2])
				|| regionReg(Reg, Cir[0], Cir[1] - Cir[2])
				|| regionReg(Reg, Cir[0] + Cir[2], Cir[1])
				|| regionReg(Reg, Cir[0] - Cir[2], Cir[1])) ? "YES" : "NO";
		boolean[] c = new boolean[4];
		int k = 0;
		for (int i = 0; i < 3; i += 2)
			for (int j = 1; j < 4; j += 2) {
				c[k] = regionCir(Cir, Reg[i], Reg[j]);
				k++;
			}
		String b = (c[0] || c[1] || c[2] || c[3]) ? "YES" : "NO";
		System.out.println(a);
		System.out.println(b);
	}

	private static boolean regionReg(int[] Reg, int x, int y) {
		if (Reg[0] <= x && Reg[1] <= y && x <= Reg[2] && y <= Reg[3])
			return false;
		return true;
	}

	private static boolean regionCir(int[] Cir, int x, int y) {
		if (((Cir[0] - x) * (Cir[0] - x) + (Cir[1] - y) * (Cir[1] - y)) > Cir[2]
				* Cir[2])
			return true;
		return false;
	}
}