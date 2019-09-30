import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

// Google Codejam
// Qualification Round 2013
// Problem D. Treasure

public class Main {

	private static int n;
	private static int[] chestOpenBy;
	private static int[][] keysInChest;
	private static boolean[] visited;
	private static int[] sol;
	private static int m;
	private static int[] startingKeys;

	private static int[] countKeys(int chests) {
		int[] keys = new int[201];
		for (int j = 1; j <= startingKeys[0]; j++)
			keys[startingKeys[j]]++;
		for (int i = 0; i < n; i++)
			if (((chests >> i) & 1) == 0){
			keys[chestOpenBy[i]]--;
			for (int j = 1; j <= keysInChest[i][0]; j++)
				keys[keysInChest[i][j]]++;
		}
		/*
		System.out.println("chests = " + chests);
		for (int i=1; i<=3; i++)
			System.out.print(" " + keys[i]);
		System.out.println("-----------------------");
		*/
		return keys;
	}

	private static void comb(int chests) {
		if (visited[chests])
			return;
		visited[chests] = true;
		if (chests == 0)
			return;
		int[] keysInHand = countKeys(chests);
		for (int i = 0; i < n; i++)
			if (keysInHand[chestOpenBy[i]] > 0 && (((chests >> i) & 1) == 1)) {
				sol[m++] = i;
				comb(chests ^ (1 << i));
				if (visited[0])
					return;
				m--;
			}
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int tt = scanner.nextInt();
		for (int t = 1; t <= tt; t++) {
			int k = scanner.nextInt();
			n = scanner.nextInt();

			startingKeys = new int[401];
			startingKeys[0] = 0;
			for (; k > 0; k--)
				startingKeys[++startingKeys[0]] = scanner.nextInt();

			chestOpenBy = new int[n];
			keysInChest = new int[n][401];

			for (int i = 0; i < n; i++) {
				chestOpenBy[i] = scanner.nextInt();
				keysInChest[i][0] = 0;
				for (k = scanner.nextInt(); k > 0; k--)
					keysInChest[i][++keysInChest[i][0]] = scanner.nextInt();
			}

			visited = new boolean[1048576];
			sol = new int[n];
			m = 0;
			comb((1 << n) - 1);
			if (!visited[0])
				System.out.printf("Case #%d: IMPOSSIBLE\n", t);
			else {
				System.out.printf("Case #%d:", t);
				for (int i = 0; i < n; i++)
					System.out.printf(" %d", sol[i]+1);
				System.out.printf("\n");
			}
		} // for t
	} // main
} // Main class

