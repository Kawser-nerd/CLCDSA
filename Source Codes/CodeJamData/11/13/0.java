import java.io.*;
import java.util.*;

public class Bai3 {
	
	static class Card implements Comparable<Card> {
		int c, s, t;
		Card(int c, int s, int t) {
			this.c = c;
			this.s = s;
			this.t = t;
		}
		
		public int compareTo(Card c) {
			if(this.s != c.s) return this.s - c.s;
			else return 0;
		}
	}
	
	class State implements Comparable<State> {
		ArrayList<Card>[] list;
		
		State() {
			list = new ArrayList[3];
			for(int i=0;i<3;++i) list[i] = new ArrayList<Card>();
		}
		
		State(State s, int id) {
			list = new ArrayList[3];
			for(int i=0;i<3;++i) list[i] = new ArrayList<Card>();
			for(int i=0;i<3;++i) {
				int ct = s.list[i].size();
				if(i == id) ct--;
				for(int j=0;j<ct;++j) list[i].add(s.list[i].get(j));
			}
		}
		
		public int compareTo(State s) {
			for(int i=0;i<3;++i) {
				if(list[i].size() != s.list[i].size())
					return list[i].size() - s.list[i].size();
				for(int j=0;j<list[i].size();++j) {
					int t = list[i].get(j).compareTo(s.list[i].get(j));
					if(t != 0) return t;
				}
			}
			return 0;
		}
	}
	
	Card[] hand, desk;
	TreeMap<State,Integer>[][] cache;
	
	int solve(State s, ArrayList<Card> post, int nturns, int dpos) {
		if(nturns == 0) return 0;
		int add = 0;
		for(int i=0;i<post.size();++i) {
			Card c = post.get(i);
			add += c.s;
			nturns += c.t - 1;
			for(int j=0;j<c.c;++j) if(dpos < desk.length) {
				if(desk[dpos].t > 0) post.add(desk[dpos]);
				else {
					s.list[desk[dpos].c].add(desk[dpos]);
				}
				dpos++;
			}
		}
		if(nturns > hand.length + desk.length) nturns = hand.length + desk.length;
		for(int i=0;i<3;++i) Collections.sort(s.list[i]);
		if(cache[nturns][dpos].containsKey(s))
			return cache[nturns][dpos].get(s) + add;
		int res = 0;
		for(int i=0;i<3;++i) if(s.list[i].size() > 0) {
			Card c = s.list[i].get(s.list[i].size()-1);
			State ns = new State(s, i);
			ArrayList<Card> npt = new ArrayList<Card>();
			for(int j=0;j<i;++j) if(dpos + j < desk.length) {
				if(desk[dpos + j].t > 0) npt.add(desk[dpos + j]);
				else {
					ns.list[desk[dpos + j].c].add(desk[dpos + j]);
				}
			}
			res = Math.max( res, c.s + solve( ns, npt, nturns - 1, Math.min( dpos + i, desk.length)));
		}
		cache[nturns][dpos].put(s, res);
		return res + add;
	}
	
	int getMaxScore(Card[] hand, Card[] desk) {
		this.hand = hand;
		this.desk = desk;
		State start = new State();
		ArrayList<Card> post = new ArrayList<Card>();
		for(int i=0;i<hand.length;++i) {
			if(hand[i].t > 0) post.add(hand[i]);
			else {
				start.list[hand[i].c].add(hand[i]);
			}
		}
		cache = new TreeMap[hand.length + desk.length + 1][desk.length + 1];
		for(int i=0;i<cache.length;++i)
			for(int j=0;j<cache[i].length;++j)
				cache[i][j] = new TreeMap<State, Integer>();
		int res = solve( start, post, 1, 0);
		return res;
	}
	
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		// PrintWriter pw = new PrintWriter(System.out);
		// Scanner sc = new Scanner(new FileReader("C-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("Csmall.out"));
		
		int ntest = sc.nextInt();
		
		for(int test=1;test<=ntest;++test) {
			
			int n = sc.nextInt();
			Card[] hand = new Card[n];
			for(int i=0;i<n;++i)
				hand[i] = new Card(sc.nextInt(), sc.nextInt(), sc.nextInt());
			int m = sc.nextInt();
			Card[] desk = new Card[m];
			for(int i=0;i<m;++i)
				desk[i] = new Card(sc.nextInt(), sc.nextInt(), sc.nextInt());
			
			int res = new Bai3().getMaxScore(hand, desk);
			
			pw.print("Case #" + test + ": ");
			pw.print(res);
			pw.println();
		}
		pw.close();
		sc.close();
	}
}
