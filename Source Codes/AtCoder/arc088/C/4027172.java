import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.ListIterator;
import java.util.Scanner;

public class Main {

	private class AlphabetsPos {
		// generic????????????????????????Queue??????
		private int[][] queues = new int[26][200000];
		private int[] pointers = new int[26];
		private int[] maxCount = new int[26];
		
		public AlphabetsPos() {
			Arrays.fill(pointers, 0);
			Arrays.fill(maxCount, 0);
		}
		
		public void queue(int index, int n) {
			queues[index][pointers[index]] = n;
			pointers[index]++;
			if (maxCount[index] < pointers[index]) {
				maxCount[index] = pointers[index];
			}
		}
		
		public int dequeue(int index) {
			pointers[index]--;
			return queues[index][pointers[index]];
		}
		
		public int getMaxCount(int index) {
			return maxCount[index];
		}
	}
	
	private boolean isPalindrome(int[] count) {
		boolean existOdd = false;
		for (int i=0; i<count.length; i++) {
			if (count[i] % 2 == 1) {
				if (existOdd) {
					// 2????????????????????
					return false;
				} else {
					existOdd = true;
				}
			}
		}
		return true;
	}
	
	public long solve(String line) {
		int[] countAlphabets = new int['z'-'a'+1];
		Arrays.fill(countAlphabets, 0);
		
		for (int i=0; i<line.length(); i++) {
			char c = line.charAt(i);
			countAlphabets[c-'a']++;
		}

		// ?????????
		if (isPalindrome(countAlphabets) == false) {
			return -1;
		}

		long move = 0;
		
		boolean existOdd = (line.length() % 2 == 1);
		
		AlphabetsPos alphaPos = new AlphabetsPos();
		LinkedList<Integer> rights = new LinkedList<Integer>();
		
		int leftPos = 0;
		int jumpNum = 0;
		
		for (int i=0; i<line.length(); i++) {
			char c = line.charAt(i);
			int index = c - 'a';

			if (alphaPos.getMaxCount(index) < countAlphabets[index] / 2) {
				// ??????????
				alphaPos.queue(index, leftPos);
				leftPos++;
				move += jumpNum;
			} else {
				// ??????????
				if (existOdd && countAlphabets[index] % 2 == 1) {
					// ???????????????????
					rights.add(line.length() / 2);
					existOdd = false;
				} else {
					// ??????????????
					rights.add(line.length() - alphaPos.dequeue(index) - 1);
				}
				jumpNum++;
			}
		}
		
		move += sort(rights, line.length() / 2);
		
		return move;
	}
	
	private void debugPrint(List<Integer> list) {
		ListIterator<Integer> it = list.listIterator();
		while (it.hasNext()) {
			System.out.print(Integer.toString(it.next()) + ",");
		}
	}
	
	private long sort(List<Integer> list, int start) {
		if (list.size() <= 1) {
			return 0;
		}
		
		long move = 0;
		int jumpNum = 0;
		int rightStart = start + list.size() / 2;
		
		ListIterator<Integer> it = list.listIterator();
		List<Integer> lefts = new LinkedList<Integer>();
		
		while (it.hasNext()) {
			int pos = it.next();
			if (pos < rightStart) {
				// ?????
				it.remove();
				lefts.add(pos);
				move += jumpNum;
			} else {
				// ?????
				jumpNum++;
			}
		}
		
		long leftMove = sort(lefts, start);
		long rightMove = sort(list, rightStart);

		/*
		System.out.print("lefts = ");
		debugPrint(lefts);
		System.out.print(" : " + Long.toString(leftMove));
		System.out.print(", rights = ");
		debugPrint(list);
		System.out.print(" : " + Long.toString(rightMove));
		System.out.println();
		*/
		
		return move + leftMove + rightMove;
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String line = in.next();
		in.close();
		
		Main main = new Main();
		long result = main.solve(line);
		System.out.println(Long.toString(result));
	}

}