import java.util.*;

class KillerWord {
	public static void main(String[] arg) {
		Scanner sc = new Scanner(System.in);
		int tc = sc.nextInt();
		for(int ctc = 1; ctc <= tc; ++ctc) {
			System.out.printf("Case #%d:", ctc);
			int n = sc.nextInt();
			int m = sc.nextInt();
			Word[] dict = new Word[n];
			for(int i = 0; i < n; ++i) dict[i] = new Word(sc.next());
			for(int i = 0; i < m; ++i) {
				String list = sc.next();
				for(Word w: dict) {
					w.score = 0;
					w.node = null;
					w.setPath(list);
				}
				for(int len = 1; len <= 10; ++len) {
					List<Word> dc = new ArrayList<Word>();
					for(Word w: dict) if(w.len == len) dc.add(w);
					if(dc.size() <= 1) continue;
					Node root = new Node();
					root.wc = dc.size();
					for(Word w: dc) {
						Node cur = root;
						for(int x: w.path) {
							Node next = cur.map.get(x);
							if(next == null) {
								next = new Node();
								next.parent = cur;
								cur.map.put(x, next);
							}
							cur = next;
							++cur.wc;
						}
						cur.word = w;
						w.node = cur;
					}
					for(Word w: dc) {
						for(;;) {
							Node parent = w.node.parent;
							if(parent == null) break;
							if(parent.wc != 1) break;
							w.node = parent;
							parent.word = w;
							parent.map.clear();
						}
					}
					Queue<Node> q = new LinkedList<Node>();
					q.add(root);
					do {
						Node cur = q.poll();
						while(cur.map.size() == 1) {
							Node child = cur.map.get(0);
							if(child == null) break;
							cur.word = child.word;
							cur.map = child.map;
							cur.wc = child.wc;
						}
						for(Node child: cur.map.values()) q.add(child);
					} while(!q.isEmpty());
					q.add(root);
					do {
						Node cur = q.poll();
						for(Node child: cur.map.values()) {
							child.score = cur.score;
							q.add(child);
						}
						Node child = cur.map.get(0);
						if(child != null) ++child.score;
					} while(!q.isEmpty());
					for(Word w: dc) w.score = w.node.score;
				}
				Word best = null;
				int bestScore = -1;
				for(Word w: dict) if(w.score > bestScore) {
					bestScore = w.score;
					best = w;
				}
				System.out.print(" " + best.s);
			}
			System.out.println();
		}
	}
}

class Node {
	Node parent = null;
	Map<Integer,Node> map = new HashMap<Integer,Node>();
	Word word = null;
	int wc = 0;
	int score = 0;
}

class Word {
	Node node = null;
	int score = 0;

	String s;
	int len;
	int[] sig = new int[26];
	int[] path = new int[26];

	void setPath(String list) {
		for(int i = 0; i < 26; ++i) path[i] = sig[list.charAt(i) - 'a'];
	}

	Word(String s) {
		this.s = s;
		len = s.length();
		for(int i = len - 1, pow = 1; i >= 0; --i, pow <<= 1) sig[s.charAt(i) - 'a'] += pow;
	}
}
