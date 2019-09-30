package CodeJam2015;

import java.util.Scanner;

public class C {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int cases = 1; cases <= T; cases++) {
			int L = sc.nextInt();
			long X = sc.nextLong();
			String s = sc.next();
			
			if (L == 1) {
				System.out.println("Case #" + cases + ": NO");
				continue;
			}
			
			int j = 0; //number of string s used
			int i = 0; //portion of string s used
			
			//match i
			int accum = 1;
			boolean matchedi = false;
			long time = System.currentTimeMillis();
			matchi:
			for (; j < X; j++) {
				for (i = 0; i < s.length(); i++) {
					accum = quartenion(accum, s.charAt(i));
					if (accum == 2) {
						matchedi = true;
						break matchi;
					}
				}
				if (System.currentTimeMillis() - time > 1000)
					break;
			}
			
			if (!matchedi) {
				System.out.println("Case #" + cases + ": NO");
				continue;
			}
			i++;
			
			//match j
			accum = 1;
			boolean matchedj = false;
			matchj:
			for (; j < X; j++) {
				for (; i < s.length(); i++) {
					accum = quartenion(accum, s.charAt(i));
					if (accum == 3) {
						matchedj = true;
						break matchj;
					}
				}
				i = 0;
			}
			
			if (!matchedj) {
				System.out.println("Case #" + cases + ": NO");
				continue;
			}
			i++;
			
			//match k
			accum = 1;
			boolean matchedk = false;
			matchk:
			for (; j < X; j++) {
				for (; i < s.length(); i++) {
					accum = quartenion(accum, s.charAt(i));
					if (accum == 4) {
						matchedk = true;
						break matchk;
					}
				}
				i = 0;
			}
			
			if (!matchedk) {
				System.out.println("Case #" + cases + ": NO");
				continue;
			}
			i++;
			
			accum = 1;
			for (; i < s.length(); i++) {
				accum = quartenion(accum, s.charAt(i));
			}
			j++;
			
			if (j == X) {
				if (accum == 1)
					System.out.println("Case #" + cases + ": YES");
				else
					System.out.println("Case #" + cases + ": NO");
				continue;
			}
			
			int accum2 = 1;
			for (i = 0; i < s.length(); i++) {
				accum2 = quartenion(accum2, s.charAt(i));
			}
			/*for (; j < X; j++) {
				accum = quartenion(accum, accum2);
				System.out.println("cum accum is " + accum);
			}*/
			if (accum2 == 1 || accum2 == -1)
				accum2 = ((X - j) % 2) == 0 ? 1 : accum2;
			else {
				switch ((int) ((X - j) % 4)) {
				case 0: accum2 = 1; break;
				case 1: /*accum2 = accum2;*/ break;
				case 2: accum2 = -1; break;
				case 3: accum2 = -accum2; break;
				}
			}
			accum = quartenion(accum, accum2);
			
			if (accum == 1)
				System.out.println("Case #" + cases + ": YES");
			else
				System.out.println("Case #" + cases + ": NO");
		}
		sc.close();
	}

	private static int quartenion(int accum, char charAt) {
		// 1 = 1, 2 = i, 3 = j, 4 = k, -X = -X
		int next = (charAt == 'i') ? 2 : ((charAt == 'j') ? 3 : 4);
		if (accum > 0) return q2(accum, next);
		else return -q2(-accum, next);
	}

	private static int q2(int accum, int next) {
		if (accum == 1) return next;
		if (next == 1) return accum;
		switch (accum) {
		case 2:
			switch (next) {
			case 2: return -1;
			case 3: return 4;
			case 4: return -3;
			}
		case 3:
			switch (next) {
			case 2: return -4;
			case 3: return -1;
			case 4: return 2;
			}
		case 4:
			switch (next) {
			case 2: return 3;
			case 3: return -2;
			case 4: return -1;
			}
		}
		return 0;
	}

	private static int quartenion(int accum, int accum2) {
		if (accum > 0) {
			if (accum2 > 0)
				return q2(accum, accum2);
			else
				return -q2(accum, -accum2);
		} else {
			if (accum2 > 0)
				return -q2(-accum, accum2);
			else
				return q2(-accum, -accum2);
		}
	}

}
/*
5
2 1
ik
3 1
ijk
3 1
kji
2 6
ji
1 10000
i
*/