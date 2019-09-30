import java.util.*;
import java.io.*;

public class Rd1ab {

    public static void main (String[] args) {

		Scanner in = new Scanner(System.in);

		int count = in.nextInt();
		for (int l = 0; l < count; l++) {

			int n = in.nextInt();
			node[] list = new node[n];
			for (int i = 0; i < n; i++) {
				list[i] = new node();
			}
			for (int i = 0; i < n-1; i++) {
				int x = in.nextInt() - 1;
				int y = in.nextInt() - 1;
				list[x].edges.add(y);
				list[y].edges.add(x);
			}
			
			int best_value = n;
			for (int i = 0; i < n; i++) {
				int value = remove(i, -1, list);
				if (value < best_value) {
					best_value = value;	
				}
			}
			System.out.println("Case #" + (l+1) + ": " + best_value);
		}
	}

	public static int remove (int head, int previous, node[] list) {

		int best = 0;
		int second = 0;
		boolean has_neighbor = false;
		boolean has_multiple_neighbor = false;
		for (int i = 0; i < list[head].edges.size(); i++) {
			if (list[head].edges.get(i) != previous) {
				int size_remove = size(list[head].edges.get(i), head, list);
				int size_binary = remove(list[head].edges.get(i), head, list);
				int score = size_remove - size_binary;
				if (score > second)
					second = score;
				if (score > best) {
					second = best;
					best = score;
				}
				if (has_neighbor)
					has_multiple_neighbor = true;
				has_neighbor = true;
			}
		}
		if (!has_neighbor)
			return 0;
		if (has_multiple_neighbor)
			return size(head, previous, list) - best - second - 1;
		else
			return size(head, previous, list) - 1;
	
	}

	public static int size (int head, int previous, node[] list) {
		int size = 1;
		for (int i = 0; i < list[head].edges.size(); i++) {
			if (list[head].edges.get(i) != previous)
				size += size(list[head].edges.get(i), head, list);
		}
		return size;
	}

}


