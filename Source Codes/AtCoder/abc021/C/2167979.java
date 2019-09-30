import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int a = sc.nextInt() - 1;
		int b = sc.nextInt() - 1;
		int m = sc.nextInt();
		int[] x = new int[m];
		int[] y = new int[m];
		int[][] gragh = new int[n][n];
		for(int i = 0 ; i < n ; i++) {
			for(int j = 0 ; j < n ; j++) {
				if(i != j) gragh[i][j] = 1000;
			}
		}
		for(int i = 0 ; i < m ; i++) {
			x[i] = sc.nextInt() - 1;
			y[i] = sc.nextInt() - 1;
			gragh[x[i]][y[i]] = gragh[y[i]][x[i]] = 1;
		}
		for(int k = 0 ; k < n ; k++) {
			for(int i = 0 ; i < n ; i++) {
				for(int j = 0 ; j < n ; j++) {
					gragh[i][j] = Math.min(gragh[i][j], gragh[i][k] + gragh[k][j]);
				}
			}
		}
		// ???DAG
		int[][] dag = new int[n][n];
		for(int i = 0 ; i < m ; i++) {
			if(gragh[a][x[i]] + 1 == gragh[a][y[i]]) dag[x[i]][y[i]] = 1;
			if(gragh[a][y[i]] + 1 == gragh[a][x[i]]) dag[y[i]][x[i]] = 1;
		}
		// ???DAG?????
//		for(int i = 0 ; i < n ; i++) {
//			for(int j = 0 ; j < n ; j++) {
//				if(i == j) continue;
//				System.out.println("(" + (i + 1) + ", " + (j + 1) + ")" + " : " + dag[i][j]);
//			}
//		}
		// a??????MAP
		HashMap<Integer, ArrayList<Integer>> map = new HashMap<>();
		for(int i = 0 ; i < n ; i++) {
			int dist = gragh[a][i];
			if(!map.containsKey(dist)) {
				ArrayList<Integer> list = new ArrayList<>();
				list.add(i);
				map.put(dist, list);
			} else {
				ArrayList<Integer> list = map.get(dist);
				list.add(i);
				map.put(dist, list);
			}
		}
		// map?????
//		String printMap = "{";
//		int cnt1 = 0;
//		for(Map.Entry<Integer, ArrayList<Integer>> entry : map.entrySet()) {
//			printMap += "??" + String.valueOf(entry.getKey()) + "=[";
//			int cnt = 0;
//			for(int value : entry.getValue()) {
//				if(cnt == 0) {
//					printMap += String.valueOf(value + 1);
//				} else {
//					printMap += ", " + String.valueOf(value + 1);
//				}
//				cnt++;
//			}
//			if(cnt1 != map.size() - 1) {
//				printMap += "], ";
//			} else {
//				printMap += "]}";
//			}
//			cnt1++;
//		}
//		System.out.println(printMap);

		// ??????
		long[] sum = new long[n];
		sum[a] = 1;
		int d = gragh[a][b];
//		System.out.println(d);
		for(int i = 0 ; i < d ; i++) {
			ArrayList<Integer> list = map.get(i);
			for(int j = 0 ; j < list.size() ; j++) {
//				System.out.print(list.get(j) + " ");
				int v = list.get(j);
				for(int k = 0 ; k < n ; k++) {
					if(dag[v][k] == 1) {
//						System.out.println("before v:" + (v + 1) + ",k:" + (k + 1) + " sum[k]:" + sum[k]);
						sum[k] = (sum[k] + sum[v]) % 1000000007;
//						System.out.println("after v:" + (v + 1) + ",k:" + (k + 1) + " sum[k]:" + sum[k]);
					}
				}
			}
		}
		System.out.println(sum[b]);
	}
}