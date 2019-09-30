import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		new Main().execute();
	}

	public void execute() {
		Scanner sc = new Scanner(System.in);
		final int N = sc.nextInt();
		Participant[] participants = new Participant[N];
		for (int i = 0; i < N; i++) {
			int ri = sc.nextInt();
			int hi = sc.nextInt();
			participants[i] = new Participant(ri, hi);
		}
		ParticipantStats stats = new ParticipantStats(participants.clone());

		for (int i = 0; i < N; i++) {
			Participant p = participants[i];
			int win = stats.countUnder(p.rating);
			int draw = stats.countByRateHand(p.rating, p.hand) - 1;
			int lose = stats.countOver(p.rating);
			switch (p.hand) {
			case GU:
				win += stats.countByRateHand(p.rating, Janken.CHOKI);
				lose += stats.countByRateHand(p.rating, Janken.PA);
				break;
			case CHOKI:
				win += stats.countByRateHand(p.rating, Janken.PA);
				lose += stats.countByRateHand(p.rating, Janken.GU);
				break;
			case PA:
				win += stats.countByRateHand(p.rating, Janken.GU);
				lose += stats.countByRateHand(p.rating, Janken.CHOKI);
				break;
			}

			System.out.println(win + " " + lose + " " + draw);
		}
		sc.close();
	}

	enum Janken {
		GU(1), CHOKI(2), PA(3);
		private int intValue;

		private Janken(int x) {
			this.intValue = x;
		}

		public int getIntValue() {
			return intValue;
		}

		public static Janken fromInt(int x) {
			switch (x) {
			case 1:
				return GU;
			case 2:
				return CHOKI;
			case 3:
				return PA;
			default:
				throw new IllegalArgumentException();
			}
		}

	}

	class Participant {
		public final int rating;
		public final Janken hand;

		public Participant(int rating, int hand) {
			this.rating = rating;
			this.hand = Janken.fromInt(hand);
		}
	}

	class ParticipantStats {
		private ArrayList<Integer> rates;
		private ArrayList<List<Integer>> statsByRate;
		private int totalCount;

		public ParticipantStats(Participant[] participants) {
			rates = new ArrayList<>();
			statsByRate = new ArrayList<>();
			Arrays.sort(participants, new Comparator<Participant>() {
				@Override
				public int compare(Participant o1, Participant o2) {
					// TODO Auto-generated method stub
					if (o1.rating == o2.rating) {
						return o1.hand.intValue - o2.hand.intValue;
					} else {
						return o1.rating - o2.rating;
					}
				}
			});
			totalCount = participants.length;
			int currentRate = 0;
			for (int i = 0; i < participants.length;) {
				currentRate = participants[i].rating;
				Integer[] stats = { 0, 0, 0, 0 };
				if (statsByRate.size() == 0) {
					stats[0] = 0;
				} else {
					stats[0] = statsByRate.get(statsByRate.size() - 1).get(0);
				}
				while (i < participants.length && currentRate == participants[i].rating) {
					stats[0]++;
					stats[participants[i].hand.intValue]++;
					i++;
				}
				rates.add(currentRate);
				statsByRate.add(Arrays.asList(stats));
			}
		}

		private int countUnder(int r) {
			int idx = Collections.binarySearch(rates, r);
			if (idx == 0) {
				return 0;
			} else {
				return statsByRate.get(idx - 1).get(0);
			}
		}

		private int countByRateHand(int r, Janken h) {
			int idx = Collections.binarySearch(rates, r);
			return statsByRate.get(idx).get(h.intValue);
		}

		private int countOver(int r) {
			int idx = Collections.binarySearch(rates, r);
			return totalCount - statsByRate.get(idx).get(0);
		}

	}

}