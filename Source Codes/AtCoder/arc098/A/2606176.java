import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numberOfPeople = sc.nextInt();
        char[] peopleDirections = sc.next().toCharArray();

        int[] east = new int[numberOfPeople];
        int[] west = new int[numberOfPeople];
        for (int i = 0; i < numberOfPeople; i++) {
            if (peopleDirections[i] == 'E') {
                east[i] = 1;
            } else {
                west[i] = 1;
            }
        }

        for (int i = 1; i < numberOfPeople; i++) {
            east[i] += east[i - 1];
            west[i] += west[i - 1];
        }

        int minimumNumberOfPeopleToChangeDirection = numberOfPeople;
        for (int i = 0; i < numberOfPeople; i++) {

            int countOfEastAtRightSide = east[numberOfPeople - 1] - east[i];
            int countOfWestAtLeftSide = i == 0 ? 0 : west[i - 1];
            int totalCount = countOfEastAtRightSide + countOfWestAtLeftSide;
            
            if (minimumNumberOfPeopleToChangeDirection > totalCount) {
                minimumNumberOfPeopleToChangeDirection = totalCount;
            }

        }

        System.out.println(minimumNumberOfPeopleToChangeDirection);
    }
}