import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int size = sc.nextInt();
		List<TownInfo> townList = new ArrayList<>();
		double total = 0;

		for (int i = 0; i < size; i++) {
			String townName = sc.next();
			double population = sc.nextDouble();
			total += population;
			TownInfo info = new TownInfo(townName, population);
			townList.add(info);

		}
		sc.close();

		String newTownName = "atcoder";

		for (TownInfo townInfo : townList) {

			double popu = townInfo.getPopulation();

			double percent = (popu * 100 / total);

			if (percent > 50) {
				newTownName = townInfo.getTownName();
			}
		}

		System.out.println(newTownName);

	}
}

class TownInfo {

	/**
	 * ????
	 */
	private String townName;

	/**
	 * ??
	 */
	private double population;

	/**
	 * ???????
	 *
	 * @param townName ????
	 * @param population ??
	 */
	public TownInfo(String townName, double population) {
		this.townName = townName;
		this.population = population;
	}

	/**
	 * townName?????
	 *
	 * @return townName ????
	 */
	public String getTownName() {
		return townName;
	}

	/**
	 * population?????
	 *
	 * @return population ??
	 */
	public double getPopulation() {
		return population;
	}

}